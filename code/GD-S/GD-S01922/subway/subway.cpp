#include <bits/stdc++.h>
using namespace std;
int c, n, m, e, test;
int w[500 * 500 + 100], k[510], a[510][510], t[510][510], d[510][510], dist[510], q[510];
vector<int> edges[510], v[500 * 500 + 100];
vector<pair<int, int>> ed[510], val[500 * 500 + 100];
map<int, int> que;
int bfs(int u, int v) {
	if (d[u][v] != -1)
		return d[u][v];
	if (d[v][u] != -1)
		return d[v][u];
	int start = 1, rear = 0;
	q[++rear] = u;
	memset(dist, 255, sizeof(dist));
	dist[u] = 0;
	while (start <= rear) {
		int x = q[start++];
		for (auto y : edges[x]) {
			if (dist[y] != -1)
				continue;
			q[++rear] = y;
			dist[y] = dist[x] + 1;
		}
		if (dist[v] != -1)
			break;
	}
	d[u][v] = dist[v];
	d[v][u] = dist[u];
	return dist[v];
}
int bfs_plus(int u, int v) {
	if (d[u][v] != -1)
		return d[u][v];
	if (d[v][u] != -1)
		return d[v][u];
	int start = 1, rear = 0;
	que.insert({0, u});
	rear++;
	memset(dist, 127, sizeof(dist));
	int inf = 2e9;
	dist[u] = 0;
	while (start <= rear) {
		auto x = que.begin();
		start++;
		que.erase(x->first);
		for (auto y : ed[x->first]) {
			if (dist[y.first] > dist[x->first] + y.second)
				continue;
			que.insert({dist[x->first] + y.second, y.first});
			rear++;
			dist[y.first] = dist[x->first] + y.second;
		}
	}
	d[u][v] = dist[v];
	d[v][u] = dist[u];
	return dist[v];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(d, 255, sizeof(d));
	scanf("%d%d%d%d%d", &c, &n, &m, &e, &test);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
			v[a[i][j]].push_back(i);
			val[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto y : v[i]) {
			for (auto x : v[i]) {
				if (y == x)
					continue;
				edges[x].push_back(y);
			}
		}
		int len = val[i].size();
		for (int y = 0; y < len; y++)
			for (int x = 0; x < len; x++) {
				if (y == x)
					continue;
				ed[val[i][x].first].push_back({val[i][y].first, val[i][x].second + val[i][y].second});
			}
	}
	int T = t[1][1];
	for (int i = 1; i <= test; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = w[x] + w[y], cnt = 2e9;
		for (auto q : v[x]) {
			for (auto p : v[y]) {
				if (12 <= c && c <= 19)
					cnt = min(cnt, bfs(q, p) + 1);
				else
					cnt = min(cnt, bfs_plus(q, p) + 1);
			}
		}
		ans += (cnt * 2 * T);
		printf("%d\n", ans);
	}
	return 0;
}
