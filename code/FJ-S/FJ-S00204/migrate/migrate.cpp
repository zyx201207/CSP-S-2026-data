#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,x[2000005],dp[5005][5005];
bool f[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		memset(dp,0,sizeof(dp));
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int r=i;
			while(r<n&&x[r]-x[i]<=d)
			{
				if(r+1<=n&&x[r+1]-x[i]<=d)
				{
				    r++;
				}
				else
				{
					break;
				}
			}
			for(int j=i+1;j<=r;j++)
			{
				dp[i][j]=1;
			}
		}
		for(int len=2;len<n;len++)
		{
			for(int l=1;l+len<=n;l++)
			{
				int r=l+len;
				for(int k=l+1;k<r;k++)
				{
					if((!dp[l][r]||f[l][r])&&dp[l][k]&&dp[k][r])
					{
						dp[l][r]+=dp[l][k]*dp[k][r];
						f[l][r]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cout<<dp[i][j]<<endl;
				if(dp[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
