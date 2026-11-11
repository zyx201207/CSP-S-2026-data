#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ci=const int;
using lli=__int128;
ci N=5e5+5;
namespace Qwq
{
	ll n;
	ll m;
	ll a[N],sum;
	ll ans;
	void mian()
	{
		ll i,j;
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		ll l=0;
		for(i=1;i<=n;i++)
		{
			sum+=(a[i]-a[i-1])*(i-l);
			while(l<i&&sum>m)
			{
				sum-=a[i]-a[l];
				l++;
			}
			ans=max(ans,i-l+1);
		}
		cout<<ans;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	Qwq::mian();
	return 0;
}

