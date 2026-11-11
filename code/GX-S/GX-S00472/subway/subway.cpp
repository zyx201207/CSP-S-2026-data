#include <iostream>
#include <vector>

using ll = long long;
const int INF = 0x3f3f3f3f;

int main()
{
	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	std::vector<int> stats(m + 1);
	std::vector<std::vector<int>> g(m + 1, std::vector<int>(m + 1, INF));
	for (int i = 1; i <= m; i++)
	{
		std::cin >> stats[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int k, pa = 0, pt = 0;
		std::cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			std::cin >> a >> t;
			if (j != 1)
			{
				g[a][pa] = g[pa][a] = pt + t;
			}
			pa = a;
			pt = t;
		}
	}
	
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];

	while (q--)
	{
		int x, y;
		std::cin >> x >> y;
		std::cout << stats[x] + g[x][y] + stats[y] << '\n';
	}
}
