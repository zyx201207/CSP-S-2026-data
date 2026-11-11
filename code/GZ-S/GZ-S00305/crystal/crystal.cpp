//GZ-S00305
//贵阳市白云区华师一学校
//廖博亚 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+5;
ll a[N];
ll s[N];
ll n,m;
ll check(ll x)
{
	for(ll i=x;i<=n;i++)
	{
		if(a[i]*(x-1)-(s[i-1]-s[i-x])<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	ll l=-1000000000000,r=1000000000001;
	while(l+1<r)
	{
		ll mid=l+r>>1;
		if(check(mid)==1) l=mid;
		else r=mid;
	 } 
	 cout<<l<<endl; 
}
