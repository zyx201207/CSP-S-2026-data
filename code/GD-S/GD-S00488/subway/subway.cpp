#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501000;
const int M = 510;
int tc;
int n, m, d, q, w[N], a[M][N];
vector<int> vec[N];
ll dis[M][M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	ll inf = dis[0][0];
	scanf("%d%d%d%d%d", &tc, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int v;
			scanf("%d", &v);
			scanf("%d", &a[i][v]);
			vec[v].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto u : vec[i]) {
			for (auto v : vec[i]) if (u != v) {
				dis[u][v] = min(dis[u][v], (ll)a[u][i] + a[v][i]);
				dis[v][u] = min(dis[v][u], (ll)a[u][i] + a[v][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) if (dis[i][k] != inf) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		ll ans = 1ll << 62;
		for (auto u : vec[s]) {
			for (auto v : vec[t]) {
				ans = min(ans, dis[u][v] + a[u][s] + a[v][t]);
			}
		}
		ans += w[s] + w[t];
		printf("%lld\n", ans);
	}
	return 0;
}