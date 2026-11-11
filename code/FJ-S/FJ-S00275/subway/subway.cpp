#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

const int N = 5e5 + 10;

int dis[510], q[N], d[510], c, m, n, k, t, u, z, v;

bool flag[510];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &m, &n, &k, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", d + i);
	}
	for (int i = 1, cnt = 0; i <= m; i++)
	{
		scanf("%d", &q[++cnt]);
		int x = q[cnt];
		while (x--)
		{
			scanf("%d", &q[++cnt]);
			scanf("%d", &q[++cnt]);
		}
	}
	while (t--)
	{
		scanf("%d%d", &u, &v);
		z = u;
		memset(dis, 0x3f, sizeof(dis));
		dis[u] = 0;
		memset(flag, false, sizeof(flag));
		priority_queue<pair<int, int> > qe;
		qe.push({0, u});
		while (!qe.empty())
		{
			int u = qe.top().second;
			qe.pop();
			if (flag[u])
			{
				continue;
			}
			flag[u] = true;
			for (int i = 1, cnt = 1; i <= m; i++)
			{
				bool flag = false;
				for (int j = 1; j <= (2 * q[cnt]); j += 2)
				{
					if (q[cnt + j] == u)
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					for (int j = 1; j <= (2 * q[cnt]); j += 2)
					{
						if (dis[q[cnt + j]] > (dis[u] + q[cnt + j + 1]))
						{
							dis[q[cnt + j]] = dis[u] + q[cnt + j + 1];
							qe.push({-dis[q[cnt + j]], q[cnt + j]});
						}
					}
				}
				cnt += 2 * q[cnt];
			}
		}
		printf("%d\n", dis[v] + d[u] + d[v]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
