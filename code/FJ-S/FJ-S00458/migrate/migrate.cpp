#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

inline ll r()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

const ll N = 10000;
ll c, t, n, d, x[N], way[N], dis[N][N];

void dfs(int fa, int u, int s)
{
//	cout <<fa<<' ' << u <<'\n';
	if(dis[fa][u] != s)
	{
		return ;
	}
	way[u]++;
	if(u == n) return ;
	for(int v = u + 1; v <= n && x[v] - x[u] <= d; v++)
	{
		dfs(fa, v, s + 1);
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = r(), t = r();
	while(t--)
	{
		memset(dis, 0x3f, sizeof(dis));
		n = r(), d = r();
		for(int i = 1; i <= n; i++)
		{
			x[i] = r();
			dis[i][i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ll s = 0, v = i;
				while(v < j)
				{
					if(x[v + 1] - x[v] > d) break;
					ll u = v;
					v++;
					while(v <= j && x[v] - x[u] <= d)
					{
						v++;
					}
					if(x[v] - x[u] > d) v--;
					s++;
				}
				if(v < j) break;
				dis[i][j] = s;
//				cout <<i <<' ' << j << ' ' << dis[i][j] << '\n';
			}
		}
			
		ll ans = 0;
		for(int i = 1; i < n; i++)
		{
			memset(way, 0, sizeof(way));
			dfs(i, i, 0);
			for(int j = i + 1; j <= n; j++)
			{
				if(way[j] == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
