/*自此 风王之瞳永伴君焰*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, maxn = 501;

const ll MAXX = 1e18;

#define Floyd main

ll inline read () {
	ll x = 0, f = 1;
	scanf("%lld", &x);
	return x * f;
}

void inline write (ll x) {
	printf("%lld", x);
	return void ();
}

inline ll MAX (ll x, ll y) {return x > y ? x : y;}
inline ll MIN (ll x, ll y) {return x < y ? x : y;}

ll n, m, d, q, c, ways[N][21], tim[N][21], dis[maxn][maxn], w[N];

void inline build () {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j) dis[i][j] = MAXX;
	for (int i = 1; i <= m; ++i) {
		for (int a = 1; a <= ways[i][0]; ++a) {
			for (int b = 1; b <= ways[i][0]; ++b) {
				if (a == b) continue;
				ll A = ways[i][a], B = ways[i][b];
				dis[A][B] = dis[B][A] = MIN (dis[A][B], tim[i][a] + tim[i][b]);
			}
		}
	}
	return void ();
}

void inline FLOYD() {
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dis[i][j] = MIN (dis[i][j], dis[i][k] + dis[k][j]);
	return void ();
}

ll inline getans (ll st, ll en) {
	ll ans = MAXX;
	for (int i = 1; i <= ways[st][0]; ++i)
		for (int j = 1; j <= ways[en][0]; ++j)
			ans = MIN (ans, dis[ways[st][i]][ways[en][j]] + tim[st][i] + tim[en][j]);
	return ans + w[st] + w[en];
}

void inline solve () {
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) {
		ll k = read ();
		for (int j = 1; j <= k; ++j) {
			ll id = read(), tt = read();
			ways[id][++ways[id][0]] = i;
			tim[id][ways[id][0]] = tt;
		} 
	}
	build ();
	FLOYD ();
	while (q--) {
		ll st = read(), en = read();
		write (getans (st, en)), putchar ('\n');
	}
	return void ();
}

signed Floyd () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll T = 1;
	while (T--) solve ();
	return 0;
}
/*
	考虑每一条地铁线相当于一个点，那么两点之间的距离为这两条线上任意两个地铁站厅来回最短时间 
	那么地铁线i与地铁线j之间的初始距离就应该是min (dis[i][j], t[i][k] + t[j][k]) (a[i][k] == a[j][k]) 
	然后我们就直接上n^3 Floyd 全源最短路就行
	别忘了加上从地铁站厅到地铁站门口的时间 
	本地2.6s我们就姑且认为它过了吧 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
	
	-> 32 17
	
	0 3 7 20 2
	8 3 6 1 7 2 9
	3 1 4 2 5 5 100
	3 2 6 3 1 7 2
	4 3 2 5 100 4 6 6 7
	1 6 
	2 3
	
	-> 35 16
*/
