#include <bits/stdc++.h>

#define N (500)
#define M ((int) 5e5)

#define OO (0x3f3f3f3f'3f3f3f3fll)

using std::min;
#define chkmin(u, v) ((u) = min(u, v))

typedef unsigned long long u64;

int n, m, q, w[M + 1];
std::vector<std::pair<int, int>> es[M + 1];

u64 dp[N + 1][N + 1];

main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%*d %d %d %*d %d", &n, &m, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1, k, u, v; i <= n; i++)
		for (scanf("%d", &k); k --> 0; )
			scanf("%d %d", &u, &v), es[u].push_back({ i, v });

	memset(dp, OO, sizeof dp);
	for (int i = n; i; i--) dp[i][i] = 0;
	for (int i = m; i; i--) {
		auto& edges = es[i];
		for (int u = edges.size() - 1; ~u; u--)
			for (int v = u - 1; ~v; v--)
				dp[edges[v].first][edges[u].first] =
						chkmin(dp[edges[u].first][edges[v].first], (u64) edges[u].second + edges[v].second);
	}
	for (int k = n; k; k--)
		for (int i = n; i; i--)
			for (int j = i - 1; j; j--)
				dp[j][i] = chkmin(dp[i][j], dp[i][k] + dp[k][j]);

	while (q --> 0) {
		int x, y; scanf("%d %d", &x, &y);

		u64 ans = OO;
		for (auto& u : es[x])
			for (auto& v : es[y])
				chkmin(ans, u.second + v.second + dp[u.first][v.first]);

		printf("%llu\n", ans + w[x] + w[y]);
	}

	return 0;
}