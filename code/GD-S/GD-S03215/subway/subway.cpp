#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;

int c, n, m, d, q, s[N], w[N], a[N][25], b[N][25], dis[505][505];

void chkmn(int u, int v, int w) {
	dis[u][v] = dis[v][u] = min(dis[u][v], w);
}

void Floyed() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= n; ++j)
			dis[i][j] = 1e18;
		dis[i][i] = 0;
		for (int j = 1, u, t; j <= k; ++j)
			cin >> u >> t, a[u][++s[u]] = i, b[u][s[u]] = t;
	}
	for (int u = 1; u <= m; ++u) {
		for (int i = 1; i <= s[u]; ++i) {
			for (int j = i+1; j <= s[u]; ++j)
				chkmn(a[u][i], a[u][j], b[u][i] + b[u][j]);
		}
	}
	Floyed();
	while (q--) {
		int u, v;
		long long ans = 1e18;
		cin >> u >> v;
		for (int i = 1; i <= s[u]; ++i) {
			for (int j = 1; j <= s[v]; ++j)
				ans = min(ans, b[u][i] + b[v][j] + dis[a[u][i]][a[v][j]]);
		}
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}
