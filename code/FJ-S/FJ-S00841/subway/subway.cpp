#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, M = 5e5 + 5;
const ll inf = 4e18;

int c, n, m, d, q, w[M];
ll ans;
vector<pair<int, int>> g[M];
ll dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 1, a, t; j <= k; ++j) {
			cin >> a >> t;
			g[a].push_back(make_pair(i, t));
		}
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (pair<int, int> to1 : g[i]) {
			int u = to1.first, t1 = to1.second;
			for (pair<int, int> to2 : g[i]) {
				int v = to2.first, t2 = to2.second;
				if (u == v) continue;
				dis[u][v] = t1 + t2;
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int x, y; q--;) {
		cin >> x >> y;
		ans = inf;
		for (pair<int, int> to1 : g[x]) {
			int u = to1.first, t1 = to1.second;
			for (pair<int, int> to2 : g[y]) {
				int v = to2.first, t2 = to2.second;
				ans = min(ans, 1ll * t1 + t2 + dis[u][v]);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
