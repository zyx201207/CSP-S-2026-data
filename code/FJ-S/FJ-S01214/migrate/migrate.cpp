#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=500,INF=1e9+7;
int a[N],E[N];
int b[M][M],f[M][M],dp[N][M];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m,ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=(((a[j]-a[i])<=m)?1:INF);
				dp[i][j]=f[i][j]=INF;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					f[i][j]=min(f[i][j],b[i][k]+b[k][j]);
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(b[i][k]+b[k][j]==f[i][j])dp[i][j]++;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dp[i][j])ans++;
				}
			}
		}
		cout<<ans/5<<endl;
	}	
} 
