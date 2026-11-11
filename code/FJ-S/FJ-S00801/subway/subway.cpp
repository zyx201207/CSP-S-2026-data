#include <bits/stdc++.h>
using namespace std;

struct node {
	long long a, t;
} e[500005];

long long dis[505][505], w[500005], c, n, m, d, q, k, x, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 0; i <= m; i++) {
		for (long long j = 0; j <= m; j++) dis[i][j] = 1e18;
	}
	for (long long i = 1; i <= m; i++) cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		cin >> k;
		for (long long j = 1; j <= k; j++) cin >> e[j].a >> e[j].t;
		for (long long u = 1; u <= k; u++) {
			for (long long v = u + 1; v <= k; v++) {
				dis[e[u].a][e[v].a] = min(dis[e[u].a][e[v].a], e[u].t + e[v].t);
				dis[e[v].a][e[u].a] = dis[e[u].a][e[v].a];
			}
		}
	}
	for (long long i = 1; i <= m; i++) dis[i][i] = 0;
	for (long long k = 1; k <= m; k++) {
		for (long long i = 1; i <= m; i++) {
			for (long long j = 1; j <= m; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
