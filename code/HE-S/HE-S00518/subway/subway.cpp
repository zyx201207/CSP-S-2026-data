#include <iostream>
#include <climits>
#include <vector>

#define int long long

int c, n, m, d, q;
std::vector<int> w;
std::vector<std::vector<int> > a, t;
std::vector<std::vector<int> > dist;

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::cin >> c >> n >> m >> d >> q;
	dist.assign(m + 1, std::vector<int>(m + 1, 0x3f3f3f3f3f3f3f3f));
	w.assign(m + 1, 0);
	a.assign(n + 1, std::vector<int>(d + 1, 0));
	t.assign(n + 1, std::vector<int>(d + 1, 0));    
	for (int i = 1; i <= m; i++)
	{
		std::cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; j++)
		{
			std::cin >> a[i][j] >> t[i][j];
		}
		for (int x = 1; x <= k; x++)
		{
			for (int y = 1; y <= k; y++)
			{
				if (a[i][x] == a[i][y])
				{
					continue; 
				}
				dist[a[i][x]][a[i][y]] = std::min(t[i][x] + t[i][y], dist[a[i][x]][a[i][y]]);
			}
		}
	}
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (dist[i][k] + dist[k][j] <= dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		std::cin >> x >> y;
		std::cout << w[x] + dist[x][y] + w[y] << '\n';
	}
	
	return 0;
}
