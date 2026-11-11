#include <iostream>
#include <vector>
#include <cmath>

#define int long long

int c, t;
int n, d;
int x[2000005];
std::vector<std::vector<int> > g;
int dist[2000005];

void bfs(int cnt, int cur)
{
	
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	std::cin >> c >> t;
	while (t--)
	{
		std::cin >> n >> d;
		g.assign(n + 1, std::vector<int>());
		for (int i = 1; i <= n; i++)
		{
			std::cin >> x[i];
		}
		std::cout << n << '\n';
	}
	
	return 0;
}
