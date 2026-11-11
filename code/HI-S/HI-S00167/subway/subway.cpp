#include<bits/stdc++.h>
using namespace std;
#define ll long long

int const N = 5E5 + 5 + 500, inf = 1e9;
int c, m, n, d, q;//n线路数, m地铁站站数
int w[N], dis[N];
struct Node {
	int u, w;
	bool operator<(Node e) const {
		return w > e.w;
	}
};
vector<Node> g[N];
int vis[N];

int dijkstra(int x, int y, int k) {
	priority_queue<Node>q;
//	memset(vis, 0, sizeof(vis));
//	memset(dis, 0x3f, sizeof(dis));
	q.push({x, w[x]});
	int ans = -1;
	dis[x] = w[x];
	while(!q.empty()) {
		int u = q.top().u;
		q.pop();
		if(vis[u] == k) continue;
		if(u == y) ans = dis[u] + w[u];
		vis[u] = k;
		for(auto e : g[u]) {
			int v = e.u, w = e.w;
			if(vis[v] != k && dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
		dis[u] = inf;
	}
	return ans;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k, a, t;
		cin >> k;
		while(k--) {
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	} 
	for(int i = 1; i <= m + n; i++) dis[i] = inf;
	
	for(int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << dijkstra(x, y, i) << endl;
		dis[x] = dis[y] = inf;
	} 
	return 0;
}

