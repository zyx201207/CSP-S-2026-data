#include<bits/stdc++.h>
using namespace std;
/*
AC at 15:51
O(n^3 + dq^2)
*/
#define N 505
#define M 500005
#define int long long
#define INF LLONG_MAX
struct node {
	int v, w;
};
int c, n, m, d, q, w[M], f[N][N];
vector<node> g[N + M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, v, t; j <= k; j++) {
			cin >> v >> t;
			g[m + i].push_back({v, t});
			g[v].push_back({m + i, t});
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) {
		int u, w, v, ww;
		f[i][i] = 0;
		for (auto ed : g[m + i]) {
			u = ed.v, w = ed.w;
			for (auto ed : g[u]) {
				v = ed.v, ww = ed.w;
				if (i == v) continue;
//				cout << i + m << " " << u << " " << w << "   " << u << " " << v << " " << ww << "\n";
				f[i][v - m] = f[v - m][i] = min(f[i][v - m], w + ww);
			}
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1, x, y, ans; i <= q; i++) {
		cin >> x >> y;
		ans = INF;
		for (auto ed : g[x])
			for (auto ee : g[y]) ans = min(ans, f[ed.v - m][ee.v - m] + ed.w + ee.w);
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
