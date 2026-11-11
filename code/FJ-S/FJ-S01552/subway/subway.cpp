#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 1e3 + 5;

int c, n, m, d, q;
ll w[MAXM];
ll dis[MAXM][MAXM];

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

ll readll()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void floyde()
{
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (dis[i][j] > 0) continue;
				if (i > j)
				{
					dis[i][j] = dis[j][i];
					continue;
				}
				dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
	{
		w[i] = readll();
	}
	for (int i = 1; i <= m; i++)
	{
		dis[i][i] = 0;
	}
	vector<pair<int, ll>> g[n + 1];
	for (int i = 1; i <= n; i++)
	{
		int k = read();
		int u = read();
		ll t0 = readll();
		for (int j = 1; j <= k - 1; j++)
		{
			int v = read();
			ll t = readll();
			dis[u][v] = t0 + t;
		}		
	}
	floyde();
	for (int i = 1; i <= m; i++)
	{
		dis[i][i] = 0;
	}
	while (q--)
	{
		int a = read(), b = read();
		ll ans = 0;
		ans = w[a] + w[b] + dis[a][b];
		cout << ans << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
