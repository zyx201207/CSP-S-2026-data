#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll a[1145141],sum[1145141];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll ans=1,sum_query=0,lc=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-lc+1)-(sum[i]-sum[lc-1])>m&&lc<=i) lc++;
		ans=max(ans,i-lc+1);
	}
	cout<<ans;
} 
