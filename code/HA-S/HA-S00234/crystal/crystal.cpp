#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0,a[500005],m,maxn=-1e12;
bool check(ll x)
{
	ll ret=0;
	ll i;
	for(i=x;i>=1&&ret+a[x]-a[i]<=m;i--)
	{
		ret+=a[x]-a[i];
	}
	if(i<=0)i=1;
	if(ret>=m)
	{
		while(true)
		{
			if(a[x+1]==a[x])x++;
			else break;
		}
		maxn=max(maxn,x-i+1);
		return false;
	}
	else return true;
}
bool cmp(ll x,ll y){
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ll l=0,r=n;
	while(l<r)
	{
		ll mid=(l+r+1)/2;
		if(check(mid))r=mid-1;
		else l=mid;
	}
	cout<<maxn;
	return 0;
}
