/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef SDK_ANDROID_SRC_JNI_VIDEODECODERFACTORYWRAPPER_H_
#define SDK_ANDROID_SRC_JNI_VIDEODECODERFACTORYWRAPPER_H_

#include <jni.h>

#include "media/engine/webrtcvideodecoderfactory.h"
#include "sdk/android/src/jni/jni_helpers.h"

namespace webrtc {
namespace jni {

// Wrapper for Java VideoDecoderFactory class. Delegates method calls through
// JNI and wraps the decoder inside VideoDecoderWrapper.
class VideoDecoderFactoryWrapper : public cricket::WebRtcVideoDecoderFactory {
 public:
  VideoDecoderFactoryWrapper(JNIEnv* jni, jobject decoder_factory);

  // Caller takes the ownership of the returned object and it should be released
  // by calling DestroyVideoDecoder().
  VideoDecoder* CreateVideoDecoderWithParams(
      const cricket::VideoCodec& codec,
      cricket::VideoDecoderParams params) override;
  void DestroyVideoDecoder(VideoDecoder* decoder) override;

 private:
  const ScopedGlobalRef<jobject> decoder_factory_;
  jmethodID create_decoder_method_;
};

}  // namespace jni
}  // namespace webrtc

#endif  // SDK_ANDROID_SRC_JNI_VIDEODECODERFACTORYWRAPPER_H_
