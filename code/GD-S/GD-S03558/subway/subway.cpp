#include <stdio.h>
#include <string.h>
#include <vector> 
#include <utility>
#include <queue>
int w[500005];
std::vector<std::pair<int, int> > g[500005];
std::vector<std::pair<int, long long> > con[500005];
std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int> >, std::greater<std::pair<long long, int> > > q;
long long dist[505], etim[505], uniq[505][505];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, Q;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &Q);
	for (int i = 1; i <= m; i++) scanf("%d", w + i);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a, t; scanf("%d %d", &a, &t);
			g[a].emplace_back(i, t);
		}
	}
	memset(uniq, -1, sizeof uniq);
	for (int i = 1; i <= m; i++) {
		for (const std::pair<int, int> temp_pair1: g[i]) {
			for (const std::pair<int, int> temp_pair2: g[i]) {
				int u = temp_pair1.first, v = temp_pair2.first;
				int tm1 = temp_pair1.second, tm2 = temp_pair2.second;
				long long w = tm1;
				w += tm2;
				if (w < uniq[u][v] || uniq[u][v] == -1) uniq[u][v] = uniq[v][u] = w; 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (uniq[i][j] != -1) {
				con[i].emplace_back(j, uniq[i][j]);
			}
		}
	}
	while (Q--) {
		int x, y; scanf("%d %d", &x, &y);
		memset(dist, 0x3c, sizeof dist);
		memset(etim, 0, sizeof etim);
		while (!q.empty()) q.pop();
		for (const std::pair<int, int> temp_pair2: g[x]) {
			int v = temp_pair2.first, tm2 = temp_pair2.second;
			dist[v] = tm2;
			q.emplace(tm2, v);
		}
		for (const std::pair<int, int> temp_pair2: g[y]) {
			int v = temp_pair2.first, tm2 = temp_pair2.second;
			etim[v] = tm2 + 1;
		}
		long long ans;
		memset(&ans, 0x3c, sizeof ans);
		while (!q.empty()) {
			long long _d = q.top().first;
			int u = q.top().second;
			q.pop();
			if (_d > dist[u]) continue;
			if (etim[u] != 0) {
				long long res = dist[u] + etim[u] - 1;
				if (res < ans) ans = res;
			}
			for (const std::pair<int, long long> temp_pair1: con[u]) {
				int v = temp_pair1.first;
				long long w = temp_pair1.second;
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					q.emplace(dist[v], v);
				}
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
} 
