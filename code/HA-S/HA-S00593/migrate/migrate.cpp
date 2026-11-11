#include<bits/stdc++.h>
using namespace std;
int c,t,n,a[2000005],dp[2000005],v[2000005];
long long d,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int k = 1;k<=n;k++)
		{
			memset(dp,0x3f,sizeof(dp));
			memset(v,0,sizeof(v));
			dp[k]=0;
			for(int i = k;i<=n;i++)
			{
				for(int j = i;j<=n;j++)
				{
					if(a[j]-a[i]<=d)
					{
						if(dp[i]+1<dp[j])
						{
							v[j]=1;
						}	
						if(dp[i]+1==dp[j])
						{
							v[j]++;
						}
						dp[j]=min(dp[i]+1,dp[j]);
					}
				}
			}
			for(int i = 1;i<=n;i++)
			{
				if(v[i]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
