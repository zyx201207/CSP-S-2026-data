#include<bits/stdc++.h>
using namespace std;
int c,t,n,dp[305][305][305];
long long d,x[305];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d) dp[i][j][1]=1;
				for(int k=2;k<=(j-i);k++)
				{
					for(int t=i+1;t<j;t++)
					{
						if(x[j]-x[t]<=d) dp[i][j][k]+=dp[i][t][k-1];
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=1;k<=(j-i);k++)
				{
					if(dp[i][j][k]!=0)
					{
						if(dp[i][j][k]==2) ans++;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=1;k<=(j-i);k++) dp[i][j][k]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
