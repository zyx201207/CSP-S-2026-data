#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 505, M = 5e5 + 5;

int c, n, m, d, q; ll w[M];
vector<pair<int, ll>> pass[M];

ll dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int p, x; cin >> p >> x;
			pass[p].push_back({i, x});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < pass[i].size(); ++j) {
			for (int k = 0; k < pass[i].size(); ++k) {
				int p1 = pass[i][j].first, p2 = pass[i][k].first;
				dis[p1][p2] = min(dis[p1][p2], pass[i][j].second + pass[i][k].second);
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
	while (q--) {
		int x, y; cin >> x >> y;
		ll Mn = 0x3f3f3f3f3f3f3f3f;
		for (auto s1 : pass[x]) {
			for (auto s2 : pass[y]) {
				Mn = min(Mn, s1.second + dis[s1.first][s2.first] + s2.second);
				// cout << s1.first << ' ' << s2.first << ' ' << dis[s1.first][s2.first] << ' ' << s1.second << ' ' << s2.second << '\n';
			}
		}
		cout << w[x] + w[y] + Mn << '\n';
	}
}
