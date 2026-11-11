#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==2)
	{
		ll maxn=INT_MIN;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				ll p=a[i]&a[j];
				maxn=max(maxn,p);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		ll t=a[1];
		for(ll i=2;i<=n;i++)
		{
			t=t&a[i];
		}
		cout<<t;
		return 0;
	}
	return 0;
}
