#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e2 + 5;
const int M = 1e3 + 5;
const int D = 20;
const ll INF = 4e18;

int c, n, m, d, q;

int ous[M];

bool vis[M][N];
ll dist[M][N];

struct Sub {
	int id, w;
};
struct Edge {
	int v, lin_id, w;
};
struct Node {
	int u, lin_id;
	ll w;
	bool operator < (const Node &x) const {
		return w > x.w;
	}
};
vector<Sub> sub_line[M];
vector<Edge> g[M][N];

void Dijkstra(int s, int sid) {
	
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	
	priority_queue <Node> qu;
	qu.push({s, sid, 0});
	dist[s][sid] = 0; 
	
	while (!qu.empty()) {
		int u = qu.top().u;
		int idu = qu.top().lin_id;
		qu.pop();
		 
		if (vis[u][idu]) continue;
		vis[u][idu] = 1;
		
		for (auto e : g[u][idu]) {
			int v = e.v, idv = e.lin_id, w = e.w;
			
			if (dist[v][idv] > dist[u][idu] + w) {
				dist[v][idv] = dist[u][idu] + w;
				qu.push({v, idv, dist[v][idv]});
			}
		}
	}
	 
}
int main() {
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;	
	for (int i = 1; i <= m; i++) {
		cin >> ous[i];
	}
	
	for (int i = 1; i <= n; i++) {		
		int p, t, x;
		cin >> p;
		
		for (int j = 1; j <= p; j++) {
			
			cin >> x >> t;
			
			sub_line[x].push_back({i, t});
			g[x][i].push_back({0, i, 0});
			g[0][i].push_back({x, i, 0});
		}
		
	}
	
	for (int i = 1; i <= m; i++) {
		int cnt = sub_line[i].size();
		 
		for (int j = 0; j < cnt; j++) {
			
			int id = sub_line[i][j].id;
			int w = sub_line[i][j].w;
			g[i][id].push_back({i, 0, w});
			g[i][0].push_back({i, id, w});
				
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		
		Dijkstra(x, 0);
		ans = dist[y][0] + ous[x] + ous[y];
		
		cout << ans << "\n";
	}
}
