#include <stdio.h>
#include <vector>
void setmin(long long& x, long long y) { if (x > y) x = y; }
constexpr int N = 500, M = 500000;
int c, n, m, d, q, w[M + 5];
struct station
{
	int line, t;
	station(int line, int t) : line(line), t(t) {}
};
std::vector<station> vec[M + 5];
long long dist[N + 5][N + 5];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i)
		scanf("%d", w + i);
	for (int i = 1, k; i <= n; ++i)
	{
		scanf("%d", &k);
		while (~--k)
		{
			int a, t;
			scanf("%d%d", &a, &t);
			vec[a].emplace_back(i, t);
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j] = i == j ? 0 : 1e18;
	for (int i = 1; i <= m; ++i)
	{
		for (station st1 : vec[i])
			for (station st2 : vec[i])
				setmin(dist[st1.line][st2.line], st1.t + st2.t);
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				setmin(dist[i][j], dist[i][k] + dist[k][j]);

	while (~--q)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans1 = w[x] + w[y];
		long long ans2 = 1e18;
		for (station st1 : vec[x])
			for (station st2 : vec[y])
				setmin(ans2, st1.t + dist[st1.line][st2.line] + st2.t);
		printf("%lld\n", ans1 + ans2);
	}
	return 0;
}

// 15 : 07