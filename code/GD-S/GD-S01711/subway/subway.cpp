#include <bits/stdc++.h>
using namespace std;

inline long long read()
{
	long long x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

inline void write(long long x)
{
	if (x > 9) write(x / 10);
	int tmp = (x % 10);
	putchar(tmp + '0');
}

int c, n, m, d, q;
int entry[500005];
vector <int> line[500005], t[500005];
long long g[505][505];

void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 2; i <= n; i++)
		{
			if (k == i) continue; 
			for (int j = 1; j < i; j++)
			{
				if (j == k) continue;
				g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[j][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) g[i][i] = 0;
}

void solve(int s, int e)
{
	long long ans = 9e18;
	for (int i = 0; i < line[s].size(); i++)
	{
		for (int j = 0; j < line[e].size(); j++)
		{
			int u = line[s][i], v = line[e][j];
			long long ti = 1ll * entry[s] + 1ll * entry[e] + 1ll * t[s][i] + 1ll * t[e][j] + g[u][v];
			ans = min(ans, ti);
		}
	}
	write(ans); 
	putchar('\n');
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	for (int i = 1; i <= 500; i++)
		for (int j = 1; j <= 500; j++) g[i][j] = g[j][i] = 4e18;
		
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) entry[i] = read();
	for (int i = 1, k; i <= n; i++)
	{
		k = read();
		for (int j = 1, x, ti; j <= k; j++)
		{
			x = read(), ti = read();
			line[x].push_back(i);
			t[x].push_back(ti);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < line[i].size(); j++)
		{
			int u = line[i][j];
			for (int k = 0; k < j; k++)
			{
				int v = line[i][k];
				long long ti = 1ll * t[i][j] + 1ll * t[i][k];
				g[u][v] = g[v][u] = min(g[u][v], ti);
			} 
		}
	}
	
	floyd();
	
	while (q--)
	{
		int s, e;
		s = read(), e = read();
		solve(s, e);
	}
	return 0;
}
