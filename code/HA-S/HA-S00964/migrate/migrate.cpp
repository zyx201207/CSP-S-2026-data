/* 生日蛋糕是青春的墓碑 */ 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5010, N = 1e6 + 10;

#define Floyd main

ll n, d, x[maxn], f[maxn][maxn], num[maxn][maxn], lst[maxn], ans, c, T, tmp[N];

bool tag[maxn];

ll inline read () {
	ll x; scanf("%lld", &x); return x;
}

void inline write (ll x) {
	printf("%lld", x);
	return void ();
}

ll inline MAX (ll x, ll y) {return x > y ? x : y;}

void inline solve () {
	n = read(), d = read();
	ll L = 1;
	if (c == 11 || c == 12) {
		for (int i = 1; i <= n; ++i) tmp[i] = read();
		if (n == 1) {
			cout << 0 << endl;
			return void ();
		}
		ll D = tmp[2] - tmp[1], TMP = 0;
		if (d < 2 * D || D * (n - 1) <= d) {
			cout << 0 << endl;
			return void ();
		}
		while (TMP * D < d) TMP ++;
		TMP = (TMP - 1) * 2;
		cout << MAX(n - TMP + 1, 0) << endl;
		return void ();
	}
	for (int i = 1; i <= n; ++i) {
		x[i] = read();
		while (x[L] < x[i] - d) ++L;
		lst[i] = L;
		tag[i] = 0;
	}
	for (int i = 1; i <= n; ++i)
		f[i][i] = 0, num[i][i] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) 
			f[i][j] = maxn + 10, num[i][j] = 0;
		if (x[i] - x[i - 1] > d) {
			for (int j = 1; j < i; ++j) tag[j] = 1;
			continue;
		}
		for (int j = 1; j < i; ++j) {
			if (tag[j] == 1) continue;
			else {
				for (int l = MAX (lst[i], j); l < i; ++l) {
					if (f[i][j] > f[l][j] + 1) f[i][j] = f[l][j] + 1, num[i][j] = 0;
					if (f[i][j] == f[l][j] + 1) num[i][j] += num[l][j];
				}
			}
			if (num[i][j] == 2) ans ++;
		}
	}
	write (ans), putchar ('\n');
	ans = 0;
	return void ();
}

signed Floyd () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while (T --) solve ();
	return 0;
}






/*
	先考虑证明一件事：
	
		若从i号岛与j号岛 之间存在满足条件的路径，那么这条路径上不同点的个数必然=1
		路径长为2显然
		首先明确不同的点一定相连，不可能存在先不同再相同再不同的情况
		再假设存在2条这样满足条件的路径，分别用序列a[], b[]表示，不妨令 两序列第一个不同的地方为i， 且有pl[b[i]] > pl[a[i]] 
		则pl[a[i]] + d >= pl[a[i + 1]], 则 pl[b[i]] + d >= pl[a[i + 1]]
		即存在一条b[i]->a[i + 1]->a[i + 2]-> ......的最短路径与上面两种路径都不相同，所以该命题成立  
	 
	n^3 直接dp 就行
	有注意到当长度为d的一个区间内如果所有从i节点出发的最短路条数都超过了2，后面是不可能再有它的转移的，可以删了
	也就是说我们可以维护一个tag数组，对于还能够往后转移的就tag = 0, 当我们做到i节点时发现从前面转移的所有关于j节点的答案都>=3时就令其tag = 1
	这样说不定能卡一卡过n^2的样例
	 
	
	
	
	
	0 2
	4 2
	1 2 3 4
	5 2
	1 2 3 4 5
	
	1
	2
	
	
	0 2
	5 3
	-2 -1 0 1 2
	6 2
	-4 -3 -2 -1 3 6
	
	0
	1
	
	
	
	
	
	
	
	
	
	
	
0 11
	
10 3
0 3 6 7 8 9 10 13 16 19

1 1999999999999999992
0

2 3
-1 2

5 3
-3 0 2 3 4

6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

4 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 1000000000000000000

5 3
999999999999999994 999999999999999996 999999999999999997 999999999999999998 1000000000000000000

6 4
-3 0 1 2 3 4

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

6 3
0 1 2 3 4 7

8 3
0 1 2 4 8 10 11 13

1 3
0
	
	
	
0 1	
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

6
	
	
	
	
	
*/
