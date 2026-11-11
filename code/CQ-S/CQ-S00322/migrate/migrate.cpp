#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e6+5;
int c,t,dp[M];
ll a[M],b[M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		int n;
		ll d;
		cin>>n>>d;
		if(d==1)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			b[i]=a[i]-a[i-1];
		}
		dp[1]=dp[2]=0;
		for(int i=3;i<=n;i++)
		{
			if(b[i]>d) dp[i]=dp[i-1];
			else 
			{
				if(dp[i-1]==0)
				{
					if(b[i]+b[i-1]+b[i-2]+b[i-3]>d&&b[i]<d&&b[i-1]<d&&b[i-2]<d&&b[i-3]<d) dp[i]=dp[i-1]+1;
				}
				else 
				{
					if(b[i]==b[i-3])dp[i]=dp[i-1]+1;
				}
			}
		}
		cout<<dp[n]<<endl;
	}
}
