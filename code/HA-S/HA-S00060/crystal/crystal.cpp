#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,ans;
ll a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		ll l=0,r=i;
		while(l<=r)
		{
			ll mid=(l+r)>>1,t=(i-mid)*a[i]-(b[i]-b[mid]);
			if(t<=m)r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	printf("%lld",ans);
	return 0;
}
