//孙宇宸 GZ-S00248 贵阳市华师一学校 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr ll INF = 1ll << 61;
constexpr int N = 500 + 1;

ll l2l[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	vector<vector<pii>> adj(m + 1);
	for (int i = 1; i <= n; ++i) {
		fill(l2l[i] + 1, l2l[i] + n + 1, INF);
		l2l[i][i] = 0;
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int a, t;
			cin >> a >> t;
			adj[a].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			int v1 = adj[i][j].first, w1 = adj[i][j].second;
			for (int k = j + 1; k < adj[i].size(); ++k) {
				int v2 = adj[i][k].first, w2 = adj[i][k].second;
				l2l[v1][v2] = min(l2l[v1][v2], (ll)w1 + w2);
				l2l[v2][v1] = min(l2l[v2][v1], (ll)w1 + w2);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				l2l[i][j] = min(l2l[i][j], l2l[i][k] + l2l[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		for (auto i : adj[x]) {
			for (auto j : adj[y]) {
				ans = min(ans, i.second + j.second + l2l[i.first][j.first]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
