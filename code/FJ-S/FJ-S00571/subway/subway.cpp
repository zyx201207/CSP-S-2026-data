#include<bits/stdc++.h>
#define int long long
using namespace std;

const int max_n = 1e6 + 5;
const int max_m = 2000 + 5;

int c, n, m, d, q;
int w[max_n], f[max_m][max_m];

struct Node{
	int v, w, nxt;
}e[max_n];

int h[max_n], idx = 0;

inline void add(int u, int v, int w) {
	e[++idx] = (Node){v, w, h[u]};
	h[u] = idx;
}

int dis[max_n], vis[max_n];

inline int dj(int s, int t) {
	for (int i = 1; i <= n + m; i++) dis[i] = 0x3f3f3f3f3f3f3f3f, vis[i] = 0;
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		
		if (u == t) break;
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (int i = h[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!vis[v]) q.push({dis[v], v}); 
			}
		}
	}
	
	return dis[t];
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (register int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	if (9 <= c && c <= 11) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == j) continue;
				f[i][j] = 0x3f3f3f3f;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k == 1) continue;
		if (9 <= c && c <= 11) {
			int u, v, w1, w2;
			cin >> u >> w1 >> v >> w2;
			f[u][v] = w1 + w2;
		}
		else if (k == 2) {
			int u, v, w1, w2;
			cin >> u >> w1 >> v >> w2;
			add(u, v, w1 + w2), add(v, u, w1 + w2);
		}
		else {
			for (register int j = 1; j <= k; j++) {
				int v, w;
				cin >> v >> w;
				add(m + i, v, w), add(v, m + i, w);
			}
		}
			
	}
	
	if ((1 <= c && c <= 8) || (12 <= c && c <= 15)) {
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << dj(x, y) + w[x] + w[y] << "\n";
		}
		return 0;
	}
	
	if (9 <= c && c <= 11) {
		for (int k = 1; k <= m; k++) {
			for (int i = 1; i <= m; i++) {
				for (int j = i + 1; j <= m; j++) {
					f[i][j] = f[j][i] = min({f[i][j], f[i][k] + f[k][j]});
				}
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << f[x][y] + w[x] + w[y] << "\n";
		}
		return 0;
	}
	
	if (16 <= c && c <= 25) {
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << dj(x, y) + w[x] + w[y] << "\n";
		}
		return 0;
	}
	
	return 0;
}