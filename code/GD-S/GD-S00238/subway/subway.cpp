#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 500, M = 5e5;
constexpr LL inf = 0x3f3f3f3f3f3f3f3f;
int n, m, q;
int w[M + 5];
LL dis[N + 5][N + 5];
struct node {
	int u, t;
} a[M + 5][21];
int cnt[M + 5];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n, cin >> n >> m >> q, cin >> q;
	for (int i = 1; i <= n; i++) {
		memset(dis[i] + 1, 0x3f, n * sizeof(LL));
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int _ = 1; _ <= k; _++) {
			int u, t;
			cin >> u >> t;
			a[u][++cnt[u]] = {i, t};
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < cnt[i]; j++)
			for (int k = j + 1; k <= cnt[i]; k++) {
				int u = a[i][j].u, v = a[i][k].u, w = a[i][j].t + a[i][k].t;
				dis[u][v] = dis[v][u] = min(dis[u][v], (LL)w);
			}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int _ = 1; _ <= q; _++) {
		int u, v;
		cin >> u >> v;
		LL ans = inf;
		for (int i = 1; i <= cnt[u]; i++)
			for (int j = 1; j <= cnt[v]; j++) {
				int x = a[u][i].u, y = a[v][j].u;
				ans = min(ans, dis[x][y] + a[u][i].t + a[v][j].t);
			}
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
} 

