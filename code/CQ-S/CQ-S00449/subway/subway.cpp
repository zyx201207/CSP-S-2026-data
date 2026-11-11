#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

namespace wxr
{

const int maxn = 500 + 10;

const int maxm = 5e5 + 10;

long long dis[maxn][maxn];

std::vector<std::pair<int, long long>> v[maxm];

long long w[maxm];

std::vector<std::pair<int, long long>> p[maxn];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int Case, n, m, d, q;
	scanf("%d %d %d %d %d", &Case, &n, &m, &d, &q);
	
	for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (i == j) dis[i][j] = 0;
		else dis[i][j] = 1LL << 60;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		
		for (int j = 0; j < k; j++)
		{
			int x; long long t;
			scanf("%d %lld", &x, &t);
			p[i].push_back({x, t});
			v[x].push_back({i, t});
		}
		
		for (int j = 0; j < k; j++)
		{
			int x = p[i][j].first; long long t = p[i][j].second;
			for (auto tmp : v[x])
			{
				if (tmp.first != i)
				{
					dis[tmp.first][i] = dis[i][tmp.first] = std::min(dis[i][tmp.first], t + tmp.second);
				}
			}
		}
	}
	
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while (q--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		
		long long ans = 1LL << 60;
		for (auto a : v[x])
		{
			for (auto b : v[y])
			{
				ans = std::min(ans, a.second + b.second + dis[a.first][b.first]);
			}
		}
		
		printf("%lld\n", ans + w[x] + w[y]);
	}
	
	return 0;
}
}

int main()
{
	wxr::main();
	return 0;
}

