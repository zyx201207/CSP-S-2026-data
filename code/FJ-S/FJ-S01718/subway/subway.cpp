#include <bits/stdc++.h>
#define inf LLONG_MAX
#define int long long

using namespace std;
const int N = 5e5 + 10;
using pII = pair < int, int>;

int k[N];
int w[N];
int c, n, m, d, q;
vector < pII> e[N]; 
vector < int> in[N]; 
// 哪些线路经过 i 这个线路到 i 需要的花费 
int dis[N];
bool vis[N];

map < int, vector < int> > mp; 
// 某条线经过哪几个点 

priority_queue < pII, vector < pII>, greater < pII> > pq;

void dij(int s, int t) {
	for (int i = 0; i < N; ++i) {
		vis[i] = false;
		dis[i] = inf;
	}
	dis[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto tmp = pq.top(); pq.pop();
		int u = tmp.second;
		if (vis[u]) continue;
		vis[u] = true;
		for (const auto &node : e[u]) {
			int w = node.second, v = node.first;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	cout << (long long)(dis[t] + w[s] + w[t]) << '\n';
	return ;
} 


signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	// A
	if (c >= 7 && c <= 11) {
		for (int i = 1; i <= m; ++i)
			cin >> w[i];
		for (int i = 1; i <= n; ++i) {
			cin >> k[i];
			if (k[i] == 2) {
				int u, wu, v, wv; cin >> u >> wu >> v >> wv;
				e[u].push_back({v, wu + wv});
				e[v].push_back({u, wu + wv});
			}
		}
		while (q--) {
			int x, y; cin >> x >> y;
			dij(x, y);
		}
		return 0;
	}
//	// B
//	if (c >= 12 && c <= 19) {
//		int T = 0; 
//		for (int i = 1; i <= m; ++i)
//		cin >> w[i];
//		for (int i = 1; i <= n; ++i) {
//			cin >> k[i];
//			for (int j = 1; j <= k[i]; ++j) {
//				int v, w; cin >> v >> w; T = w; 
//				in[v].push_back(i);
//				mp[i].push_back(v);
//			}
//		}
//		while (q--) {
//			int x, y; cin >> x >> y;
//			int ret = inf;
//			for (const auto &line : in[x]) {
//				for (int i = 1; i <= n; ++i)
//					dis[i] = inf, vis[i] = false;
//				dis[x] = 1;
//				queue < int> q;
//				q.push(x);
//				while (!q.empty()) {
//					int u = q.front(); q.pop();
//					if (vis[u]) continue;
//					vis[u] = true;
//					dis[u] = 1;
//					for (const auto &line : in[u])
//						valofl[line] = dis[u];
//					
//				}
//			}
//			cout << (long long)(w[x] + w[y] + (long long)ret * T) << '\n';
//		}
//		return 0;
//	}
}
