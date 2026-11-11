#include <stdio.h>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 501, M = 5e5 + 1;
using i64 = long long;
//N 线路数，M 站台数 
int w[M];
map<int, int> fa[M];//key:线路id,val:权值 
i64 dis[N][N];
void floyd(const int n)
{
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &w[i]); 
	for(int i = 1; i <= n; ++i)
	{
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k ;++j)
		{
			int a, t;
			scanf("%d%d", &a, &t);
			fa[a][i] = t;
		}
	}
	for(int i = 1; i <= m; ++i)
	{
		vector<pair<int, int>> temp;
		for(const pair<int, int> p : fa[i])
		{
			if(!temp.empty())
			{
				for(const pair<int, int> p2 : temp)
				{
					const int u = p.first, v = p2.first;
					dis[u][v] = dis[v][u] = 1ll * p.second + p2.second;
				}
			}
			temp.push_back(p);
		}
	}
	floyd(n);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		i64 ans = 0x3f3f3f3f3f3f3f3f;
		for(pair<int, int> p : fa[a])
		{
			for(pair<int, int> p2 : fa[b])
			{
				ans = min(ans, dis[p.first][p2.first] + p.second + p2.second);
			}
		}
		printf("%lld\n", ans + w[a] + w[b]);
	}
	return 0;
}
