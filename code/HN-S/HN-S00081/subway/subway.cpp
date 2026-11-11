#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 500 + 10;
int c, n, m, d, q;
const int MAXM = 510;
int dist[MAXM][MAXM];
int w[MAXN];
struct node {
	int v, w;
};
vector <node> G[MAXN], g[MAXM];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			g[i].push_back({a, t});
			G[a].push_back({i, t});
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto x : G[i]) {
			for (auto y : G[i]) {
				if (x.v == y.v) continue;
				dist[x.v][y.v] = min(dist[x.v][y.v], x.w + y.w);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (auto u : G[x]) 
			for (auto v : G[y]) ans = min(ans, w[x] + w[y] + dist[u.v][v.v] + u.w + v.w);
		cout << ans << '\n';
	}
	return 0;
}
/*
T2 怎么又是图论？

由于 d <= 20，所以你可以在询问的时候枚举由这两个站下面的那个站台到达

注意到这个 n + m 个点建图方式：

- 每条线路向所属点连边

注意到 n <= 500

所以我们枚举的两条线路之间的最短路，可以算出来！

这个可以 floyd 算出来！ 

大样例过了，我无疑是兴奋地！ 

应该有七√了！ 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


1 037202
2 8361 72 9
3 3142 55 100
4 3263 17 2
5 4325 100 46 6 7
6 16
7 23
*/
