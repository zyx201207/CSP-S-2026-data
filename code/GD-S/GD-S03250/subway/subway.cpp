#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 1005;
const int INF = 0x3f3f3f3f;
struct Edge {
	int v, w, id1, id2;
	// 这条边到哪一个节点，花费多少钱（即是否要换乘）
	// u所在的线，v所在的线 
};
int c, n, m, d, q;
int w[M];
int a[N][M], t[N][M]; // t[线路站台编号][该地铁站的站厅号（即地铁站号）] 
int dist[2 * M][2 * M];
vector<Edge> g[2 * M], rg[2 * M]; 
// 0~m是站台，m+1~2*m是站厅 
void dijstra(int s) {
	priority_queue<pair<int, int> > pq;
	pq.push({0, s});
	dist[s][s] = 0;
	while (!pq.empty()) {
		int mindis = pq.top().first, u = pq.top().second;
		if (mindis != dist[s][u]) continue;
		
		for (auto i : g[u]) {
			int v = i.v, w = i.w;
			if (dist[s][u] > dist[s][u] + w) {
				dist[s][u] = dist[s][u] + w;
				pq.push({v, dist[s][u]}); 
			}
		}
	}
}
int main() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][a[i][j]]; // 直接记录从站台到站厅的时间;
//			g[m + i].push_back({})
			if (j >= 2) {
				g[a[i][j - 1]].push_back({a[i][j], 0, i, i});
				rg[a[i][j]].push_back({a[i][j - 1], 0, i, i});
			}
			 
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!g[i].empty() && g[i].size() > 1) {
			for (auto x : rg[i]) {
				for (auto y : g[i]) {
					if (x.id1 == y.id2) {
						g[x.v].push_back({y.v, 0, x.id2, y.id2});
					}
					else {
						g[x.v].push_back({y.v, t[x.id2][i] + t[y.id2][i], x.id2, y.id2});
					}
				}
			}
			g[i].clear();
		}
	}
//	for (int i = 1; i <= m; i++) {
//		cout << "Subway" << i << ": \n";
//		for (auto j : g[i]) {
//			cout << j.v << " " << j.w << " " << j.id1 << " " << j.id2 << " " << '\n';
//		}
//	}
	for (int i = 1; i <= m; i++) {
		memset(dist[i], INF, sizeof(dist));
		dijstra(i);
	}
	
	return 0;
} 
