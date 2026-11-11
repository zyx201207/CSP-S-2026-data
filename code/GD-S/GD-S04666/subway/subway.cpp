#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int c, n, m, d, q, w[500010];
vector<pair<int, int>> E[500010];

int dist[500510];
void bfs1(int x, int y) {
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		
		for(pair<int, int> t : E[u]) {
			int v = t.first, w = t.second;
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.push(v);
			}
		}
	}
}
int fa[500010], sz[500010];
int find(int x) {
	if(x == fa[x]) return x;
	int t = find(fa[x]);
	sz[x] += sz[fa[x]];
	fa[x] = t;
	return fa[x];
}
void merge(int x, int y, int w) {
	int fx = find(x), fy = find(y);
	if(fx == fy) {
		if(sz[x] + w < sz[y]) {
			sz[y] = sz[fx] + w;
			fa[y] = fx;
		}else {
			sz[x] = sz[fy] + w;
			fa[x] = fy;
		}
	} else {
		fa[fx] = fy;
		sz[fx] += sz[fy] + w;
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q; 
	for(int i = 1; i <= n + m; i++) fa[i] = i, sz[i] = 0;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int x, y; cin >> x >> y;
			E[x].push_back({i + m, y});
			E[i + m].push_back({x, y});
			merge(x, i + m, y);
		}
	}
	
	if(c <= 6) {
		while(q--) {
			memset(dist, 0x7f, sizeof dist);
			int x, y; cin >> x >> y; 
			bfs1(x, y);
			cout << dist[y] + w[x] + w[y] << "\n";
		}
		return 0;
	}
	while(q--) {
		int x, y; cin >> x >> y;
		cout << sz[x] + sz[y] << "\n";
	}
//	else if(c <= 21) {
//		
//		return 0;
//	}else if(c <= 23) {
//		
//		return 0;
//	}
	
	return 0;
} 
