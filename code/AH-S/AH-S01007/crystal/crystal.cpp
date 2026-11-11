#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll a[N],sum[N];
bool cmp(ll x,ll y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	sum[0]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll p=1,s=1;
	sort(a+1,a+n+1,cmp);
	for(ll i=2;i<=n;i++)
	{
		while((p<i)&&((i-p)*a[i]-(sum[i-1]-sum[p-1])))
		{
			p++;
		}
		ll w=i-p+1;
		s=max(s,w);
	}
	cout<<s;	
}
