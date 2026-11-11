#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m;
ll a[N],s[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
