#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
bool vis[N];
struct edge{
	int v, w; 
};
vector<edge> g[N];
ll dis[N], dis2[N], dis3[N], a[N];
struct node {
	ll u, dis;
	bool operator > (const node &other) const {
		return dis > other.dis;
	}
};
void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(dis2, 0x3f, sizeof dis2);
	memset(dis3, 0x3f, sizeof dis3);
	memset(vis, false, sizeof vis);
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (edge ed : g[u]) {
			int v = ed.v, w = ed.w;
			if (dis[v] > dis[u] + w) {
				if (dis2[v] > dis[v]) {
					dis3[v] = dis2[v];
					dis2[v] = dis[v];
				}
				else dis3[v] = dis[v];
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			} else {
				if (dis2[v] > dis[u] + w) {
					dis3[v] = dis2[v];
					dis2[v] = dis[u] + w;
				} else dis3[v] = dis[u] + w;
				if (dis2[u] + w < dis2[v]) {
					dis2[v] = dis2[u] + w;
				} else dis3[v] = min(dis3[v], dis2[u] + w);
				dis3[v] = min(dis3[v], dis3[u] + w);
			}
			
			//cout << u << " " << v << " " << dis[u] << " " << dis2[u] << " " << dis[v] << " " << dis2[v] << '\n';
		}
	}
}
signed main() {
//	system("fc my.out subway5.ans");
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(a[i] - a[j]) <= d) {
					g[i].push_back({j, 1}), g[j].push_back({i, 1});
				}
			}
		}
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
			for (int j = i + 1; j <= n; j++) {
				//if (i == 5 && j == 1) cout << i << " " << j << " " << dis[j] << " " << dis2[j] << " " << dis3[j] << '\n';
				// 
				if (i != j && dis[j] == dis2[j] && dis[j] != 0x3f3f3f3f3f3f3f3f && dis[j] != dis3[j]) {
//					cout << i << " " << j << " " << dis[j] << " " << dis2[j] << " " << dis3[j] << '\n';
					 
					sum++;
				}
			}
		}
		cout << sum << '\n';
		for (int i = 1; i <= n; i++) g[i].clear();
	}
//	for (int i = 1; i <= T; i++) {
//		int u, v, w;
//		cin >> u >>v >> w;
//		g[u].push_back({v, w}); g[v].push_back({u, w});
//	}
//	dijkstra(1);
//	cout << dis[5] << " " <<dis2[5] << " " << dis3[5]; 
	return 0;
}
/*
0 1
6 3
0 1 2 3 4 7

*/


