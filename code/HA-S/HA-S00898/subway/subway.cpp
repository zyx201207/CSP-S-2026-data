#include <bits/stdc++.h>

using namespace std;
constexpr int N = 510, M = 5e5 + 10;
using ll = long long;
ll idid, n, m, d, q, w[M], c[N][N];
vector<pair<int, ll>> e[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	memset(c, 0x3f, sizeof c);
	cin >> idid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	vector<vector<pair<int, ll>>> a(n + 10);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int p; ll t;
			cin >> p >> t;
			a[i].push_back(make_pair(p, t));
			e[p].push_back(make_pair(i, t));
		}
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int x = 0, y = 0;
			while (x < (int) a[i].size() && y < (int) a[j].size()) {
				if (a[i][x].first == a[j][y].first) {
					c[j][i] = c[i][j] = min(c[i][j], (ll) a[i][x].second + (ll) a[j][y].second);
					++x; ++y;
				} else if (a[i][x].first < a[j][y].first) {
					++x;
				} else ++y;
			}
		}
	}
	for (int i = 1; i <= n; i++) c[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}
	while (q--) {
		int s, t;
		ll ans = 0x3f3f3f3f3f3f3f3fll;
		cin >> s >> t;
		if (s == t) {
			cout << 0 << '\n';
			continue;
		}
		for (auto& x : e[s]) {
			for (auto& y : e[t]) {
				ans = min(ans, c[x.first][y.first] + x.second + y.second);
			}
		}
		ans += w[s] + w[t];
		cout << ans << '\n';
	}
	return 0;
}
