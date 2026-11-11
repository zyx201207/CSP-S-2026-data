#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, Q, w[N], k[N];
int dis[N], ans[1010][1010];
bool vis[N];
queue<int> q;
vector<pair<int,int> > g[N];
void dijkstra(int x) {
	memset(dis, 0x3f, sizeof(dis));
	dis[x] = 0; q.push(x); vis[x] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for(int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first;
			int w = g[u][i].second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					q.push(v); vis[v] = 1;
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		int u = m + i;
		for(int j = 1; j <= k[i]; j++) {
			int v, w;
			cin >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	if(m <= 1000) {
		for(int i = 1; i <= m; i++) {
			dijkstra(i);
			for(int j = 1; j <= m; j++) {
				ans[i][j] = dis[j];
			}
		}
		while(Q--) {
			int x, y;
			cin >> x >> y;
			cout << w[x] + ans[x][y] + w[y] << '\n';
		}
	}else {
		while(Q--) {
			int x, y;
			cin >> x >> y;
			dijkstra(x);
			cout << w[x] + dis[y] + w[y] << '\n';
		}
	}
	return 0;
} 
