#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 550, M = 50050;
struct edge{
	int v, id;
};
vector<edge> e[M];
int c, n, m, d, q, w[M], t[N][M], dist[M], vis[M];
queue<edge> qq;
int main () {
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) 
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int v = 0;
		for (int j = 1; j <= k; j++) {
			int u;
			cin >> u;
			cin >> t[i][u];
			if (v) {
				e[u].push_back({v, i});
				e[v].push_back({u, i});
			}
			v = u; 
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		memset(dist, 127, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		dist[x] = w[x];
		qq.push({x, 0});
		while (!qq.empty()) {
			int u = qq.front().v, id = qq.front().id;
			qq.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto v : e[u]) {
				int to = v.v, id2 = v.id;
				if (dist[u] + t[id][u] + t[id2][u] < dist[to]) {
					dist[to] = dist[u] + t[id][u] + t[id2][u];
					qq.push({to, id2});
				}
			}
		}
		cout << dist[y] + w[y] << endl;
	}
	//fclose(stdin); 
	//fclose(stdout);
	return 0;
} 
