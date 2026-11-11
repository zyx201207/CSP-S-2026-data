#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e6+10,inf=0x3f3f3f3f3f3f3f3f;
int n,d,a[N],dp[N],minn[N],ans;
void sol()
{
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i+1;k<=j;k++) dp[k]=0,minn[k]=inf;
			minn[i]=0,dp[i]=1;
			for(int k=i+1;k<=j;k++)
			{
				for(int l=i;l<k;l++)
				{
					if(a[k]-a[l]>d) continue;
					if(minn[k]>minn[l]+1) minn[k]=minn[l]+1,dp[k]=dp[l];
					else if(minn[k]==minn[l]+1) dp[k]+=dp[l];
				}
			}
			if(dp[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) sol();
	return 0;
}
