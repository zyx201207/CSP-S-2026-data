#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll n,m,a[N],s[N]; 
bool check(ll x,ll y)
{
	return a[y]*(y-x+1)-(s[y]-s[x-1])<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=1;
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(check(mid,i)) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}
