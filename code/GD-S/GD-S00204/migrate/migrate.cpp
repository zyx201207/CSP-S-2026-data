#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll f[5005][5005],n,c,t,a[5005],d,dp[5005][5005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			ans=0;
			memset(f,0x3f,sizeof(f));
			memset(dp,0,sizeof(dp));
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i],f[i][i]=0,dp[i][i]=0;
			for(int i=1;i<n;i++)
			{
				if(dp[i]-dp[i-1]<=d) dp[i-1][i]=1;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d) f[i][j]=1,f[j][i]=1;
				}
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
				}
			}
			for(int l=3;l<=n;l++)
			{
				for(int i=1;i+l-1<=n;i++)
				{
					ll j=i+l-1;
					for(int k=i+1;k<=j;k++)
					{
						dp[i][j]+=dp[i][k]*dp[k][j];
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(dp[i][j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}//у╗ак 
