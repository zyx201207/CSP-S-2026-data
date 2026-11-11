#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;

int c, t, n, m, ans;

bool flag[N], f[N], fl[N];

vector<int> edge[N];

inline void dfs(int u)
{
	f[u] = true;
	for (auto v : edge[u])
	{
		if (flag[v] && !f[v])
		{
			dfs(v);
		}
	}
}

inline void maxn(int u, int k, int &mi)
{
	fl[u] = true;
	for (auto v : edge[u])
	{
		if (flag[v])
		{
			mi = min(mi, k);
			return ;
		}
		else if (!fl[v])
		{
			maxn(v, k + 1, mi);
		}
	}
}

inline void df(int k)
{
	if (k > m)
	{
		int cnt = 0, ma = 0, mi;
		memset(f, false, sizeof(f));
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] && !f[i])
			{
				cnt++;
				dfs(i);
			}
			if (cnt > 2)
			{
				return ;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i])
			{
				memset(fl, false, sizeof(fl));
				mi = 0x3f3f3f3f;
				maxn(i, 1, mi);
				ma = max(ma, mi);
			}
		}
		ans = min(ans, ma);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])
		{
			flag[i] = true;
			df(k + 1);
			flag[i] = false;
		}
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		df(1);
		printf("%d\n", ans);
//		printf("%d\n", n - 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
