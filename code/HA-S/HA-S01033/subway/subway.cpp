#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int INF = 1e10;
vector<long long> zhant;
vector< pair<int, long long> > g[MAXN];
int vis[MAXN];
long long dis[MAXN];
int c, n, m, d, q;

long long dijkstra(int a, int b) {
	
	memset(dis, INF, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
	dis[a] = 0;
	pq.push({0, a});
	
	while(!pq.empty()) {
		long long d = pq.top().first;int u = pq.top().second;
		pq.pop();
		
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(int i = 0;i < g[u].size();i++);
		{
			if(dis[u] + d < dis[g[u][i].first]) {
				dis[g[u][i].first] = dis[u] + d;
				pq.push({dis[g[u][i].first], g[u][i].first});
			}
		}
	}
	
	
	return dis[b];
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	zhant.resize(m);
	for(int i = 0;i < m;i++) cin >> zhant[i];
	for(int i = 0;i < n;i++) {
		int k;
		cin >> k;
		for(int j = 0;j < k;j++) {
			int v, w;
			cin >> v >> w;
			g[i].push_back({v, w});
			g[v].push_back({i, w});
		}
	}
	
	for(;q > 0;q--) {
		int x, y;
		cin >> x >> y;
		long long ans = zhant[x - 1] + zhant[y - 1];
		ans += dijkstra(x, y);
		cout << ans << endl;
	}
	
	
	return 0;
}
