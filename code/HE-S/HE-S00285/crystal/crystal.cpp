#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans=1ll,sum[500005];
ll erfen(int x)
{
	int l=1ll,r=x,mid,ans;
	while(l<=r)
	{
		mid=(l+r+1ll)>>1ll;
		if(a[x]*(x-mid+1ll)-(sum[x]-sum[mid-1])>m)l=mid+1ll;
		else r=mid-1ll,ans=mid;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1ll;i<=n;i++)sum[i]=sum[i-1ll]+a[i];
	for(ll i=2ll;i<=n;i++)
	{
		ll c=erfen(i);
		ans=max(ans,i-c+1ll);
	}
	cout<<ans;
	return 0;
}
