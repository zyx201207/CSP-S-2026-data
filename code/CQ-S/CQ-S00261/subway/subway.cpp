#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
using i64 = long long; using pii = pair<int, int>;

const int D = 21, N = 5e5 + 10, M = 5e2 + 10;
const i64 inf = 1e18;
i64 dis[M][M], w[N], dis2[N];
bool vis[M + N];
vector<pair<int, i64> > g[N + M];
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	rep (i, 1, m) cin >> w[i];
	rep (u, 1, n) {
		int k; cin >> k;
		rep (j, 1, k) {
			int v, w; cin >> v >> w;
			g[u + m].emplace_back(v, w), g[v].emplace_back(u + m, w);
		}
	}
	rep (i, 1, n) rep (j, i + 1, n) dis[i][j] = dis[j][i] = inf;
	rep (i, 1, m) {
		for (auto x : g[i]) {
			for (auto y : g[i]) {
				if (x.first != y.first) dis[x.first - m][y.first - m] = x.second + y.second;
			}
		}
	}
	rep (k, 1, n) rep (i, 1, n) rep (j, 1, n) dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
	while (q--) {
		int x, y; cin >> x >> y;
		i64 mi = inf;
		for (auto i : g[x]) for (auto j : g[y]) {
			mi = min(mi, dis[i.first - m][j.first - m] + i.second + j.second);
		}
		cout << mi + w[x] + w[y] << '\n';
	}
}
