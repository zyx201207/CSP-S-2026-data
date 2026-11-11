#include <bits/stdc++.h>
using namespace std;

const int MR = 5e5 + 5;

int c, n, m, d, q;
int a[505][MR], l[505], cuong[505][505][505], cnt[505][505];
int t_kt[MR]; 
int t_tx[505][MR];

int dfs(int s, int t)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= l[i]; j++)
		{
			for(int k = 1; k <= l[i]; k++)
			{
				if(j == k) continue;
				if(a[i][j] == s && a[i][k] == t) 
				{
					return 0;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int k = 1; k <= n; k++)
		{
			for(int j = 1; j <= l[i]; j++)
			{
				for(int h = 1; h <= l[k]; h++)
				{
					if(a[i][j] == s && a[k][h] == t)
					{
						for(int f = 1; f <= cnt[i][k]; f++)
						{
							int g = cuong[i][k][f];
							return dfs(s, g) + t_tx[i][g] + t_tx[k][g] + dfs(g, t);
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> t_kt[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i];
		for(int j = 1; j <= l[i]; j++)
		{
			cin >> a[i][j] >> t_tx[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int k = 1; k <= n; k++)
		{
			for(int j = 1; j <= l[i]; j++)
			{
				for(int h = 1; h <= l[k]; h++)
				{
					if(a[i][j] == a[k][h])
						cuong[i][k][++cnt[i][k]] = a[i][j];
				}
			}
		}
	}
	while(q--)
	{
		int s, t;
		cin >> s >> t;
		int ans = 0;
		ans += t_kt[s] + t_kt[t];
		ans += dfs(s, t);
		cout << ans << "\n";
	}
	return 0;
}

