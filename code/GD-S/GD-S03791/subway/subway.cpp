#include <iostream>
#include <vector>
using namespace std;
#define ll long long
constexpr int maxn = 500 + 10, maxm = 5e5 + 10;
ll dis[maxn][maxn]; int w[maxm], k[maxn];
vector <pair <int, int> > e[maxm];
signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			int u, v; cin >> u >> v;
			e[u].push_back({i, v});
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= m; i ++) {
		int len = e[i].size();
		for (int j = 0; j < len; j ++) {
			for (int k = 0; k < len; k ++) {
				if (j == k) continue;
				int u = e[i][j].first, v = e[i][k].first;
				long long w = e[i][j].second + e[i][k].second;
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			}
		}
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q --) {
		int s, t; cin >> s >> t; ll Mn = 1e18;
		int L1 = e[s].size(), L2 = e[t].size();
		for (int i = 0; i < L1; i ++) {
			for (int j = 0; j < L2; j ++) {
				int u = e[s][i].first, v = e[t][j].first;
//				cout << u << ", " << v << " : " << e[s][i].second << 
				Mn = min(Mn, e[s][i].second + e[t][j].second + dis[u][v]);
			}
		} cout << Mn + w[s] + w[t] << '\n';
	}
}
