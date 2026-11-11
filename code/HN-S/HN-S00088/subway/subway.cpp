#include <bits/stdc++.h>
#define pli pair <long long, int>
using namespace std;
const int M = 5e5 + 10;
int c, n, m, d, q;
int pt[M]; // 每个点作为起点/终点的花费
int v[M], w[M];
vector <pair <int, int>> edge[M];
// 从i到edge[i][j].first有一条边权为edge[i][j].second的边,编号为j
long long dist[M];
bool vis[M];
void dijkstra(int st, int ed) {
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));
	priority_queue <pli, vector <pli>, greater <pli>> pq; // st到pq.second的最小距离为pq.first
	dist[st] = 0;
	pq.emplace(0, st);
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		if (vis[x.second]) continue;
		vis[x.second] = true;
		for (auto it : edge[x.second]) {
			int to = it.first, w = it.second;
		//	cout << x.second << ' ' << to << ' ' << w << '\n';
		//	cout << to << ' ' << dist[x.second] + w << "\n\n";
			if (dist[to] > dist[x.second] + w) {
				dist[to] = dist[x.second] + w;
				pq.emplace(dist[to], to);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) cin >> pt[i];
	for (int i=1; i<=n; i++) {
		int k; cin >> k;
		for (int i=1; i<=k; i++) cin >> v[i] >> w[i];
		for (int i=1; i<=k; i++)
			for (int j=1; j<=k; j++) {
				if (i == j) continue;
				edge[v[i]].push_back({v[j], w[i] + w[j]});
			}
	}
	for (int i=1; i<=q; i++) {
		int st, ed;
		cin >> st >> ed;
		dijkstra(st, ed);
	//	for (int i=1; i<=m; i++) cout << dist[i] << ' ';
		cout << dist[ed] + pt[st] + pt[ed] << '\n';
	//	cout << "\n\n";
	}
//	for (int i=1; i<=m; i++) {
//		for (int j=0; j<edge[i].size(); j++)
//			cout << i << "->" << edge[i][j].first << ": " << edge[i][j].second << '\n';
//		cout << '\n';
//	}
	return 0;
}
