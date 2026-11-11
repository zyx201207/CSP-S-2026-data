#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,ans,a[N];
bool Check(ll x)
{
	ll sum=0;
	for(ll i=1;i<=n;i++)
		if(a[i]<x)
			sum+=x-a[i];
	return sum<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll l=-1e12,r=1e12,mid;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(Check(mid))
			l=mid;
		else
			r=mid-1;
	}
	for(ll i=1;i<=n;i++)
		if(a[i]<=l)
			ans++;
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
