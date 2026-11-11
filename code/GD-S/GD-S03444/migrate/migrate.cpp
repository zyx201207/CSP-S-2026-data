#include <bits/stdc++.h>
#define int long long
using namespace std;
int sz[2000005];
int dp[5005][5005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin >> c >> t;
	while (t--)
	{
		int ans(0);
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> sz[i];
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				dp[i][j] = 0x7fffffff;
				int sum(0);
				
				for (int k = j-1;k >= i;k--)
				{
					if (sz[j]-sz[k] <= d)
					{
						if (dp[i][j] > dp[i][k]+1)
							sum = 1,dp[i][j] = dp[i][k]+1;
						else
							sum++;
					}	
				}
				if (sum == 2)
					ans++;
			}
		}
		cout << ans << '\n';	
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
