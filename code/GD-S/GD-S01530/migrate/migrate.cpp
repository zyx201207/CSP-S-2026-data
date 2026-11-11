#include<bits/stdc++.h>
using namespace std;
long long x[2000005],dp[2000005][3];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		long long n,m,ans=0,zyd;
		cin>>n>>m;
		for (int j=1;j<=n;j++)
		{
			cin>>x[j];
			dp[j][0]=x[j];
			dp[j][1]=x[1]-m-1;
			dp[j][2]=x[1]-m-1;
		}
		x[0]=x[1]-m-1;
		for (int j=1;j<=n;j++)
		{
			zyd=j;
			for (int k=1;k<=n-j+1;k++)
			{
				long long j0=dp[j][0],j1=dp[j][1],j2=dp[j][2];
				long long dd1=upper_bound(x+1,x+n+1,j0+m)-x-1,dd2=upper_bound(x+1,x+n+1,j1+m)-x-1,dd3=upper_bound(x+1,x+n+1,j2+m)-x-1;
				if (x[dd1]==j0||j==x[n])
				{
					break;
				}
				ans=ans+max(0LL,dd2-max(zyd,dd3));
				zyd=dd1;
				dp[j][0]=x[dd1];
				dp[j][1]=max(x[dd1-1],x[dd2]);
				dp[j][2]=x[dd3];
				dp[j][2]=max(dp[j][2],min(x[dd1-1],x[dd2]));
				if (dd1-2>=0)
				{
					dp[j][2]=max(dp[j][2],x[dd1-2]);
				}
				if (dd2-1>=0)
				{
					dp[j][2]=max(dp[j][2],x[dd2-1]);
				} 
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
