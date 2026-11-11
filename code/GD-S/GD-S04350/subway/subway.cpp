#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510, M = 5e5 + 10;
int w[M], k[N], dis[N][N];
vector<pair<int, int>> a[N], v[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x, y;
			cin >> x >> y;
			a[i].push_back({x, y});
			v[x].push_back({i, y});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		for (auto x : a[i]) {
			for (auto y : v[x.first]) {
				dis[i][y.first] = min(dis[i][y.first], x.second + y.second);
			}
		}
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y, ans = 1e18;
		cin >> x >> y;
		for (auto l : v[x]) {
			for (auto r : v[y]) {
				ans = min(ans, dis[l.first][r.first] + l.second + r.second);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
