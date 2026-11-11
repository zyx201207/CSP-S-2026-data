#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace Creeper{
	const int N = 505, M = 5e5 + 5;
	int c, n, m, d, q, w[M], f[N][N], k[N];
	vector<pair<int, int>> t[M];
	void solve() {
		cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= m; i++) cin >> w[i];
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				int x, y;
				cin >> x >> y;
				t[x].push_back({i, y});
			}
		}
		memset(f, 0x3f, sizeof(f));
		for (int i = 1; i <= n; i++) f[i][i] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < t[i].size(); j++) {
				for (int k = j + 1; k < t[i].size(); k++) {
					int u = t[i][j].first, v = t[i][k].first;
					f[u][v] = min(f[u][v], t[i][j].second + t[i][k].second);
					f[v][u] = min(f[v][u], t[i][j].second + t[i][k].second);
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
		while (q--) {
			int x, y, ans = LLONG_MAX;
			cin >> x >> y;
			for (int i = 0; i < t[x].size(); i++) {
				for (int j = 0; j < t[y].size(); j++) {
					ans = min(ans, f[t[x][i].first][t[y][j].first] + t[x][i].second + t[y][j].second);
				}
			}
			cout << ans + w[x] + w[y] << '\n';
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) Creeper::solve();
}
