#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;
bool Bflag = true;
int c, n, m, d, q, top;
int k[501], w[20001], head[10100001], a[501][20001], t[501][50001];
struct Edgenode {
	int nxt, to, wt;
} edge[80001];
inline void add(int u, int v, int w) {
	edge[++top] = {head[u], v, w}, head[u] = top;
	edge[++top] = {head[v], u, w}, head[v] = top;
}
int Dijkstra(int st, int ed) {
	priority_queue< PII, vector<PII>, greater<PII> > pq;
	vector<int> dis(((Bflag) ? 2 : n + 1) * m + 1, 1e18);
	vector<bool> vis(((Bflag) ? 2 : n + 1) * m + 1, false);
	pq.push({0, st}), dis[st] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to, w = edge[i].wt;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) pq.push({dis[v], v});
			}
		}
	}
	return dis[ed];
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if (i > 1 && j > 1 && t[i][j] != t[i - 1][j] || t[i][j] != t[i][j - 1])
				Bflag = false;
		}
	}
	if (Bflag) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				add(a[i][j], a[i][j] + m, t[i][j]);
				if (j > 1)
					add(a[i][j] + m, a[i][j - 1] + m, 0);
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				add(a[i][j], a[i][j] + i * m, t[i][j]);
				if (j > 1)
					add(a[i][j] + i * m, a[i][j - 1] + i * m, 0);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + Dijkstra(x, y) + w[y] << '\n';
	}
	return 0;
}
 
