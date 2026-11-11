#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7;
ll n,m;
ll a[N];
ll sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll l=1;
		ll r=i;
		ll res=1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			ll len=i-mid+1;
			if(a[i]*len-(sum[i]-sum[mid-1])<=m)
			{
				res=len;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans<<'\n'; 
}
