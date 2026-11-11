#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n;
long long l,x[N],dp[5005][5005],ans,d[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>l;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				d[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]>l)
				break;
				if(d[i][j]==x[j]-x[i])
				{
					dp[i][j]++;
				}
				else if(d[i][j]>x[j]-x[i])
				{
					dp[i][j]=1;
					d[i][j]=1;
				}
				
				for(int k=j+1;k<=n;k++)
				{
					if(x[k]-x[j]>l)
						break;
					if(d[i][k]==d[j][k]+x[j]-x[i])
					{
						dp[i][j]++;
					}
					else if(d[i][k]>d[j][k]+x[j]-x[i])
					{
						dp[i][k]=dp[j][k];
						d[i][k]=d[j][k]+1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=(dp[i][j]==2);
				cout<<dp[i][j]<<' ';
			}
			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
