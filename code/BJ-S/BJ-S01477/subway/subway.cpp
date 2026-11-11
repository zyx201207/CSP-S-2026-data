#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 2;
int c, n, m, d, q, w[N];
int k, a[N], t[N];
vector < pair <int, long long> > g[N * 20];
priority_queue <pair <long long, int> > pq;
long long dis[N];
long long ddd[N][N];
bool vis[N];
long long Dij(int x, int y) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[x] = 0;
	pq.push({-0, x});
	while(!pq.empty()) {
		int u = pq.top().second;
		// cout << "u:" << u << endl;
		pq.pop();
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(auto [v, w] : g[u]) {
			// cout << "dis[u]:" << dis[u] 
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				// cout << "v:" << v << " w:" << w << endl;
				// cout << "dis[v]:" << dis[v] << endl;
				pq.push({-dis[v], v});
			}
		}
	}
	return dis[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for(int st = 1; st <= k; st++) {
			for(int en = st + 1; en <= k; en++) {
				g[a[st]].push_back({a[en], t[st] + t[en]});
				g[a[en]].push_back({a[st], t[st] + t[en]});
			}
		}
	}
	/*/cout << "g:" << endl;
	for(int u = 1; u <= m; u++) {
		for(auto [v, w] : g[u]) {
			cout << u << " " << v << " " << w << endl;
		}
	}/*/
	if(7 <= c && c <= 11) {
		for(int i = 1; i <= m; i++) {
			Dij(i, 1);
			for(int j = 1; j <= m; j++) {
				ddd[i][j] = dis[j];
			}
		}
		int x, y;
		for(int i = 1; i <= q; i++) {
			cin >> x >> y;
			cout << w[x] + w[y] + ddd[x][y] << "\n";
		}
		return 0;
	}
	int x, y;
	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << w[x] + w[y] + Dij(x, y) << "\n";
	}
	return 0;
}