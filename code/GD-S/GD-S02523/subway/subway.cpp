#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 5e5 + 505;
const int INF = 1e18;
int c, n, m, d, q;
int w[M];
//			id   dis
vector<pair<int, int>> g[M];

//int dis[M];
//bool vis[M];
//void dij(int start, int end) {
//	memset(dis, 0x3f, sizeof dis);
//	memset(vis, 0, sizeof vis);
//	dis[start] = 0;
//	//			    	dis  id
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	pq.push({0, start});
//	while(!pq.empty()) {
//		auto [d, u] = pq.top();
//		pq.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		if (u == end) return;
//		for (const auto & [v, len] : g[u]) {
//			if (dis[u] + len < dis[v]) {
//				dis[v] = dis[u] + len;
//				pq.push({dis[v], v});
//			} 
//		}
//	}
//}

int dp[505][505];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dp, 0x3f, sizeof dp);			//4557430888798830399
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, id, t; j <= k; j++) {
			cin >> id >> t;
			g[i].push_back({n + id, t});
			for (const auto & [lid, ti] : g[n + id]) {
				dp[i][lid] = min(dp[i][lid], t + ti);
				dp[lid][i] = dp[i][lid];
			}
			g[n + id].push_back({i, t});
		}
		dp[i][i] = 0;
	}	//node[1, n]为线路节点[n + 1, n + m]为站厅节点 
	
//	for (int i = 1, x, y; i <= q; i++) {
//		cin >> x >> y;
//		dij(n + x, n + y);
//		int ans = w[x] + dis[n + y] + w[y];
//		cout << ans << endl;
//	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] > INF || dp[k][j] > INF) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		int ans = INF;
		for (const auto & [xdt, xt] : g[n + x]) {
			for (const auto & [ydt, yt] : g[n + y]) {
				ans = min(ans, w[x] + xt + dp[xdt][ydt] + yt + w[y]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
