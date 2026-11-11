#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5, M = 505; 
int tmp, cas, n, m, q, w[N], x, y;
vector<pii> a[N]; 
vector<pii> g[M];
int d[M][M], dis[M][M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> cas >> n >> m >> tmp >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = dis[i][j] = 0;
			else d[i][j] = dis[i][j] = 2e18;
		}
	}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, len; i <= n; i++) {
		cin >> len;
		for (int j = 1, x, t; j <= len; j++) {
			cin >> x >> t;
			for (pii e : a[x]) {
				int u = e.fi, v = e.se;
				int w = v + t;
				d[u][i] = min(d[u][i], w);
			}
			a[x].push_back({i, t});
		}
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			g[i].push_back({j, d[i][j]});
			g[j].push_back({i, d[i][j]});
		}
	}
	for (int i = 1; i <= n; i++) {
		priority_queue<pii> q;
		q.push({0, i});
		while (!q.empty()) {
			int u = q.top().se;
			q.pop();
			for (pii e : g[u]) {
				int v = e.fi, w = e.se;
				if (dis[i][u] + w < dis[i][v]) {
					dis[i][v] = dis[i][u] + w;
					q.push({-dis[i][v], v});
				}
			}
		}	
	} 
	while (q--) {
		cin >> x >> y;
		int ans = 2e18;
		for (pii l : a[x]) {
			for (pii r : a[y]) {
				ans = min(ans, l.se + r.se + w[x] + w[y] + dis[l.fi][r.fi]);
			}
		}
		cout << ans << '\n';
	}
}
