#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll n,m,a[N],s[N];
bool check(ll x)
{
	for(ll i=x;i<=n;i++)
	{
		if(s[i]-s[i-x]<=m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s[1]=0;
	for(ll i=2;i<=n;i++)
	{
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	ll l=1,r=n;
	while(l<r)
	{
		ll mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
