#include <bits/stdc++.h>

using namespace std;

#define int long long

int c, t;
int n, d;
int x[2000010];
int dp[330][330];
int sum[330][330][110];

void dfs(int l, int p, int cnt)
{
	sum[l][p][cnt] ++;
	for(int i = p + 1; i <= n && (x[i] - x[p] <= d); i ++)
	{
		dfs(l, i, cnt + 1);
	}
	return;
}


signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int T = 1; T <= t; T ++)
	{
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >> x[i];
		}
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j < i; j ++)
			{
				for(int w = 1; w <= 100; w ++)
				{
					sum[j][i][w] = 0;
				}
			}	
		}
		for(int i = 1; i <= n; i ++)
		{
			dfs(i, i, 0);
		}
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j < i; j ++)
			{
				for(int w = 1; w <= 100; w ++)
				{
					if(sum[j][i][w])
					{
						if(sum[j][i][w] == 2) ans ++;
						break;
					}
				}
			}	
		}
		cout << ans << '\n';
	}
	return 0;
}
