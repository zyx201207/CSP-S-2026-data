#include<bits/stdc++.h>
#define ll long long
#define AC return 0
using namespace std;
const int N=2e6+77;
ll c,t,n,d,sum=0,a[N],dp[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		dp[1]=0;
		for(int i=2;i<=n;i++) dp[i]=dp[max(1LL,i-d)]+1;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ll x=(a[j]-a[i])%d;
				ll mi=1e18;
				for(int k=i+1;k<=j;k++) mi=min(mi,a[k]-a[k-1]);
				if(x>=mi) sum++;
			}
		}
		cout<<sum<<"\n";
		sum=0;
	}
	AC;
}
//GoodBye OI (;
