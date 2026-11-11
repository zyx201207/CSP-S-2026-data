#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int plan[N],dp[N],q[N],h,t;
long long a[N],sum[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0;
		if(c==11 || c==12)
		{
			h=t=1;
			for(int i=1;i<=n;i++) dp[i]=plan[i]=sum[i]=q[i]=0;
			q[h]=1;
			dp[1]=0;
			sum[0]=1;
			plan[0]=1;
			for(int r=2;r<=n;r++)
			{
				while(a[r]-a[q[h]]>d && h<=t) sum[dp[q[h]]]-=plan[q[h]],h++;
				dp[r]=dp[q[h]]+1;
				plan[r]=sum[dp[r]-1];
				q[++t]=r;
				sum[dp[r]]+=plan[r];
				if(plan[r]==2) ans+=n-r+1;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int l=1;l<=n;l++)
		{
			h=t=1;
			for(int i=1;i<=n;i++) dp[i]=plan[i]=sum[i]=q[i]=0;
			q[h]=l;
			dp[l]=0;
			sum[0]=1;
			plan[0]=1;
			for(int r=l+1;r<=n;r++)
			{
				while(a[r]-a[q[h]]>d && h<=t) sum[dp[q[h]]]-=plan[q[h]],h++;
				dp[r]=dp[q[h]]+1;
				plan[r]=sum[dp[r]-1];
				q[++t]=r;
				sum[dp[r]]+=plan[r];
				if(plan[r]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
