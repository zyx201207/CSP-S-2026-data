#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 5e2 + 5, M = 5e5 + 5, D = 25, Q = 1e5 + 5, INF = 1e18;

struct To {
	ll v, w;
};

ll c, n, m, d, q;
ll w[M], f[N][N];
vector<To> g[M];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (ll j = 1, a, t; j <= k; j++) {
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	// 对线路建图 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			f[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (To x : g[i]) {
			for (To y : g[i]) {
				if (x.v == y.v) continue;
				f[x.v][y.v] = min(f[x.v][y.v], x.w + y.w);
				f[y.v][x.v] = min(f[y.v][x.v], x.w + y.w);
			}
		}
	}
	// floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		ll ans = INF;
		for (To tx : g[x]) {
			for (To ty : g[y]) {
				ans = min(ans, f[tx.v][ty.v] + tx.w + ty.w);
			} 
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
/**
三年了，终于  T_T 
*/

