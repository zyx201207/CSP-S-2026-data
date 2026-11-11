#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[5005],dp[5005][5005],ans[5005][5005],cnt = 0;
void dfs(int i,int dep,int tot,int fir,int todep)
{
	if(dep == todep)
	{
		if(i==tot)
		{
			ans[fir][tot]++;
		}
		return;
	}
	for(int j = i+1; j<=n; j++)
	{
		if(dp[i][j]==1)
		{
			dfs(j,dep+1,tot,fir,todep);
		}
	}
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	for(int p = 1; p<=t; p++)
	{
		cin >> n >> d;
		for(int i =1; i<=n; i++)cin >> a[i];
		for(int i = 1; i<n; i++)
		{
			for(int j = i+1; j<=n;j++)
			{
				if(a[j]-a[i]<=d)dp[i][j]=1;
				else
				{
					if(dp[i][j-1]!=0 && a[j]-a[j-1]<=d)dp[i][j] = dp[i][j-1]+1;
				}
			}
		}
		for(int i = 1; i<=n-3; i++)
		{
			for(int j = i+3; j<=n; j++)
			{
				dfs(i,0,j,i,dp[i][j]);
			}
		}
		for(int i = 1; i<=n; i++)
		{
			for(int j = i+1; j<=n; j++)
			{
				if(ans[i][j]==2)cnt++;
			}
		}
		cout << cnt << endl;
		//for(int i = 1; i<=n; i++)
		//{
			//for(int j = 1; j<=n; j++)
			//cout << dp[i][j] << ' ';
			//cout << endl;
		//}
	}
}
