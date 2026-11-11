#include <bits/stdc++.h>
typedef long long ll;
const int N = 5e5 + 5;
const int M = 505;

int c, n, m, d, q;
ll w[N];
ll dis[M][M];

std::vector<std::pair<int, ll> > e[N];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) scanf("%lld", w + i);
	for (int i = 1; i <= n; ++i) {
		int k; scanf("%d", &k);
		while (k--) {
			int x; ll val; scanf("%d%lld", &x, &val);
			e[x].push_back({i, val});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) 
		for (auto p : e[i]) {
			int u = p.first; ll val = p.second;
			for (auto p2 : e[i]) {
				int v = p2.first; ll val2 = p2.second;
				if (u == v) continue;
				dis[u][v] = dis[u][v] = std::min(dis[u][v], val + val2);
			}
		}	
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int a, b; scanf("%d%d", &a, &b);
		ll del = w[a] + w[b], ans = 1e18;
		for (auto p : e[a]) {
			int u = p.first; ll val = p.second;
			for (auto p : e[b]) {
				int v = p.first; ll val2 = p.second;
				ans = std::min(ans, val + val2 + dis[u][v]);
			}
		}	
		printf("%lld\n", ans + del);
	}
	return 0;
}
