#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll n,m;
ll a[N];
bool check(ll mid)
{
	long long res=0;
	for(int i=1;i<=mid;i++)
	{
		res+=a[mid]-a[i];
	}
	return res<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
