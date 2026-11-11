#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 510, M = 5e5 + 10;
int C, n, m, d, Q, w[M];
struct edge {
	int to, w;
};
vector<edge> g[N + M];
int sq_g[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> C >> n >> m >> d >> Q;
	rep(i, 1, m) {
		cin >> w[i];
	}
	rep(i, 1, n) {
		int k;
		cin >> k;
		rep(j, 1, k) {
			int a, t;
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	memset(sq_g, 0x3f, sizeof(sq_g));
	rep(i, 1, m) {
		const int sz = g[i].size();
		rep(j, 0, sz - 1) {
			rep(k, j + 1, sz - 1) {
				const auto [u, w1] = g[i][j];
				const auto [v, w2] = g[i][k];
				sq_g[u - m][v - m] = min(sq_g[u - m][v - m], w1 + w2);
				sq_g[v - m][u - m] = sq_g[u - m][v - m];
			}
		}
	}
	rep(i, 1, n) {
		sq_g[i][i] = 0;
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				sq_g[i][j] = min(sq_g[i][j], sq_g[i][k] + sq_g[k][j]);
			}
		}
	}
	while (Q --) {
		int x, y;
		cin >> x >> y;
		int ans = LONG_LONG_MAX;
		for (const auto [u, w1] : g[x]) {
			for (const auto [v, w2] : g[y]) {
				ans = min(ans, w[x] + w[y] + w1 + w2 + sq_g[u - m][v - m]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
