#include<bits/stdc++.h>
using namespace std;
const int M = 1010, N = 610;
int c, n, m, d, q;
long long w[M];
long long dp[M][M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j < i; j++)
		{
			dp[i][j] = dp[j][i] = 1e18;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		int last = 0, lt = 0;
		
		int x, y, xx, yy;
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &xx);
		scanf("%d", &yy);
		dp[xx][x] = dp[x][xx] = y+yy;
	}
	for(int k = 1; k <= m; k++)
	{
		for(int i = 1; i <= m; i++)
		{
			for(int j = i+2; j <= m; j++)
			{
				dp[i][j] = dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	while(q--)
	{
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		printf("%lld\n", w[x] + w[y] + dp[x][y]);
	}
	return 0;
}
