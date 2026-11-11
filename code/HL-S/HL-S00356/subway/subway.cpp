#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q, w[N];
vector<pair<int, int>> id[N]; // 对于 i 这个点 哪些大点包含我 以及我去这些大点的贡献 
int dis[510][510]; 

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int u, v; cin >> u >> v;
			id[u].emplace_back(i, v);
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto p1 : id[i]) for (auto p2 : id[i]) {
			int u = p1.first, v = p2.first;
			if (u == v) continue;
			dis[u][v] = dis[v][u] = min(dis[u][v], p1.second + p2.second);
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
	while (q--) {
		int u, v; cin >> u >> v;
		int ans = inf;
		for (auto s : id[u]) {
			for (auto t : id[v]) {
				ans = min(ans, s.second + t.second + dis[s.first][t.first]);
			}
		}
		cout << ans + w[u] + w[v] << "\n"; // wxy
	} 
	return 0;
}