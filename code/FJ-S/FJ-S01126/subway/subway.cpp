#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int C, n, m, d, q, w[500005];
vector <pair <int, int> > c[500005];
int dis[505][505];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int u, t; cin >> u >> t;
			c[u].push_back(make_pair(i, t));
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			dis[i][j] = 1e18;
	for (int i = 1; i <= n; i++) 
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int)c[i].size(); j++) {
			for (int k = j + 1; k < (int)c[i].size(); k++) {
				int u = c[i][j].first, v = c[i][k].first;
				int W = c[i][j].second + c[i][k].second;
				dis[u][v] = min(dis[u][v], W);
				dis[v][u] = min(dis[v][u], W);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v; int ans = 1e18;
		for (int i = 0; i < (int)c[u].size(); i++) {
			for (int j = 0; j < (int)c[v].size(); j++) {
				ans = min(ans, dis[c[u][i].first][c[v][j].first] + c[u][i].second + c[v][j].second);
			}
		}
		cout << ans + w[u] + w[v] << endl;
	}
	return 0;
}
