#include <bits/stdc++.h>
using namespace std;
 
const int N = 505, M = 5e5 + 1005;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<long long,int> PLI;
int cc, n, m, d, q;
LL w[M];

vector<PII> g[M], zt[M];
LL dis[M];
bool vis[M];

LL zz[N][N];

void dij(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0;
	priority_queue<PLI, vector<PLI>, greater<PLI> > q;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (PII it : g[u]) {
			int v = it.first, c = it.second;
			if (vis[v]) continue;
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> cc >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i + n];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int u = i;
		while (k--) {
			int v, w;
			cin >> v >> w;
			v += n;
			zt[v].push_back({u, w});
		}
	}
	for (int i = 1; i <= m; i++) {
		int u = i + n;
		if (zt[u].size() > 1) {
			for (auto it : zt[u]) {
				int v = it.first, c = it.second;
				g[u].push_back({v, c});
				g[v].push_back({u, c});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dij(i);
		for (int j = 1; j <= n; j++) {
			zz[i][j] = dis[j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		x += n, y += n;
		LL ans = 4e18;
		for (auto it1 : zt[x]) {
			for (auto it2 : zt[y]) {
				int z1 = it1.first, c1 = it1.second;
				int z2 = it2.first, c2 = it2.second;
				ans = min(ans, zz[z1][z2] + c1 + c2);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
