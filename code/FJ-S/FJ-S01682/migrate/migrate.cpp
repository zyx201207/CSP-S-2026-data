#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,dp[5005][5005];
long long d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (x[j]-x[i]<=d) dp[i][j] = 1;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+3;j<=n;j++)
			{
				if (!dp[i][j])
				{
					int t=j-i;
					for (int b = i+1;b<j;b++)
					{
						if (dp[i][b] && dp[b][j]) 
						{
							if (dp[i][b]+dp[b][j]<=t)
							{
								if (dp[i][b]+dp[b][j]<t) 
								{
									dp[i][j] = 0;
									t = dp[i][b]+dp[b][j];
								}
								dp[i][j]++;
							}
						}
					}
				}
			}
		}		
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (dp[i][j] == 2) 
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
