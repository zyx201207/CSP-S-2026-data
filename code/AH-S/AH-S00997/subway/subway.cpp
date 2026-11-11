#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using  namespace std;

#define x first
#define y second

typedef long long LL;
typedef pair<int, int> PII;

const int N = 500010, M = 510;

int c, m, n, d, q;
int w[N];
vector<PII> g[M], s[N];
LL f[M][M];

void init(const int &st, const int &ed)
{
	for (int i = 0; i <= m; i ++ )
		for (int j = 0; j <= m; j ++ )
			if(i != j) f[i][j] = 1e18;
			
	for (int i = st; i <= ed; i ++ )
	{
		for (int j = 0; j < s[i].size(); j ++ )
		{
			for (int k = 0; k < s[i].size(); k ++ )
			{
				int u = s[i][j].x, v = s[i][k].x;
				LL w1 = s[i][j].y, w2 = s[i][k].y;
				f[u][v] = min(f[u][v], w1 + w2);
			}
		}
	}
			
	for (int k = 1; k <= m; k ++ )
		for (int i = 1; i <= m; i ++ )
			for (int j = 1; j <= m; j ++ )
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &m, &n, &d, &q);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
	for (int i = 1, l; i <= m; i ++ )
	{
		scanf("%d", &l);
		for (int j = 1, x, w; j <= l; j ++ )
		{
			scanf("%d%d", &x, &w);
			g[i].push_back({x, w});
			s[x].push_back({i, w});
		}
	}		
	while (q -- )
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		
		init(st, ed);
		
		LL ans = 1e18;
		for (int i = 0; i < s[st].size(); i ++ )
		{
			for (int j = 0; j < s[ed].size(); j ++ )
			{
				int u = s[st][i].x, v = s[ed][j].x;
				int w1 = s[st][i].y, w2 = s[ed][j].y;
				ans = min(ans, w[st] + w[ed] + w1 + w2 + f[u][v]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/


/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

