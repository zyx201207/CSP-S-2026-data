#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e6 + 10;

int q[N], nm[N], c, t, n;

long long d[N], m, ans;

inline void dfs(int k, int s)
{
	if (nm[k] > s)
	{
		nm[k] = s;
		q[k] = 1;
	}
	else if (nm[k] == s)
	{
		q[k]++;
	}
	for (int i = k + 1; i <= n; i++)
	{
		if ((d[i] - d[k]) > m)
		{
			break;
		}
		dfs(i, s + 1);
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		scanf("%d%lld", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", d + i);
		}
		ans = 0;
		for (int i = 1; i < n; i++)
		{
			memset(q, 0, sizeof(q));
			memset(nm, 0x3f, sizeof(nm));
			dfs(i, 1);
			for (int j = i + 1; j <= n; j++)
			{
				if (q[j] == 2)
				{
					ans++;
				}
//				printf("%d ", q[j]);
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
