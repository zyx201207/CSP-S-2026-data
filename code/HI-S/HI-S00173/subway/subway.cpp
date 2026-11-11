// I often recall the past, For the CSP-S2026.
// WC 2027
// gcx12012, chennie, zak, TB__QGSS__423 bless me
// this problem fall my dream :(
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define inf 0x3f3f3f3f
const int M = (int)5e5 + 10;
const int N = (int)510;

int c, n, m, d, q, w[M];
struct edge {
	int v, w;
}; 
struct node {
	ll dis, u;
	bool operator()(node a, node b) {
		return a.dis > b.dis;
	}
};
vector<edge> g[N];

ll dis[N], G[N][N], dist[N][N];
bool vis[N];
void dij(int u) {
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<node, vector<node>, node> q;
	q.push((node){0, u});
	dis[u] = 0;
	while (!q.empty()) {
		node a = q.top();
		q.pop();
		if (!vis[a.u]) {
			vis[a.u] = true;
			for (auto v:g[a.u]) {
				if (dis[v.v] >= dis[a.u] + v.w) {
					dis[v.v] = dis[a.u] + v.w;
					q.push((node){dis[v.v], v.v});
				}
			}
		}
	} 
}
void solve() {
	memset(G, inf, sizeof(G));
	memset(dist, inf, sizeof(dist));
	cin >> c >> n >> m >> d >> q;
	rep (i, 1, m) {
		cin >> w[i];
	}
	rep (i, 1, n) {
		int k;
		cin >> k;
		int sum = 0;
		rep (i, 1, k) {
			int a, t;
			cin >> a >> t;
			sum += t;
			g[i].push_back((edge){a, t});
		}
	}
	rep (u, 1, n) {
//		cout << "start at " << g[u][0].v << endl;
		dij(g[u][0].v);
		rep (v, 0, m) {
			G[u][v] = dis[v];
		}
	} 
	
	rep (k, 0, m) {
		rep (i, 1, n) {
			rep (j, 1, n) {
				dist[i][j] = min(dist[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	
//	rep (i, 1, n) {
//		rep (j, 0, m) {
//			cout << G[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << w[u]+dist[u][v]+w[v] << endl;
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	 
	int T = 1;
//	cin >> t;
	while (T--) {
		solve();
	}
	return 0;
}
