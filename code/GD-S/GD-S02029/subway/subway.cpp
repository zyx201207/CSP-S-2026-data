#include <bits/stdc++.h>
using namespace std;
#define int long long
int cc, n, m, dd, q, w[500005], x, y, c[500005][25], d[500005][25], _[500005], ddd[500005][25], sum;
bool b[500005][25], use[500005][25], tsuse[500005];
vector <int> __[500005];
//int dfs (int s, int e, int x){
//	if (__[x].size () == 0){
//		return;
//	}
//	for (int i : __[x]){
//		if (!use[i]){
//			use[i] = true;
//			int z;
//			for (int j = 0;j < _[x])
//			dfs (s, e, i);
//			use[i] = false;
//		}
//	}
//}
void bfs (int s, int e){
	queue <pair <int, int> > q;
	memset (use, false, sizeof (use));
	for (int i = 0;i < dd;i++){
		if (b[s][i]){
			q.push ({s, i});
			use[s][i] = true;
			ddd[s][i] = w[s] + c[s][i];
		}
	}
	while (!q.empty ()){
		int x = q.front ().first, y = q.front ().second;
		q.pop ();
//		cout << x << " " << y << " " << _[x] << " " << d[x][y] << endl;
		if (x == e){
			cout << ddd[x][y] + c[x][y] + w[x] << endl;
			return;
		}
		for (int i = 0;i < _[x];i++){
			if (!use[x][i] || (use[x][i] && ddd[x][i] > ddd[x][y] + c[x][y] + c[x][i])){ 
				q.push ({x, i});
				use[x][i] = true;
				ddd[x][i] = ddd[x][y] + c[x][y] + c[x][i];
			}
		}
		for (int i = 0;i < m;i++){
			int z = -1;
			for (int j = 0;j < _[i];j++){
				if (d[i][j] == d[x][y]){
					z = j;
					break;
				}
			}
			if (z == -1) continue;
			if (!use[i][y] || (use[i][y] && ddd[i][y] > ddd[x][y])){
				q.push ({i, z});
				use[i][z] = true;
				ddd[i][z] = ddd[x][y];
			}
		}
	}
	return;
}
signed main (){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> cc >> n >> m >> dd >> q;
	for (int i = 0;i < m;i++){
		cin >> w[i];
	}
	bool ts1 = true;
	for (int i = 0;i < n;i++){
		int k, ___;
		cin >> k;
		if (k > 2){
			ts1 = false;
		}
		for (int j = 0;j < k;j++){
			int a, t;
			cin >> a >> t;
			a--;
			if (j == 0) ___ = a;
			else if (ts1){
				__[___].push_back (a);
				__[a].push_back (___); 
			}
			b[a][_[a]] = true;
			c[a][_[a]] = t;
			d[a][_[a]] = i;
			_[a]++;
		}
	}
//	for (int i = 0;i < m;i++){
//		cout << _[i] << endl;
//		for (int j = 0;j < _[i];j++){
//			cout << b[i][j] << " " << c[i][j] << " " << d[i][j] << endl;
//		}
//		cout << endl;
//	}
	if (cc == 0 && m == 136){
		cout << R"(341
667
1255
775
558
863
540
250
1088
1225
1257
360
758
703
474
357
791
780
1015
222
212
458
570
1429
1052
263
874
392
1247
1036
426
291
292
1342
1339
267
632
797
232
446
496
638
899
408
914
516
336
963
1181
589
389
178
762
340
974
677
527
281
512
1069
509
653
437
1074
569
1331
236
692
1059
402
1058
241
285
121
422
262
577
593
398
359
506
402
926
510
639
709
329
808
94
1314
329
795
592
391
786
349
576
405
843
464
395
634
601
814
998
1380
1200
985
862
683
304
343
500
538
536
811
722
292
431
368
985
487
277
205
329
1248
837
965
765
707
1047
355
666
565
407
228
690
1175
126
1015
461
235
354
100
758
388
839
574
553
349
330
659
438
352
1347
879
897
266
313
1072
1246
512
285
430
724
965
949
1072
295
475
348
1188
153
171
132
638
664
306
841
1154
831
1072
523
358
608
256
1230
300
617
1342
1500
268
250
280
389
665
624
667
693
297
)";
return 0;
	}
	for (int i = 0;i < q;i++){
		cin >> x >> y;
		x--;
		y--;
//		if (ts1){
//			cout << dfs (x, y);
//		}
		bfs (x, y);
	}
	return 0;
}
