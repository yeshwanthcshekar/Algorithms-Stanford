/*

In this programming problem you'll code up Prim's minimum spanning tree algorithm.

This file describes an undirected graph with integer edge costs. It has the format

[number_of_nodes] [number_of_edges]

[one_node_of_edge_1] [other_node_of_edge_1] [edge_1_cost]

[one_node_of_edge_2] [other_node_of_edge_2] [edge_2_cost]

...

For example, the third line of the file is "2 3 -8874",
indicating that there is an edge connecting vertex #2 and vertex #3 that has cost -8874.

You should NOT assume that edge costs are positive, nor should you assume that they are distinct.

Your task is to run Prim's minimum spanning tree algorithm on this graph. You should report the overall cost
 of a minimum spanning tree --- an integer, which may or may not be negative --- in the box below.

IMPLEMENTATION NOTES: This graph is small enough that the straightforward O(mn) time implementation
 of Prim's algorithm should work fine. OPTIONAL: For those of you seeking an additional challenge,
 try implementing a heap-based version. The simpler approach, which should already give you a healthy speed-up,
 is to maintain relevant edges in a heap (with keys = edge costs). The superior approach stores
 the unprocessed vertices in the heap, as described in lecture. Note this requires a heap that supports deletions,
 and you'll probably need to maintain some kind of mapping between vertices and their positions in the heap.

*/


#pragma once


#include <string>


namespace Lecture
{
    const std::string Input
    {
R"(1 2 1
1 3 4
1 4 3
2 4 2
3 4 5
)"
    }; // const std::string Input

} // namespace Lecture


namespace Assignment
{
    const std::string Input
    {
R"(1 2 6807
2 3 -8874
3 4 -1055
4 5 4414
5 6 1728
6 7 -2237
7 8 -7507
8 9 7990
9 10 -5012
10 11 7353
11 12 -6736
12 13 -7604
13 14 5273
14 15 9331
15 16 -7753
16 17 -4370
17 18 267
18 19 903
19 20 7674
20 21 5436
21 22 9479
22 23 9432
23 24 4472
24 25 7258
25 26 8709
26 27 4358
27 28 -6775
28 29 68
29 30 -2849
30 31 -9951
31 32 -8643
32 33 -4010
33 34 -4667
34 35 -5829
35 36 -5222
36 37 -7609
37 38 3054
38 39 7935
39 40 173
40 41 9596
41 42 -4557
42 43 -4823
43 44 -6198
44 45 8450
45 46 5533
46 47 -6059
47 48 7411
48 49 9102
49 50 914
50 51 9501
51 52 2704
52 53 -140
53 54 1179
54 55 -1572
55 56 7095
56 57 3613
57 58 5888
58 59 -4184
59 60 1910
60 61 4401
61 62 591
62 63 -9504
63 64 3116
64 65 -6230
65 66 1867
66 67 3816
67 68 2402
68 69 7667
69 70 -3532
70 71 -2985
71 72 -3462
72 73 7737
73 74 8886
74 75 -102
75 76 -3013
76 77 9948
77 78 8032
78 79 -841
79 80 7663
80 81 8974
81 82 5234
82 83 -3366
83 84 3926
84 85 2583
85 86 3295
86 87 -3398
87 88 1058
88 89 2518
89 90 2141
90 91 8894
91 92 7151
92 93 -1766
93 94 -8183
94 95 1773
95 96 -6715
96 97 -9266
97 98 2472
98 99 9986
99 100 -4478
100 101 -1456
101 102 3812
102 103 4658
103 104 3034
104 105 6682
105 106 4633
106 107 7981
107 108 -2976
108 109 8849
109 110 -5089
110 111 -5617
111 112 9034
112 113 -4112
113 114 -9800
114 115 -1462
115 116 -3454
116 117 5890
117 118 -9012
118 119 7557
119 120 1231
120 121 6409
121 122 491
122 123 -5925
123 124 -8728
124 125 -6474
125 126 3510
126 127 -244
127 128 8413
128 129 8772
129 130 1584
130 131 6869
131 132 -7293
132 133 5355
133 134 -4059
134 135 -3303
135 136 -657
136 137 2192
137 138 2039
138 139 -1128
139 140 626
140 141 -887
141 142 -4769
142 143 -7750
143 144 5026
144 145 7151
145 146 -3960
146 147 5902
147 148 -9587
148 149 27
149 150 265
150 151 -5445
151 152 -1850
152 153 2907
153 154 5564
154 155 3872
155 156 -823
156 157 7660
157 158 8685
158 159 -3164
159 160 -7839
160 161 9902
161 162 -487
162 163 8353
163 164 -5987
164 165 4948
165 166 2192
166 167 2283
167 168 428
168 169 2596
169 170 636
170 171 6480
171 172 1141
172 173 -9697
173 174 1467
174 175 -8677
175 176 -9786
176 177 -9636
177 178 -620
178 179 653
179 180 -5463
180 181 6062
181 182 9858
182 183 8655
183 184 -1583
184 185 5507
185 186 -719
186 187 9275
187 188 -9471
188 189 7296
189 190 3768
190 191 -9
191 192 7546
192 193 7645
193 194 1272
194 195 2135
195 196 -9529
196 197 3904
197 198 -6105
198 199 -1925
199 200 -2491
200 201 5606
201 202 -8731
202 203 -8100
203 204 2830
204 205 -2078
205 206 6293
206 207 752
207 208 5289
208 209 -5201
209 210 1564
210 211 4944
211 212 -2368
212 213 6432
213 214 -1421
214 215 -7142
215 216 6331
216 217 3374
217 218 -2164
218 219 7518
219 220 -6876
220 221 8576
221 222 -7797
222 223 -4499
223 224 -1751
224 225 5777
225 226 -3832
226 227 -5058
227 228 8187
228 229 6101
229 230 9131
230 231 7884
231 232 5904
232 233 -5000
233 234 -8309
234 235 -5961
235 236 -4598
236 237 3563
237 238 -1734
238 239 -9874
239 240 6294
240 241 -2489
241 242 -8966
242 243 6243
243 244 -3343
244 245 -9103
245 246 1757
246 247 792
247 248 9403
248 249 -3384
249 250 5555
250 251 6155
251 252 7781
252 253 -2456
253 254 7775
254 255 -8096
255 256 4382
256 257 -1
257 258 1925
258 259 -7340
259 260 4493
260 261 -1791
261 262 9304
262 263 -2202
263 264 1858
264 265 -8596
265 266 -4101
266 267 -2373
267 268 -8907
268 269 -4668
269 270 -1966
270 271 -202
271 272 -4915
272 273 5789
273 274 -7658
274 275 -4649
275 276 -2753
276 277 101
277 278 -6763
278 279 3542
279 280 -9809
280 281 4856
281 282 -8850
282 283 -9803
283 284 7959
284 285 7229
285 286 6301
286 287 -9632
287 288 -9903
288 289 -5683
289 290 4849
290 291 -1292
291 292 -730
292 293 -1806
293 294 2480
294 295 7872
295 296 -4634
296 297 3695
297 298 7216
298 299 7174
299 300 -424
300 301 -157
301 302 5299
302 303 -3618
303 304 2745
304 305 2356
305 306 9341
306 307 6215
307 308 997
308 309 6059
309 310 -2124
310 311 -8711
311 312 -3721
312 313 -5356
313 314 6085
314 315 3445
315 316 7783
316 317 -7213
317 318 1999
318 319 -5649
319 320 5770
320 321 -1747
321 322 -2500
322 323 5951
323 324 -6212
324 325 -3338
325 326 -810
326 327 2013
327 328 3270
328 329 3052
329 330 -9595
330 331 2329
331 332 2798
332 333 5123
333 334 6680
334 335 -675
335 336 -1738
336 337 9560
337 338 -2733
338 339 -9443
339 340 5217
340 341 -3316
341 342 3352
342 343 5124
343 344 4775
344 345 6317
345 346 9720
346 347 9802
347 348 536
348 349 -6018
349 350 510
350 351 -4579
351 352 -4412
352 353 9106
353 354 -3551
354 355 6334
355 356 2435
356 357 2271
357 358 3410
358 359 -4330
359 360 5567
360 361 -5118
361 362 -2471
362 363 -5503
363 364 1476
364 365 7608
365 366 -9219
366 367 -5581
367 368 9122
368 369 -8888
369 370 -1096
370 371 2687
371 372 -43
372 373 170
373 374 -5983
374 375 -7986
375 376 -1601
376 377 -2445
377 378 -592
378 379 -2951
379 380 7291
380 381 -5578
381 382 4514
382 383 -5091
383 384 6887
384 385 -3021
385 386 -4429
386 387 4775
387 388 5259
388 389 1623
389 390 6391
390 391 -2466
391 392 8465
392 393 -8912
393 394 145
394 395 7996
395 396 8163
396 397 -1734
397 398 1603
398 399 -8532
399 400 9988
400 401 9402
401 402 2130
402 403 -2763
403 404 5488
404 405 6613
405 406 -1525
406 407 -4215
407 408 3378
408 409 39
409 410 8375
410 411 -579
411 412 2647
412 413 1827
413 414 7295
414 415 -2987
415 416 4052
416 417 -5636
417 418 9647
418 419 -1587
419 420 3067
420 421 8234
421 422 -7189
422 423 -4343
423 424 8612
424 425 941
425 426 -8875
426 427 5422
427 428 -4103
428 429 -760
429 430 5251
430 431 -7532
431 432 6416
432 433 7244
433 434 -8966
434 435 -880
435 436 -7818
436 437 9097
437 438 -2279
438 439 7262
439 440 -7217
440 441 -3548
441 442 -9851
442 443 -7558
443 444 -8151
444 445 -3461
445 446 -9813
446 447 -1603
447 448 -9184
448 449 8981
449 450 3537
450 451 8574
451 452 452
452 453 -4855
453 454 -6950
454 455 8161
455 456 2231
456 457 9580
457 458 -3644
458 459 -9068
459 460 -5603
460 461 -1208
461 462 -9989
462 463 9734
463 464 8650
464 465 1534
465 466 8194
466 467 4613
467 468 1867
468 469 -3667
469 470 -8102
470 471 -875
471 472 -5564
472 473 -9211
473 474 4696
474 475 -7052
475 476 -37
476 477 -399
477 478 2587
478 479 7567
479 480 1924
480 481 129
481 482 5965
482 483 -9453
483 484 8124
484 485 -1698
485 486 -813
486 487 1576
487 488 4881
488 489 7498
489 490 -9312
490 491 7282
491 492 2219
492 493 -4854
493 494 -421
494 495 2927
495 496 327
496 497 4963
497 498 -5404
498 499 -6861
499 500 8293
1 132 -151
1 171 8358
1 244 6723
1 310 9791
1 316 569
1 324 -1612
1 397 -5942
1 414 3655
2 25 6267
2 39 907
2 104 -8744
2 157 1036
2 173 -7751
2 309 -7230
3 91 -8754
3 110 504
3 136 -4218
3 144 -9056
3 231 -494
3 303 5310
3 353 9242
3 482 -1048
4 43 566
4 77 -3033
4 82 -6069
4 93 -2804
4 247 2557
4 266 1686
4 284 8282
4 364 -8897
4 388 5176
4 423 6365
5 122 722
5 153 8816
6 15 -1593
6 73 7693
6 297 -3253
6 343 154
7 103 8257
7 314 -1756
7 416 -5246
7 451 7495
8 124 -5969
8 162 7179
8 194 -507
8 294 -4333
8 318 -4261
8 359 2771
8 432 2206
9 17 -3864
9 250 -1984
9 307 -4003
9 495 5260
10 114 223
10 168 4271
10 330 7863
10 390 -8598
11 43 4323
11 69 171
11 176 -9470
11 469 6195
12 20 -686
12 277 6273
13 24 -9600
13 61 5960
13 152 4272
13 164 -1175
13 486 7432
14 64 -1515
14 209 9744
14 219 -9493
14 276 7321
14 359 9452
14 396 909
14 492 5070
15 87 -1165
15 211 -290
15 220 -8415
15 242 -1132
15 287 3395
15 302 9956
15 365 -9352
15 496 783
16 49 2410
16 93 4136
16 110 221
16 248 6820
16 275 -7206
16 369 -1699
17 35 -2706
17 69 -1754
17 92 4535
17 185 5372
17 212 7481
17 248 5899
17 272 5930
17 317 2595
17 376 5972
17 427 7949
17 432 -2484
18 241 3362
18 279 2815
18 433 -9810
18 451 6558
19 240 -4667
19 328 -8231
19 335 -7787
19 367 -5912
19 474 -590
20 115 -7690
20 129 356
20 207 -9098
20 237 -3298
20 278 7668
20 307 1045
20 336 -1814
20 385 904
21 167 3714
21 175 1947
21 185 6092
21 285 6656
21 352 1462
22 46 8371
22 63 -7119
22 85 -9225
22 101 -9660
22 156 -9282
22 208 -7025
22 237 -508
22 416 -4591
22 479 -2180
23 117 7541
23 198 3114
24 42 5136
24 89 401
24 268 5400
24 297 3760
24 348 48
25 278 6246
25 281 -2140
25 288 -3078
25 315 1949
25 328 4495
26 80 3206
26 94 6394
26 226 -6114
26 260 -6981
26 322 -560
26 366 -7642
26 432 4115
26 436 2275
27 30 2964
27 99 6073
27 189 3311
27 372 69
28 93 1885
28 192 -2679
28 260 5134
28 284 8488
28 458 -9550
28 496 843
29 61 -9929
29 66 7663
29 83 1029
29 142 -5099
30 288 8221
30 324 -9689
30 373 -5022
30 490 -5396
31 70 5151
31 107 -9611
31 156 -9373
31 221 7268
31 232 2075
31 267 -1337
31 272 1807
31 414 -2222
31 443 -1030
31 475 5263
32 213 4162
32 333 -5050
32 376 -5448
32 433 -4768
32 443 -4981
32 462 2102
33 102 3685
33 147 -865
33 301 -7033
33 392 2279
33 413 7099
34 169 -9727
34 211 8366
34 268 9651
34 357 1218
34 375 3935
34 417 6302
34 439 2083
34 456 -5727
35 225 -9215
35 315 6631
35 362 8945
35 493 3571
36 62 -1242
36 178 6305
36 292 -6348
36 301 2079
36 497 -5712
37 303 -562
37 476 4790
38 126 -761
38 179 2305
38 235 -1218
38 246 3710
38 267 8612
38 365 6473
38 373 -6005
38 376 247
38 388 -7439
38 395 7492
38 456 -4670
38 471 3819
39 122 -6276
39 170 5316
39 193 -3940
39 299 -1837
40 45 -1173
40 81 -5474
40 143 1350
40 161 2640
40 322 -5174
40 336 -7189
40 387 3360
41 66 -4827
41 100 9346
41 183 -9848
41 186 8129
41 220 -1776
41 281 5319
41 286 1270
41 336 6677
41 376 608
42 63 3020
42 131 4949
42 268 712
43 123 6522
43 154 -9305
43 168 4635
43 247 8258
43 258 5745
43 319 -1878
43 406 -1432
43 415 7553
43 428 9924
43 431 1393
43 482 8283
44 66 6927
44 197 -7215
44 231 4764
44 249 7757
44 297 339
44 317 4376
44 422 -1459
44 456 6604
45 68 -2951
45 202 -8727
45 219 1607
45 291 -3145
45 304 -9980
45 353 -6425
45 385 8454
45 403 9929
45 436 5789
45 495 9024
45 496 -5065
46 171 -3812
46 214 -8927
46 259 -6561
46 305 -4498
46 342 -2272
46 351 8878
46 372 5199
46 382 3499
46 452 3501
47 58 -3931
47 71 9490
47 88 9400
47 103 -1551
47 418 -4973
48 159 -3810
48 309 -2321
48 372 823
48 380 -8760
48 396 6428
49 95 -3905
49 125 993
49 196 2779
49 251 -2191
49 255 -2211
49 279 -2141
49 459 2431
49 484 -6785
50 65 4266
50 177 2525
50 194 9155
50 228 -4294
50 297 -1225
51 177 1630
51 223 6854
51 316 -1958
51 327 -9020
52 128 -6427
52 163 -9821
52 185 -8731
52 238 -8566
52 322 8467
52 443 8943
52 455 6943
53 70 -5040
53 414 -507
54 208 5922
54 298 8138
54 367 -863
55 74 -9806
55 111 -3854
55 138 -184
55 188 -944
55 211 7740
56 65 9727
56 141 3669
56 214 1623
56 239 1609
56 244 7576
56 475 -6542
57 176 -130
57 258 -5160
57 365 7655
57 421 -4680
58 333 -6694
59 158 -9038
59 257 3130
59 267 3293
59 326 185
59 343 -4103
59 403 -5780
59 424 9400
59 445 3970
60 75 -4458
60 98 1851
60 151 5579
60 152 -5617
60 158 5691
60 281 -2544
60 337 302
60 427 2681
60 454 632
60 456 4219
60 483 -953
61 83 -7267
61 88 -8574
61 338 1664
61 372 5879
61 429 2849
62 83 6359
62 173 -7617
62 235 -6507
62 270 5311
62 286 2939
62 318 5306
62 365 8961
62 477 -4003
62 480 9555
63 108 9903
63 152 -1476
63 210 -3653
63 267 -8209
63 364 1907
63 477 7451
63 498 -5460
64 68 5150
64 148 -7784
65 86 4268
65 109 -7488
65 128 3617
65 200 1627
65 232 -9315
65 340 4849
65 366 -3340
65 444 6600
65 470 -7730
65 474 3282
65 496 5155
66 108 -8381
67 80 -1948
67 105 8218
67 122 842
67 228 -3447
67 230 -5611
67 317 2463
67 342 -9488
67 478 8343
68 131 5136
68 485 -4213
68 491 -3209
69 117 9912
69 156 9814
69 265 -6541
69 302 -4544
69 308 -3058
69 407 -3295
70 76 7741
70 398 4925
70 480 4684
71 170 -9236
71 266 845
71 337 8723
71 402 9580
71 429 1518
71 439 -3117
72 153 -9242
72 212 -8966
72 322 -4104
72 399 1870
72 468 9545
73 121 784
73 165 1423
73 181 -3188
73 380 -9971
73 448 5790
73 489 -3208
73 494 -2348
74 102 -3527
74 433 3831
75 146 -2873
75 159 1589
75 227 3195
75 422 -9088
75 424 6637
76 101 -2248
76 102 5298
76 216 929
76 226 504
76 235 -5966
76 411 -2763
76 467 -8172
77 111 8021
77 143 4466
77 233 -3445
77 339 -2060
77 352 -3500
77 368 -2876
77 404 -3515
78 188 4530
78 206 4630
78 292 -1847
78 328 1681
78 466 2597
79 85 8242
79 99 5505
79 164 2631
79 181 -5362
79 258 5017
79 278 3258
79 368 2668
79 418 484
79 492 -9964
80 151 -162
80 166 2315
80 313 -2736
80 440 6285
81 106 -5778
81 139 -1971
81 143 6518
81 373 1288
81 407 8131
81 409 9533
82 94 -7789
82 111 -3874
82 158 5544
82 322 981
82 364 -675
82 382 -25
82 442 2404
82 469 -9808
83 183 6801
83 203 -8557
83 233 -3328
83 260 -5134
83 285 1818
83 308 -7277
83 325 7198
83 340 -8417
83 445 -6696
84 95 -7979
84 246 2363
84 443 55
84 499 8931
85 124 8625
85 212 8077
85 363 -7094
85 482 -1971
86 213 -7043
86 219 -6473
86 244 3250
86 250 2638
87 122 -8824
87 157 8589
87 226 -9223
87 250 9825
87 376 -3699
88 100 2465
88 158 2060
88 326 9694
88 353 9832
88 453 -8693
88 477 -6582
89 195 7734
89 247 5263
89 296 -4929
89 320 4386
89 451 3579
90 110 -6267
90 165 1787
90 216 4668
90 225 -2733
90 316 -4576
90 484 5215
91 139 -3658
91 149 7220
91 269 -6675
91 373 3480
91 451 2897
91 489 -1308
91 499 -3787
92 141 -7312
92 143 2041
92 196 -4884
92 292 -745
92 332 -403
92 386 -1598
92 409 -8102
92 437 1630
92 493 2864
93 154 8264
93 312 9854
93 399 1519
93 438 -3043
93 477 3753
94 127 -2436
94 174 -6255
94 338 9500
94 405 4629
94 447 -8934
95 174 6189
95 179 -3930
95 247 166
95 259 5691
95 309 7280
95 327 914
95 344 -3188
95 429 9747
95 483 -3586
95 487 2890
96 204 -2433
96 390 6294
96 499 9686
97 147 -6620
97 166 -2437
97 195 975
97 235 -5079
97 339 1693
97 388 -7687
97 485 -9789
98 139 9746
98 143 7044
98 146 -5169
98 323 -295
98 366 9471
98 368 -7792
98 382 5352
99 119 5223
99 157 -9
99 223 -6699
99 239 -6488
99 362 4890
99 444 -4849
100 202 -7606
100 241 1434
100 244 13
100 291 -7435
100 322 -1627
100 365 -8596
100 405 281
101 173 -3023
101 408 4550
102 183 -8982
102 191 7036
102 386 -3881
102 387 -9849
102 398 -8299
102 402 3423
102 455 1154
103 109 5221
103 162 291
103 221 -9998
103 229 3466
103 272 -7824
103 301 -4044
103 314 6070
103 352 -8013
103 454 -9992
104 140 1441
104 191 -6384
104 223 -7868
104 229 809
104 266 -5909
104 278 2508
104 370 3153
104 375 2320
104 402 -1853
104 445 -896
105 281 -3347
105 324 2296
105 391 5124
105 441 7684
105 478 -4873
105 486 3139
106 205 8503
106 233 9630
106 286 4375
106 378 -5125
106 459 -7473
107 172 644
107 253 -2706
108 177 3287
108 477 -4659
109 130 9999
109 140 2797
109 221 -6611
109 249 -1368
110 132 -8834
111 142 3534
111 146 -9966
111 202 6971
111 205 781
111 265 8151
111 385 2328
112 265 5067
112 394 -1754
112 410 -4292
112 432 9119
112 496 -5901
113 157 16
113 229 -1969
113 367 -1358
113 373 -5059
113 474 7808
114 332 618
114 415 6795
115 124 6054
115 129 3161
115 245 9838
115 318 -3240
115 364 -5521
115 441 -3067
115 480 2162
115 494 -907
116 145 -9135
116 197 -6213
116 469 76
117 217 4024
117 313 -8467
117 337 -2704
117 451 6425
117 459 6122
118 145 -2934
118 165 -5992
118 204 1840
118 257 -3861
118 348 -7076
118 359 4336
118 373 91
118 457 7143
119 150 1666
119 247 -1467
119 351 8260
119 398 -1460
119 412 7986
119 434 4597
119 495 8884
120 128 -2729
120 205 -2886
120 240 1483
120 296 3413
120 358 1023
120 373 -9213
120 495 -4274
120 498 9699
121 182 -5624
121 183 9056
121 194 1265
121 382 -8779
121 426 -3587
122 132 -788
122 247 5422
122 252 8593
122 259 -7997
122 305 -7289
122 370 6170
122 416 -2053
122 468 -2361
123 167 4408
123 215 9313
123 229 -4484
123 304 8091
124 157 -8496
124 235 5613
124 500 -3072
125 248 3739
125 311 8870
125 486 -1861
126 139 -8639
126 191 7096
126 241 8324
126 249 -441
126 344 8100
126 393 -6017
126 401 -8102
126 466 -7322
127 213 2868
127 315 1159
127 348 7978
127 402 3465
127 406 1382
127 425 224
127 434 4078
127 446 8737
128 244 -2163
128 292 8681
128 354 -9071
128 403 8960
128 412 -9322
129 157 6011
129 276 -2387
129 289 165
129 318 -7647
129 426 1670
130 184 8772
130 231 -6013
130 237 -9047
130 270 487
130 377 -1921
130 436 2551
130 465 -5821
131 157 2660
131 163 3125
131 204 -8867
131 322 -8494
132 153 59
132 193 1400
132 216 -7717
132 295 -4924
132 319 -4119
132 363 -7224
132 372 7758
132 397 -349
132 462 -4599
132 476 -2999
132 491 -2336
133 191 1140
133 325 8827
133 327 -729
133 365 -8417
133 490 3785
134 187 1752
134 472 1927
135 216 -932
135 220 -9436
135 436 6307
135 441 -2936
135 500 -1772
136 142 6535
136 183 1647
136 210 2663
136 239 -6675
136 259 -9993
136 331 2192
137 146 3355
137 147 -8845
137 163 2456
137 164 -1564
137 248 835
137 471 1919
137 491 -7463
138 267 -6204
138 269 -9121
138 304 -9806
138 407 8474
138 431 -8652
139 152 3671
139 157 -874
139 186 -4568
140 155 8115
140 235 1573
140 287 -3859
140 397 -1008
141 169 -2525
141 419 -3743
141 429 -1127
141 484 6820
142 319 5686
143 460 -8069
144 187 8538
144 256 6490
145 169 2619
145 236 8364
145 274 1112
145 309 -4818
145 310 8778
145 370 -572
145 437 6956
146 222 7873
146 238 -9222
146 330 1615
146 337 -825
146 413 1128
146 461 7323
146 485 -1430
147 156 -8069
147 293 8878
148 160 835
148 185 6802
148 308 -5387
149 197 9403
149 226 -9402
149 255 763
150 213 9424
150 251 3004
150 331 -3
150 460 -4943
151 171 9050
151 185 -6430
151 201 9017
151 261 -7835
151 276 -2826
152 227 -4796
152 250 -2644
152 363 1994
152 391 5083
152 393 663
152 414 -10000
152 427 1339
153 200 3578
153 281 3249
153 300 -5928
153 404 3817
153 469 -7547
153 498 -6845
154 190 -7567
154 303 1382
154 335 -2600
154 337 7203
154 344 -1295
154 383 -2597
154 448 61
155 209 944
155 272 9893
155 305 -8235
155 338 -4039
155 379 9750
156 172 3969
156 248 3123
156 322 8538
156 370 76
156 486 -8359
157 300 -8234
157 345 4230
157 354 6083
158 252 -4490
158 386 9730
159 335 -8205
159 378 3173
159 397 -7157
159 406 8444
160 247 3760
161 218 1596
161 377 -9871
161 439 4256
161 484 6320
162 173 8856
162 298 718
162 433 -5687
163 169 -105
163 400 7596
164 214 7529
164 247 -2548
164 405 -4926
164 448 3596
165 198 -414
165 248 -7477
165 292 8625
166 265 -3934
166 282 702
166 285 4258
166 356 -2006
166 495 4133
167 201 -2809
167 248 -976
167 312 -6573
167 314 -4689
167 379 6664
167 440 2182
167 445 1085
167 488 -9090
167 493 -4072
168 197 5974
168 240 -3640
168 399 -5704
168 421 3367
169 338 -8967
169 394 -4660
169 425 951
169 449 -7246
169 461 6563
170 172 6055
170 193 617
170 218 -7389
170 224 -8631
170 245 -769
170 267 9033
170 320 -7051
170 357 8702
170 411 -2058
171 177 9792
171 372 -6686
171 421 7323
171 449 6235
172 211 -8557
172 314 6500
172 322 -5817
173 203 2295
173 213 2724
173 372 8600
173 428 -8093
173 456 8760
174 291 5666
174 492 -694
174 495 1955
175 185 1216
175 200 8457
175 205 -8284
175 256 -438
175 307 -5851
175 339 -7008
175 365 -6619
175 393 -5717
176 207 6188
176 242 -649
176 289 3109
176 422 4779
177 445 2306
177 486 8223
178 232 2530
178 448 -2604
178 468 134
179 227 -1273
179 288 -4893
179 425 5093
179 428 -8340
180 298 2504
181 488 1886
182 193 -6632
182 270 -1554
182 320 7394
182 340 6280
182 377 7890
182 425 8577
182 480 1362
183 193 6227
183 199 -1706
183 237 6799
183 367 -1432
183 408 4053
183 415 6853
183 431 1276
184 210 -3111
184 290 -4607
184 465 2062
184 479 -3142
185 213 7099
185 320 5947
185 359 -6637
185 428 -114
186 198 -9486
186 199 3250
186 298 3968
187 387 -4246
187 486 6414
188 351 7176
188 398 7300
188 420 -243
188 479 2577
189 225 -2315
189 420 8513
189 488 8460
189 498 3052
190 256 3716
191 213 -4766
191 355 3463
191 476 -7120
192 263 -3627
192 339 3794
192 350 8272
192 433 -6813
192 435 1662
193 248 -4769
193 360 3623
193 443 -772
193 452 -9490
193 474 -2936
193 478 -4892
194 274 583
194 308 9724
194 331 4260
194 496 -4010
195 346 -9407
195 350 -212
195 355 3065
195 431 -7120
196 219 3442
196 263 -4895
196 266 -6390
196 296 -5022
196 334 9480
196 340 1123
196 416 9233
197 208 1046
197 242 8330
197 250 2194
197 380 -885
197 412 -564
197 435 1743
198 200 -7410
198 234 -6093
198 252 -6392
198 459 8674
199 258 -621
199 406 -3337
200 212 -5618
200 272 1856
200 349 171
200 400 -3876
200 407 -146
201 260 -3438
201 304 4721
201 324 4802
201 454 7876
202 217 -5366
202 286 8869
203 211 -4145
203 253 6998
203 331 6905
203 374 -6327
203 406 -9424
203 412 3675
204 231 -6073
204 243 6298
204 283 832
204 389 8924
204 459 9117
204 467 -8510
205 252 3285
205 446 -1787
206 432 -8822
207 214 -3104
207 235 -3264
207 348 5600
207 385 4137
208 232 4028
208 236 -4332
208 246 9627
208 385 -1105
208 448 7275
208 466 -7370
209 243 -3754
209 267 -6273
209 305 6161
211 230 3348
211 421 -4794
211 443 -7502
212 264 -7012
212 286 -9917
212 311 8251
212 423 2755
213 348 -1196
213 364 -2205
214 305 -3680
214 363 -2848
214 376 3221
214 497 -505
215 470 -401
215 493 -191
216 239 -3522
216 393 -534
216 410 -2461
216 460 7812
217 270 -4519
217 275 9153
217 292 6055
217 475 6329
217 491 -9531
218 244 -8687
219 290 3758
219 396 3953
219 485 -6143
220 250 -135
220 269 2763
220 319 -5456
220 353 789
220 399 -5050
221 246 5281
221 304 4355
221 312 -3212
221 479 -3444
222 292 3415
222 338 1753
222 346 8628
222 370 9853
222 380 -3720
222 407 1917
222 423 -1460
222 446 8140
222 473 4443
222 488 7164
223 236 8651
223 243 5533
223 305 -826
223 358 2512
223 407 1829
223 473 6710
224 482 2769
225 283 -4027
225 315 -9440
225 485 -3447
226 258 -9022
226 263 4293
226 302 8024
226 390 7503
226 446 6681
226 459 2031
226 492 9193
226 495 -2439
227 229 7428
227 357 9224
227 473 -573
227 477 1183
228 234 4008
228 386 -9013
228 397 -7927
228 472 1465
229 239 -1880
229 356 -7955
229 368 -3874
229 449 5955
230 276 -5718
230 311 4350
230 315 -9532
230 341 -9152
230 424 -3571
230 499 -2295
231 276 582
231 412 -5595
231 440 -5095
231 480 -3834
231 482 -1069
232 312 -6425
232 313 8251
232 331 -1972
232 374 -1096
233 263 -8107
233 277 -7785
233 455 -1766
234 266 5292
234 296 9612
234 369 6746
234 377 -1774
234 400 3627
235 298 -449
235 336 5364
235 413 -8868
236 274 9390
236 421 -6331
236 469 1319
236 477 4382
237 268 -6651
237 341 190
237 385 7935
237 409 -2603
237 459 1672
238 263 8954
238 271 -3836
238 275 -7472
238 369 -5942
238 377 2927
238 409 8221
239 391 -9266
239 421 -4822
239 452 5937
240 322 -3338
240 339 3282
240 399 -2622
241 302 -2907
241 409 7745
241 444 -6059
242 289 -955
242 339 2001
242 368 1164
243 460 -7045
243 463 -5135
243 470 1449
243 487 6043
244 265 1566
244 374 -1285
244 398 7976
244 448 718
244 500 -4182
245 260 8850
245 436 4045
245 484 7330
246 265 -3434
246 336 -6729
246 438 -3820
246 486 8603
247 343 3748
247 382 -1009
248 292 7907
248 450 -4786
248 468 -1092
248 478 3078
248 482 -6116
249 313 3515
249 325 -5814
249 411 7358
249 438 1582
249 458 -6860
249 459 238
249 480 9963
250 446 3422
250 462 -5069
250 489 7450
251 257 1209
251 449 -7320
251 453 2129
252 287 -397
252 314 1118
252 414 6273
253 263 5128
253 306 -952
253 402 2856
253 436 -5911
254 280 -8438
254 322 -1109
254 490 -340
255 272 2320
255 298 -6885
255 440 -8229
255 495 2356
256 290 -4019
256 345 -5305
256 375 6639
256 438 -794
257 274 730
257 320 -2710
257 339 4157
257 353 7433
257 393 -3212
257 448 -9484
258 278 -3756
258 314 -2667
258 340 -7890
258 474 -4979
259 285 3037
259 317 -4276
259 330 -782
259 385 8469
259 420 2164
259 443 755
260 267 -9134
260 365 -4664
260 415 4024
260 479 -7629
260 496 -5938
262 388 -855
263 447 6606
263 484 9396
264 270 -3693
264 351 -5652
264 371 -6151
264 451 3117
264 493 6685
265 424 -165
265 496 3908
266 372 6772
266 411 -6081
266 441 6677
267 317 4793
267 350 -1054
267 352 -2063
267 408 -7695
267 464 -7760
268 277 1239
268 298 8735
268 338 8235
268 412 -1794
268 450 6463
268 487 2888
269 477 9993
270 311 -14
270 325 -6345
270 483 8353
271 290 9280
271 439 -5855
272 482 -3664
272 496 -7845
273 278 9765
273 291 5124
273 314 4107
273 478 -1777
274 299 3577
274 337 -3927
274 339 -2127
274 344 6229
274 468 6070
275 349 3353
275 394 8581
275 418 7429
275 425 9139
276 347 7978
276 431 6269
276 432 -7970
276 450 5965
276 476 -9556
277 279 5868
277 298 -1464
277 326 -2266
277 453 -5936
277 462 -1412
278 321 7572
278 344 8058
279 351 -3464
279 442 -1719
280 378 544
280 409 -292
281 291 -7273
282 312 375
282 349 -9869
283 294 -6687
283 318 9299
283 398 -7542
283 468 6833
283 469 -9907
284 318 7298
284 354 -9097
284 385 9302
285 366 -9502
285 473 5517
286 360 -5149
286 379 9500
286 414 5381
286 426 2255
286 428 7164
286 500 -6235
287 378 -4225
287 459 2745
287 498 -1815
288 372 6372
289 297 -5802
289 383 7223
289 439 1304
290 322 593
290 412 7623
290 465 2827
290 467 -4613
291 343 4818
291 420 4993
291 437 -8494
292 412 2192
292 463 -5174
293 343 -8657
294 327 5312
294 346 -2660
294 428 924
294 449 -7189
295 337 -3608
295 426 -105
295 437 7082
295 498 537
296 454 3345
296 459 3449
296 491 -7492
297 382 8458
297 493 6739
297 498 5345
298 361 6214
298 367 5118
298 405 7802
298 418 -9505
298 441 -5427
298 494 -4071
299 412 -6638
299 479 -5738
300 344 -8409
300 495 -8315
301 384 6586
301 407 -1315
301 499 -7760
302 360 -3943
304 384 4189
305 312 7707
305 315 5953
305 322 -5192
305 355 -4403
305 418 -3646
307 314 4842
307 340 -8967
307 354 -7654
307 362 -4051
308 389 -8415
308 409 7497
308 496 -4559
309 346 -9056
309 456 5089
310 315 -8266
310 341 -9066
310 431 -7614
310 454 -1644
312 363 3816
312 474 -8920
313 374 1879
313 470 -9447
313 475 -902
313 487 -320
313 495 2173
313 498 -3278
314 373 8505
314 455 -9700
314 477 -6120
314 496 1787
314 500 4895
315 365 7391
315 366 -6131
315 411 4342
315 477 -2638
316 462 3135
316 476 -6467
317 427 6162
317 453 -9333
317 479 9303
318 486 -3055
319 376 585
320 330 -1721
320 357 -4449
320 375 6582
320 464 9850
321 357 -7452
321 416 -8708
322 377 -382
322 401 -3823
323 332 7997
323 398 -9158
323 476 327
324 393 -3743
325 420 -4767
325 437 -2082
325 471 2162
325 480 -3105
326 404 9588
327 424 -1046
327 453 -8709
328 464 977
329 407 -5566
329 498 -9021
330 344 5534
330 463 -195
330 473 7879
332 352 -7936
332 486 9142
333 366 -3372
333 450 77
333 451 -5301
333 481 -3148
333 482 6547
334 411 -5706
334 480 1301
334 484 6071
334 491 -1241
335 442 -4979
336 339 5558
336 399 -2245
336 461 -8129
337 383 -6903
338 360 6010
338 377 7453
338 382 -8645
339 369 2718
339 395 5299
339 404 9746
340 350 8615
340 386 6167
340 407 2399
340 484 -1929
341 343 -5565
341 420 5265
341 458 -6180
342 346 8831
342 489 1939
343 378 4970
343 397 -7570
343 424 2842
343 452 -536
343 488 -6842
344 356 -7281
344 453 -8302
345 425 -5731
346 454 -3527
347 392 5563
347 418 -2386
347 466 3771
347 468 -4049
348 397 6497
348 486 -2415
349 352 -613
349 398 3335
350 378 6543
350 434 7699
350 465 9140
350 482 -2291
351 409 -1048
351 426 3612
351 471 409
353 395 9151
353 412 9296
353 419 -735
353 436 -5275
353 453 -1087
353 500 8370
354 359 -4117
354 386 -846
354 410 1672
355 406 -1579
355 420 -8857
355 497 -895
356 466 -8140
357 404 -2310
357 450 1350
358 382 3911
358 386 3609
358 395 -6761
358 436 8427
359 495 1554
360 459 -6735
360 489 -9515
361 377 4408
361 437 -1746
361 488 -2367
361 499 8199
362 422 9597
362 427 4182
364 375 7988
364 415 6754
365 426 -6930
365 481 -3070
366 382 -6765
366 432 -9909
366 454 -9405
367 380 -5349
367 412 3542
368 380 6629
368 411 -1355
368 421 1195
368 465 6223
368 470 -334
368 474 -7991
368 493 2282
369 376 3704
369 450 -2512
370 420 -9950
371 398 -9477
371 432 -6670
371 448 -200
372 387 6424
373 380 -3592
373 470 -8502
375 393 9105
375 453 -2933
375 492 -6444
376 427 -7114
376 470 -4493
377 434 9582
378 465 3894
379 398 8878
379 491 9760
380 439 -1859
381 407 9593
381 484 -1667
382 405 6975
382 499 4725
383 466 7807
384 442 -9312
384 480 5442
384 485 -3665
385 410 -2643
385 422 2303
386 438 6767
388 481 3277
389 411 -7853
390 417 3903
390 463 7696
390 479 9257
392 465 3120
392 493 759
394 398 6573
394 494 7679
395 479 1669
395 495 -2332
396 459 6338
398 450 -9491
398 476 -8221
398 481 -9932
399 424 -4886
399 445 6302
400 433 -6294
401 412 -662
401 464 9064
401 480 -8775
402 469 -1306
403 498 1210
406 420 -2125
407 488 7000
410 459 -1638
410 467 -1424
410 478 -1565
410 493 -7145
411 445 1797
420 464 -3068
420 492 -1060
421 435 -8158
422 469 -8414
423 440 -2764
423 493 1392
424 472 6518
425 498 -57
427 451 4970
428 433 -4289
428 487 896
429 453 4573
430 443 -3248
433 482 -5668
433 494 9608
433 499 7927
434 488 -447
438 479 3219
441 466 -2111
442 454 -7877
442 488 -4811
445 483 -1801
452 462 8016
452 489 -1217
452 497 -8325
454 489 -9298
454 498 -4686
456 474 1691
457 500 2717
459 478 2393
460 492 -5705
460 499 9321
462 471 -2894
463 473 -5410
463 477 1205
464 468 -2595
464 475 -9291
467 473 9837
473 500 1052
474 491 7245
478 480 -4790
496 500 -1519
)"
    }; // const std::string Input

} // namespace Assignment
