#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
int c, n, m, ddd, q;
long long d[555][555];
long long w[500005];
struct nd
{
	long long y, w;
};
vector<nd> g[500005];
inline long long read()
{
	int h = 0;
	char c = getchar();
	while(c >= '0' && c <= '9')
	{
		h = 1ll * h * 10 + (c - '0');
		c = getchar();
	}
	return h;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for(int i = 0; i <= 505; i++)
	{
		for(int j = 0; j <= 505; j++)
		{
			d[i][j] = inf;
		}
		d[i][i] = 0;
	}
	c = read(), n = read(), m = read(), ddd = read(), q = read();
	for(int i = 1; i <= m; i++)
	{
		w[i] = read();
	}
	int a, t;
	int kkkk;
	for(int i = 1; i <= n; i++)
	{
		kkkk = read();
		for(int j = 1; j <= kkkk; j++)
		{
			a = read(), t = read();
			g[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < g[i].size(); j++)
		{
			for(int jj = j + 1; jj < g[i].size(); jj++)
			{
				d[g[i][j].y][g[i][jj].y] = min(d[g[i][j].y][g[i][jj].y], 1ll * g[i][j].w + 1ll * g[i][jj].w);
				d[g[i][jj].y][g[i][j].y] = d[g[i][j].y][g[i][jj].y];
			}
		}
	}
	for(int kk = 1; kk <= n; kk++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], 1ll * d[i][kk] + 1ll * d[kk][j]);
				d[j][i] = d[i][j];
			}
		}
	}
	int x, y;
	long long ans;
	while(q--)
	{
		x = read(), y = read();
		ans = inf;
		for(int i = 0; i < g[x].size(); i++)
		{
			for(int j = 0; j < g[y].size(); j++)
			{
				ans = min(ans, 1ll * w[x] + 1ll * w[y] + 1ll * g[x][i].w + 1ll * g[y][j].w + 1ll * d[g[x][i].y][g[y][j].y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
