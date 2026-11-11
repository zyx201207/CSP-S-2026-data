#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll a,ll b)
{
	return a>b;
}
ll find(ll a)
{
	ll k;
	for(ll i=1;;i++)
	{
		if(1<<i>a)
		{
			k=i-1;
			break;
		}
	}
	return k;
}
ll q(ll a[],ll n,ll m)
{
	if(n=m)
	{
		ll ans=a[1];
		for(ll i=1;i<=n;i++)
			ans=ans&a[i];
		return ans;
	}
	if(n<m)
		return 0;
	else
	{
		ll l=find(a[m]);
		ll x=0,b[n];
		for(ll i=1;i<=n;i++)
		{
			
			if(a[i]>=1<<l)
			{
				x++;
				b[x]=a[i]-(1<<l);
			}
			
		}
		return q(b,x,m)+(1<<l);
	}
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a[n+1];
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<q(a,n,m);
	return 0;
}
