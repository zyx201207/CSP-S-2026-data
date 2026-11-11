#include <bits/stdc++.h>

using namespace std;

const long long N = 500 + 5;
const long long M = 5e5 + 5;
const long long INF = 1e18;

vector <pair <long long, long long>> G[M], T[N];
long long c, n, m, d, q, x, y, w[M], vis[N], t[N][N], dis[N][N];

void Dij (long long r) {
	queue <long long> q; memset (vis, 0, sizeof (vis));
	for (long long i = 1; i <= n; i ++) dis[r][i] = INF;
	vis[r] = 1; q.push (r); dis[r][r] = 0;
	while (! q.empty ()) {
		long long u = q.front (); q.pop ();
		for (auto i : T[u]) {
			long long j = i.first;
			if (vis[j] == 0) vis[j] = 1;
			if (dis[r][j] > dis[r][u] + i.second)
				dis[r][j] = dis[r][u] + i.second, q.push (j);
			else if (vis[j] == 0) q.push (j);
		} 
	}
} 

int main () {
	freopen ("subway7.in", "r", stdin);
	freopen ("subway2.out", "w", stdout);
	scanf ("%lld %lld %lld %lld %lld", & c, & n, & m, & d, & q); 
	for (long long i = 1; i <= m; i ++) scanf ("%lld", & w[i]); 
	for (long long i = 1; i <= n; i ++) {
		long long k; cin >> k;
		while (k --)
			scanf ("%lld %lld", & x, & y) , G[x].push_back ({y, i});
	}
	for (long long i = 1; i <= n; i ++)
		for (long long j = 1; j <= n; j ++) t[i][j] = INF;
	for (long long i = 1; i <= m; i ++)
		for (auto j : G[i])
			for (auto k : G[i]) {
				long long p = j.second, l = k.second;
				if (p == l) continue;
				t[p][l] = min (t[p][l], j.first + k.first);
				t[l][p] = t[p][l];
			}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (t[i][j] != INF)
				T[i].push_back ({j, t[i][j]});
	for (int i = 1; i <= n; i ++) Dij (i);
	while (q --) {
		long long ans = INF;
		scanf ("%lld %lld", & x, & y); 
		for (auto i : G[x]) for (auto j : G[y])
			ans = min (ans, dis[i.second][j.second] + i.first + j.first);
		printf ("%lld\n", ans + w[x] + w[y]); 
	}
	return 0;
}
