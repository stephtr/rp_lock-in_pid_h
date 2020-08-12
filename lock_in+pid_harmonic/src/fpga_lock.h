/**
 * @brief Red Pitaya LOCK FPGA controller.
 *
 * @Author Marcelo Luda <marceluda@gmail.com>
 *
 *
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */

#ifndef _FPGA_LOCK_H_
#define _FPGA_LOCK_H_

#include <stdint.h>

/** @defgroup fpga_lock_h LOCK Controller
 * @{
 */

/** Base LOCK FPGA address */
#define LOCK_BASE_ADDR 0x40600000
/** Base LOCK FPGA core size */
#define LOCK_BASE_SIZE 0x190

/** @brief LOCK FPGA registry structure.
 *
 * This structure is direct image of physical FPGA memory. When accessing it all
 * reads/writes are performed directly from/to FPGA LOCK registers.
 */
// [FPGAREG DOCK]
typedef struct lock_reg_t {

    /** @brief Offset 20'h00000 - oscA_sw
      *  switch for muxer oscA
      *
      *  bits [31: 5] - Reserved
      *  bits [ 4: 0] - Data
      */
    uint32_t oscA_sw;
    
    /** @brief Offset 20'h00004 - oscB_sw
      *  switch for muxer oscB
      *
      *  bits [31: 5] - Reserved
      *  bits [ 4: 0] - Data
      */
    uint32_t oscB_sw;
    
    /** @brief Offset 20'h00008 - osc_ctrl
      *  oscilloscope control
      *  [osc2_filt_off,osc1_filt_off]
      *
      *  bits [31: 2] - Reserved
      *  bits [ 1: 0] - Data
      */
    uint32_t osc_ctrl;
    
    /** @brief Offset 20'h0000C - trig_sw
      *  Select the external trigger signal
      *
      *  bits [31: 8] - Reserved
      *  bits [ 7: 0] - Data
      */
    uint32_t trig_sw;
    
    /** @brief Offset 20'h00010 - out1_sw
      *  switch for muxer out1
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t out1_sw;
    
    /** @brief Offset 20'h00014 - out2_sw
      *  switch for muxer out2
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t out2_sw;
    
    /** @brief Offset 20'h00018 - lock_control
      *  lock_control help
      *
      *  bits [31:11] - Reserved
      *  bits [10: 0] - Data
      */
    uint32_t lock_control;
    
    /** @brief Offset 20'h0001C - lock_feedback
      *  lock_control feedback
      *
      *  bits [31:11] - Reserved
      *  bits [10: 0] - Data
      */
    uint32_t lock_feedback;
    
    /** @brief Offset 20'h00020 - lock_trig_val
      *  if lock_control ?? , this vals sets the voltage threshold that turns on the lock
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  lock_trig_val;
    
    /** @brief Offset 20'h00024 - lock_trig_time
      *  if lock_control ?? , this vals sets the time threshold that turns on the lock
      *
      *  bits [31: 0] - Data
      */
    uint32_t lock_trig_time;
    
    /** @brief Offset 20'h00028 - lock_trig_sw
      *  selects signal for trigger
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t lock_trig_sw;
    
    /** @brief Offset 20'h0002C - rl_error_threshold
      *  Threshold for error signal. Launchs relock when |error| > rl_error_threshold
      *
      *  bits [31:13] - Reserved
      *  bits [12: 0] - Data
      */
    uint32_t rl_error_threshold;
    
    /** @brief Offset 20'h00030 - rl_signal_sw
      *  selects signal for relock trigger
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t rl_signal_sw;
    
    /** @brief Offset 20'h00034 - rl_signal_threshold
      *  Threshold for signal. Launchs relock when signal < rl_signal_threshold
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  rl_signal_threshold;
    
    /** @brief Offset 20'h00038 - rl_config
      *  Relock enable. [relock_reset,enable_signal_th,enable_error_th] 
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t rl_config;
    
    /** @brief Offset 20'h0003C - rl_state
      *  Relock state: [state:idle|searching|failed,signal_fail,error_fail,locked] 
      *
      *  bits [31: 5] - Reserved
      *  bits [ 4: 0] - Data
      */
    uint32_t rl_state;
    
    /** @brief Offset 20'h00040 - sf_jumpA
      *  Step function measure jump value for ctrl_A
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  sf_jumpA;
    
    /** @brief Offset 20'h00044 - sf_jumpB
      *  Step function measure jump value for ctrl_B
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  sf_jumpB;
    
    /** @brief Offset 20'h00048 - sf_config
      *  Step function configuration. [pidB_ifreeze,pidB_freeze,pidA_ifreeze,pidA_freeze,start] 
      *
      *  bits [31: 5] - Reserved
      *  bits [ 4: 0] - Data
      */
    uint32_t sf_config;
    
    /** @brief Offset 20'h0004C - signal_sw
      *  Input selector for signal_i
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t signal_sw;
    
    /** @brief Offset 20'h00050 - signal_i
      *  signal for demodulation
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  signal_i;
    
    /** @brief Offset 20'h00054 - sg_amp1
      *  amplification of Xo, Yo and F1o
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t sg_amp1;
    
    /** @brief Offset 20'h00058 - sg_amp2
      *  amplification of F2o
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t sg_amp2;
    
    /** @brief Offset 20'h0005C - sg_amp3
      *  amplification of F3o
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t sg_amp3;
    
    /** @brief Offset 20'h00060 - lpf_F1
      *  Low Pass Filter of X, Y and F1
      *
      *  bits [31: 6] - Reserved
      *  bits [ 5: 0] - Data
      */
    uint32_t lpf_F1;
    
    /** @brief Offset 20'h00064 - lpf_F2
      *  Low Pass Filter of F2
      *
      *  bits [31: 6] - Reserved
      *  bits [ 5: 0] - Data
      */
    uint32_t lpf_F2;
    
    /** @brief Offset 20'h00068 - lpf_F3
      *  Low Pass Filter of F3
      *
      *  bits [31: 6] - Reserved
      *  bits [ 5: 0] - Data
      */
    uint32_t lpf_F3;
    
    /** @brief Offset 20'h0006C - error_sw
      *  select error signal
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t error_sw;
    
    /** @brief Offset 20'h00070 - error_offset
      *  offset for the error signal
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  error_offset;
    
    /** @brief Offset 20'h00074 - error
      *  error signal value
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  error;
    
    /** @brief Offset 20'h00078 - error_mean
      *  1 sec error mean val
      *
      *  bits [31: 0] - Data
      */
    int32_t  error_mean;
    
    /** @brief Offset 20'h0007C - error_std
      *  1 sec error square sum val
      *
      *  bits [31: 0] - Data
      */
    int32_t  error_std;
    
    /** @brief Offset 20'h00080 - gen_mod_phase
      *  phase relation of cos_?f signals
      *
      *  bits [31:12] - Reserved
      *  bits [11: 0] - Data
      */
    uint32_t gen_mod_phase;
    
    /** @brief Offset 20'h00084 - gen_mod_hp
      *  harmonic period set
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    uint32_t gen_mod_hp;
    
    /** @brief Offset 20'h00088 - ramp_A
      *  ramp signal A
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ramp_A;
    
    /** @brief Offset 20'h0008C - ramp_B
      *  ramp signal B
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ramp_B;
    
    /** @brief Offset 20'h00090 - ramp_step
      *  period of the triangular ramp signal
      *
      *  bits [31: 0] - Data
      */
    uint32_t ramp_step;
    
    /** @brief Offset 20'h00094 - ramp_low_lim
      *  ramp low limit
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ramp_low_lim;
    
    /** @brief Offset 20'h00098 - ramp_hig_lim
      *  ramp high limit
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ramp_hig_lim;
    
    /** @brief Offset 20'h0009C - ramp_reset
      *  ramp reset config
      *
      *  bits [31: 1] - Reserved
      *  bit  [0]     - Data
      */
    uint32_t ramp_reset;
    
    /** @brief Offset 20'h000A0 - ramp_enable
      *  ramp enable/disable switch
      *
      *  bits [31: 1] - Reserved
      *  bit  [0]     - Data
      */
    uint32_t ramp_enable;
    
    /** @brief Offset 20'h000A4 - ramp_direction
      *  ramp starting direction (up/down)
      *
      *  bits [31: 1] - Reserved
      *  bit  [0]     - Data
      */
    uint32_t ramp_direction;
    
    /** @brief Offset 20'h000A8 - ramp_B_factor
      *  proportional factor ramp_A/ramp_B.
      *  ramp_B=ramp_A*ramp_B_factor/4096
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ramp_B_factor;
    
    /** @brief Offset 20'h000AC - sin_ref
      *  lock-in modulation sinus harmonic reference
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  sin_ref;
    
    /** @brief Offset 20'h000B0 - cos_ref
      *  lock-in modulation cosinus harmonic reference
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  cos_ref;
    
    /** @brief Offset 20'h000B4 - cos_1f
      *  lock-in modulation sinus harmonic signal with phase relation to reference
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  cos_1f;
    
    /** @brief Offset 20'h000B8 - cos_2f
      *  lock-in modulation sinus harmonic signal with phase relation to reference and double frequency
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  cos_2f;
    
    /** @brief Offset 20'h000BC - cos_3f
      *  lock-in modulation sinus harmonic signal with phase relation to reference and triple frequency
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  cos_3f;
    
    /** @brief Offset 20'h000C0 - in1
      *  Input signal IN1
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  in1;
    
    /** @brief Offset 20'h000C4 - in2
      *  Input signal IN2
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  in2;
    
    /** @brief Offset 20'h000C8 - out1
      *  signal for RP RF DAC Out1
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  out1;
    
    /** @brief Offset 20'h000CC - out2
      *  signal for RP RF DAC Out2
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  out2;
    
    /** @brief Offset 20'h000D0 - oscA
      *  signal for Oscilloscope Channel A
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  oscA;
    
    /** @brief Offset 20'h000D4 - oscB
      *  signal for Oscilloscope Channel B
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  oscB;
    
    /** @brief Offset 20'h000D8 - X_28
      *  Demodulated signal from sin_ref
      *
      *  bits [31:28] - Reserved
      *  bits [27: 0] - Data
      */
    int32_t  X_28;
    
    /** @brief Offset 20'h000DC - Y_28
      *  Demodulated signal from cos_ref
      *
      *  bits [31:28] - Reserved
      *  bits [27: 0] - Data
      */
    int32_t  Y_28;
    
    /** @brief Offset 20'h000E0 - F1_28
      *  Demodulated signal from cos_1f
      *
      *  bits [31:28] - Reserved
      *  bits [27: 0] - Data
      */
    int32_t  F1_28;
    
    /** @brief Offset 20'h000E4 - F2_28
      *  Demodulated signal from cos_2f
      *
      *  bits [31:28] - Reserved
      *  bits [27: 0] - Data
      */
    int32_t  F2_28;
    
    /** @brief Offset 20'h000E8 - F3_28
      *  Demodulated signal from cos_3f
      *
      *  bits [31:28] - Reserved
      *  bits [27: 0] - Data
      */
    int32_t  F3_28;
    
    /** @brief Offset 20'h000EC - cnt_clk
      *  Clock count
      *
      *  bits [31: 0] - Data
      */
    uint32_t cnt_clk;
    
    /** @brief Offset 20'h000F0 - cnt_clk2
      *  Clock count
      *
      *  bits [31: 0] - Data
      */
    uint32_t cnt_clk2;
    
    /** @brief Offset 20'h000F4 - read_ctrl
      *  [unused,start_clk,Freeze]
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t read_ctrl;
    
    /** @brief Offset 20'h000F8 - pidA_sw
      *  switch selector for pidA input
      *
      *  bits [31: 5] - Reserved
      *  bits [ 4: 0] - Data
      */
    uint32_t pidA_sw;
    
    /** @brief Offset 20'h000FC - pidA_PSR
      *  pidA PSR
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t pidA_PSR;
    
    /** @brief Offset 20'h00100 - pidA_ISR
      *  pidA ISR
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t pidA_ISR;
    
    /** @brief Offset 20'h00104 - pidA_DSR
      *  pidA DSR
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t pidA_DSR;
    
    /** @brief Offset 20'h00108 - pidA_SAT
      *  pidA saturation control
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    uint32_t pidA_SAT;
    
    /** @brief Offset 20'h0010C - pidA_sp
      *  pidA set_point
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidA_sp;
    
    /** @brief Offset 20'h00110 - pidA_kp
      *  pidA proportional constant
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidA_kp;
    
    /** @brief Offset 20'h00114 - pidA_ki
      *  pidA integral constant
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidA_ki;
    
    /** @brief Offset 20'h00118 - pidA_kd
      *  pidA derivative constant
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidA_kd;
    
    /** @brief Offset 20'h0011C - pidA_in
      *  pidA input
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidA_in;
    
    /** @brief Offset 20'h00120 - pidA_out
      *  pidA output
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidA_out;
    
    /** @brief Offset 20'h00124 - pidA_ctrl
      *  pidA control: [ pidA_ifreeze: integrator freeze , pidA_freeze: output freeze , pidA_irst:integrator reset]
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t pidA_ctrl;
    
    /** @brief Offset 20'h00128 - ctrl_A
      *  control_A: pidA_out + ramp_A
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ctrl_A;
    
    /** @brief Offset 20'h0012C - pidB_sw
      *  switch selector for pidB input
      *
      *  bits [31: 5] - Reserved
      *  bits [ 4: 0] - Data
      */
    uint32_t pidB_sw;
    
    /** @brief Offset 20'h00130 - pidB_PSR
      *  pidB PSR
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t pidB_PSR;
    
    /** @brief Offset 20'h00134 - pidB_ISR
      *  pidB ISR
      *
      *  bits [31: 4] - Reserved
      *  bits [ 3: 0] - Data
      */
    uint32_t pidB_ISR;
    
    /** @brief Offset 20'h00138 - pidB_DSR
      *  pidB DSR
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t pidB_DSR;
    
    /** @brief Offset 20'h0013C - pidB_SAT
      *  pidB saturation control
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    uint32_t pidB_SAT;
    
    /** @brief Offset 20'h00140 - pidB_sp
      *  pidB set_point
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidB_sp;
    
    /** @brief Offset 20'h00144 - pidB_kp
      *  pidB proportional constant
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidB_kp;
    
    /** @brief Offset 20'h00148 - pidB_ki
      *  pidB integral constant
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidB_ki;
    
    /** @brief Offset 20'h0014C - pidB_kd
      *  pidB derivative constant
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidB_kd;
    
    /** @brief Offset 20'h00150 - pidB_in
      *  pidB input
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidB_in;
    
    /** @brief Offset 20'h00154 - pidB_out
      *  pidB output
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  pidB_out;
    
    /** @brief Offset 20'h00158 - pidB_ctrl
      *  pidB control: [ pidB_ifreeze: integrator freeze , pidB_freeze: output freeze , pidB_irst:integrator reset]
      *
      *  bits [31: 3] - Reserved
      *  bits [ 2: 0] - Data
      */
    uint32_t pidB_ctrl;
    
    /** @brief Offset 20'h0015C - ctrl_B
      *  control_B: pidA_out + ramp_B
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  ctrl_B;
    
    /** @brief Offset 20'h00160 - aux_A
      *  auxiliar value of 14 bits
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  aux_A;
    
    /** @brief Offset 20'h00164 - aux_B
      *  auxiliar value of 14 bits
      *
      *  bits [31:14] - Reserved
      *  bits [13: 0] - Data
      */
    int32_t  aux_B;
    

} lock_reg_t;
// [FPGAREG DOCK END]


/** @} */

/* Description of the following variables or function declarations is in
 * fpga_lock.c
 */
  extern lock_reg_t    *g_lock_reg;

int fpga_lock_init(void);
int fpga_lock_exit(void);

#endif // _FPGA_LOCK_H_
