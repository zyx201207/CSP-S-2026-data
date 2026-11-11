#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5, K = 1e3 + 5, D = 2e1 + 5, INF = 0x3f3f3f3f;
int c, n, m, d, q, cnt[M], line[M][D];
long long w[M], g[N][N];
long long dis[N][N];
struct node {
	int k, a[K], t[K], rest[M];
} e[N];
bool cmp(node num1, node num2) {
	return num1.k < num2.k;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].k;
		for (int j = 1; j <= e[i].k; j++) {
			cin >> e[i].a[j] >> e[i].t[j];
			e[i].rest[e[i].a[j]] = j;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) g[i][j] = dis[i][j] = INF;
	sort(e + 1, e + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= e[i].k; j++) line[e[i].a[j]][++cnt[e[i].a[j]]] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int minn = INF;
			for (int l = 1; l <= e[i].k; l++) {
				if (e[j].rest[e[i].a[l]] != 0) minn = min(minn, e[i].t[l] + e[j].t[e[j].rest[e[i].a[l]]]);
			}
			dis[i][j] = dis[j][i] = minn;
		}
	}
	for (int i = 1; i <= n; i++) g[i][i] = dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[j][k]);
	while (q--) {
		int u, v;
		cin >> u >> v;
		long long minn = INF;
		for (int i = 1; i <= cnt[u]; i++)
			for (int j = 1; j <= cnt[v]; j++) {
				minn = min(minn, dis[line[u][i]][line[v][j]] + e[line[u][i]].t[e[line[u][i]].rest[u]] + e[line[v][j]].t[e[line[v][j]].rest[v]]);
			}
		cout << w[u] + w[v] + minn << "\n";
	}
	return 0;
}
