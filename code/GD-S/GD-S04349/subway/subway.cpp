#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], k[505];
vector<int> t[505];
vector<pair<int, int> > g[500005], f[600005], e[505];
long long dis[600005], ans[505][505];
bool vis[600005];
priority_queue<pair<int, int> > pq;
queue<int> bfsq;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		cin >> k[i];
		sum += k[i];
		for (int j = 0;j < k[i];j++) {
			int x, y;
			cin >> x >> y;
			t[i].push_back(y);
			g[x].push_back({i, j});
			f[i].push_back({n + x, y});
			f[n + x].push_back({i, y});
		}
	}
	if (sum <= 20000) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n + m;j++) {
				dis[j] = 1e18;
				vis[j] = 0;
			}
			dis[i] = 0;
			pq.push({0, i});
			while (!pq.empty()) {
				int u = pq.top().second;
				pq.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (int j = 0;j < f[u].size();j++) {
					int v = f[u][j].first;
					if (dis[v] > dis[u] + f[u][j].second) {
						dis[v] = dis[u] + f[u][j].second;
						pq.push({-dis[v], v});
					}
				}
			}
			for (int j = 1;j <= n;j++) {
				ans[i][j] = dis[j];
			}
		}
	}
	else if (min(n, d) <= 2) {
		for (int i = 1;i <= m;i++) {
			if (g[i].size() == 2) {
				int u = g[i][0].first, v = g[i][1].first;
				int idu = g[i][0].second, idv = g[i][1].second;
				e[u].push_back({v, t[u][idu] + t[v][idv]});
				e[v].push_back({u, t[u][idu] + t[v][idv]});
			}
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				dis[j] = 1e18;
				vis[j] = 0;
			}
			dis[i] = 0;
			pq.push({0, i});
			while (!pq.empty()) {
				int u = pq.top().second;
				pq.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (int j = 0;j < e[u].size();j++) {
					int v = e[u][j].first;
					if (dis[v] > dis[u] + e[u][j].second) {
						dis[v] = dis[u] + e[u][j].second;
						pq.push({-dis[v], v});
					}
				}
			}
			for (int j = 1;j <= n;j++) {
				ans[i][j] = dis[j];
			}
		}
	}
	else {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n + m;j++) {
				dis[j] = 1e18;
			}
			dis[i] = 0;
			bfsq.push(i);
			while (!bfsq.empty()) {
				int u = bfsq.front();
				bfsq.pop();
				for (int j = 0;j < f[u].size();j++) {
					int v = f[u][j].first;
					if (dis[v] > dis[u] + f[u][j].second) {
						dis[v] = dis[u] + f[u][j].second;
						bfsq.push(v);
					}
				}
			}
			for (int j = 1;j <= n;j++) {
				ans[i][j] = dis[j];
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		long long val = 1e18;
		for (int i = 0;i < g[x].size();i++) {
			for (int j = 0;j < g[y].size();j++) {
				int u = g[x][i].first, v = g[y][j].first;
				int idu = g[x][i].second, idv = g[y][j].second;
				val = min(val, ans[u][v] + w[x] + w[y] + t[u][idu] + t[v][idv]);
			}
		}
		cout << val << '\n';
	}
	return 0;
}
