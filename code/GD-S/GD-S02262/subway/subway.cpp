#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int c, n, m, d, q, w[500005];
vector<int> a[505], t[505];
vector<long long> dis;
vector<bool> vis;
const long long inf = 1ll << 62;
struct Node {
	int v, w;
};
struct Edge {
	int v;
	long long w;
	bool operator < (const Edge& A) const {
		return w > A.w;
	}
};
vector<vector<Node> > g;
priority_queue<Edge> que;
long long Dijkstra(int st, int ed) {
	dis.resize(n * m + 5, inf);
	vis.resize(n * m + 5, 0);
	dis[st] = 0;
	que.push({st, 0});
	while (!que.empty()) {
		int u = que.top().v;
		long long d = que.top().w;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (auto i : g[u]) {
			if (d + i.w < dis[i.v]) {
				dis[i.v] = d + i.w;
				que.push({i.v, d + i.w});
			}
		}
	}
	long long ans = inf;
	for (int i = 0; i < n; i++)
		ans = min(ans, dis[ed + i * m] + t[i][ed]);
	return ans;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	g.resize(n * m + 5);
	
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int aa, tt;
			scanf("%d%d", &aa, &tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
		for (int j = 1; j < k; j++) {
			g[a[i][j] + i * m].push_back({a[i][j - 1] + i * m, 0});
			g[a[i][j - 1] + i * m].push_back({a[i][j] + i * m, 0});
			for (int l = 0; l < n; l++)
				if (l != i) {
					g[a[i][j] + l * m].push_back({a[i][j - 1] + l * m, t[i][j] + t[i][j - 1]});
					g[a[i][j - 1] + l * m].push_back({a[i][j] + l * m, t[i][j] + t[i][j - 1]});
				}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = inf;
		for (int j = 0; j < n; j++)
			ans = min(ans, Dijkstra(x + j * m, y) + t[j][x]);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
