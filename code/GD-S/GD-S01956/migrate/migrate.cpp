#include <bits/stdc++.h>
using namespace std;
long long n,a[2000005],dp[305][305],sum[305][305],m,T,c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		bool fA=1;
		long long k=a[2]-a[1];
		for(int i=3;i<=n;i++)
		{
			if(a[i]-a[i-1]!=k)
			{
				fA=0;
				break;
			}
		}
		if(n<=300)
		{
			memset(sum,0,sizeof sum);
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=m)
					{
						dp[i][j]=1;
						sum[i][j]=1;
					}
					else
					{
						dp[i][j]=2*1e18+5;
					}
				}
			}
			
			for(int l=1;l<=n;l++)
			{
				for(int r=l+2;r<=n;r++)
				{
					for(int i=l+1;i<r;i++)
					{
						if(dp[l][i]==2*1e18+5)continue;
						else if(a[r]-a[i]<=m)
						{
							if(dp[l][i]+1==dp[l][r])
							{
								sum[l][r]+=sum[l][i];
							}
							else if(dp[l][i]+1<dp[l][r])
							{
								sum[l][r]=sum[l][i];
								dp[l][r]=dp[l][i]+1;
							}
						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(sum[i][j]==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		else if(fA)
		{
			long long cnt=m/k*2-1;
			if(cnt<=1)
			{
				cout<<0<<'\n';
				continue; 
			}
			cout<<max(0ll,n-cnt)<<'\n';
		}
		else
		{
			
		}
	}
	
	return 0;
}
