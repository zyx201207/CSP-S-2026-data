#include <bits/stdc++.h>
#define int long long
#define pir pair < int, int >
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[N];
int dis[N];
int vis[N];
vector < pir > g[N];
void dij(int s) {
	for(int i=0; i<=1e5; i++) vis[i] = 0, dis[i] = 1e18;
	priority_queue < pir, vector < pir >, greater < pir > > q;
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto x : g[u]) {
			int v = x.first;
			int w = x.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

int a[N], t[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin >> k;
		for(int j=1; j<=k; j++) cin >> a[j] >> t[j];
		for(int j=1; j<=k; j++) {
			for(int c=k; c>=1; c--) {
				if(j == c) continue;
				else g[a[j]].push_back({a[c], t[j] + t[c]}), g[a[c]].push_back({a[j], t[j] + t[c]});
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << w[x] + w[y] + dis[y] << '\n';
	}
	return 0;
}
