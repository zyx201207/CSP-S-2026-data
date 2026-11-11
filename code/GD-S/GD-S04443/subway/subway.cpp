#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 INF = 2e18;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m);
	for (int i = 0; i < m; i++) cin >> w[i];
	
	vector<int> k(n);
	vector<vector<int>> a(n), t(n);
	vector<vector<array<int,2>>> co(m);  // co[i] = O(d)
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		a[i].resize(k[i]), t[i].resize(k[i]);
		for (int j = 0; j < k[i]; j++) {
			cin >> a[i][j] >> t[i][j], a[i][j]--;
			co[a[i][j]].push_back({i,t[i][j]});
		}
	}
	
	vector<vector<i64>> G(n, vector<i64>(n, INF));
	for (int i = 0; i < n; i++) G[i][i] = 0;
	for (int u = 0; u < m; u++) {   // O(md^2), can it AC?, or some O(md) / O(m)?
		for (int i = 0; i < co[u].size(); i++)
			for (int j = i + 1; j < co[u].size(); j++) {
				int x = co[u][i][0], y = co[u][j][0];
				i64 w = co[u][i][1] + co[u][j][1];
				G[x][y] = G[y][x] = min(G[x][y], w);
			}
	}
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (G[i][k] != INF && G[k][j] != INF)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		i64 ans = INF;
		for (auto x : co[u]) for (auto y : co[v]) // O(qd^2)
			ans = min(ans, G[x[0]][y[0]] + x[1] + y[1] + w[u] + w[v]);
		cout << ans << '\n';
	}
	
	return 0;
}

