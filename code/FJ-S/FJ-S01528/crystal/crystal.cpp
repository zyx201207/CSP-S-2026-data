#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+100;
ll n,m,ans,a[N];
ll sum[N];
ll dp[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];



	dp[1]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
			if (m+(sum[j]-sum[i-1])>=(j-i+1)*a[j])
				dp[j-i+1]=max(dp[j-i+1],(ll)(j-i+1));
	}
	for (int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}

