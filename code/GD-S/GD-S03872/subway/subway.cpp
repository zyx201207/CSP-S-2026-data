#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 505, M = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> g[M];
int c, n, m, d, q, w[M], dis[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)  cin >> w[i];
	for(int i = 1, k, v, t; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> v >> t;
			g[v].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++)  dis[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		for(int x = 0; x < g[i].size(); x++) {
			for(int y = x + 1; y < g[i].size(); y++) {
				pair<int, int> u = g[i][x], v = g[i][y];
				dis[u.fi][v.fi] = min(dis[u.fi][v.fi], u.se + v.se);
				dis[v.fi][u.fi] = min(dis[v.fi][u.fi], v.se + u.se);
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dis[i][k] == INF || dis[k][j] == INF)  continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1, s, t, ans; i <= q; i++) {
		cin >> s >> t;
		ans = INF;
		for(int x = 0; x < g[s].size(); x++) {
			for(int y = 0; y < g[t].size(); y++) {
				pair<int, int> u = g[s][x], v = g[t][y];
				ans = min(ans, dis[u.fi][v.fi] + u.se + v.se);
			}
		}
		ans += w[s] + w[t];
		cout << ans << '\n';
	}
	return 0;
}
