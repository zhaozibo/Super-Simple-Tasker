/*===========================================================================
* Super-Simple Tasker 0 (SST0) cooperative version for ARM Cortex-M
*
* Copyright (C) 2005-2023 Quantum Leaps, <state-machine.com>.
*
* SPDX-License-Identifier: MIT
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
===========================================================================*/
#ifndef SST_PORT_H_
#define SST_PORT_H_

#define SST_PORT_TASK_ATTR SST_TaskPrio prio;

#define SST_PORT_MAX_TASK 32U
typedef uint32_t SST_ReadySet;

/* SST-PORT disabling/enabling interrupts */
#define SST_PORT_INT_DISABLE() __asm volatile ("cpsid i")
#define SST_PORT_INT_ENABLE()  __asm volatile ("cpsie i")

/* SST-PORT critical section */
#define SST_PORT_CRIT_STAT
#define SST_PORT_CRIT_ENTRY() SST_PORT_INT_DISABLE()
#define SST_PORT_CRIT_EXIT()  SST_PORT_INT_ENABLE()

#if (__ARM_ARCH > 6) /* ARMv7-M or higher? */
#define SST_LOG2(x_) ((uint_fast8_t)(32U - __builtin_clz((unsigned)(x_))))
#endif

#endif /* SST_PORT_H_ */
