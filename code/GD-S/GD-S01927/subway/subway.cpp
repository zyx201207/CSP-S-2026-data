#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>

const int N = 5e5 + 10;
int c, n, m, d, q;
vector<pll> g[N];
int w[N], dis[N];
int vis[N], temp;

void dijkstra(int st) {
	memset(dis, 0x3f3f3f, sizeof dis);
	priority_queue<pll, vector<pll>, greater<pll> > q;
	dis[st] = 0;
	q.push({0, st});
	while(!q.empty()) {
		int u = q.top().second; q.pop();
		vis[u] = temp;
		for(auto &edge : g[u]) {
			int v = edge.second;
			int w = edge.first;
			if(vis[v] == temp) continue;
			vis[v] = temp;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) 
		cin >> w[i];
		
	for(int i = 1; i <= n; i ++) {
		int k; cin >> k;
		int lstv[N], lstw[N], cnt = 1;
		for(int j = 1; j <= k; j ++) {
			int v, w; cin >> v >> w;
			if(j == 1) 
				lstv[cnt] = v, lstw[cnt] = w;
			else {
				for(int u = 1; u <= cnt; u ++) {
					g[v].push_back({lstw[u] + w, lstv[u]});
					g[lstv[u]].push_back({lstw[u] + w, v});
				}
				lstv[++ cnt] = v;
				lstw[++ cnt] = w;
			}				
		}
	}
	
				
	while(q --) {
		int x, y; cin >> x >> y;
		temp ++;
		dijkstra(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	
	return 0;
}
