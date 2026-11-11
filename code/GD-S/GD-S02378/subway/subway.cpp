#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 5e4 + 10, N = 510, INF = 0x3f3f3f3f;

int c, n, m, d, q, w[M], k[N], a[N][M], t[N][M], x, y, dist[M];
vector <int> g[M];
bool type1 = true;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> k[i];
		if(k[i] > 2) type1 = false;
		for(int j = 1;j <= k[i];j++) {
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	if(type1) {
		for(int i = 1;i <= q;i++) {
			cin >> x >> y;
			memset(dist, INF, sizeof dist);
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			dist[x] = 0;
			pq.push({0, x});
			while(!pq.empty()) {
				int u = pq.top().second;
				pq.pop();
				for(int &line : g[u]) {
					for(int j = 1;j <= k[line];j++) {
						if(a[line][j] != u) {
							int &v = a[line][j];
							if(dist[u] + t[line][u] + t[line][v] < dist[v]) {
								dist[v] = dist[u] + t[line][u] + t[line][v];
								pq.push({dist[v], v});
							}
						}
					}
				}
			}
		}
		return 0;
	}
	for(int i = 1;i <= q;i++) {
		cin >> x >> y;
		memset(dist, INF, sizeof dist);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[x] = 0;
		pq.push({0, x});
		while(!pq.empty()) {
			int u = pq.top().second;
			pq.pop();
			for(int &line : g[u]) {
				for(int j = 1;j <= k[line];j++) {
					if(a[line][j] != u) {
						int &v = a[line][j];
						if(dist[u] + t[line][u] + t[line][v] < dist[v]) {
							dist[v] = dist[u] + t[line][u] + t[line][v];
							pq.push({dist[v], v});
						}
					}
				}
			}
		}
		cout << w[x] + w[y] + dist[y] << '\n';
	}
	return 0;
}
