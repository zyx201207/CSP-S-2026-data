#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans=0;
bool check(ll mid) 
{
	ll s=0;
	for(int i=0;i<mid;i++)
	{
		s+=(a[mid]-a[i]);
	}
	if(s<=m)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	ll l=0,r=n-1;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)==0)
		{
			l=mid+1;
			ans=l;
		}
		else
		{
			r=mid-1;
		}
	}
	ll ans2=ans;
	for(int i=ans2+1;i<n;i++)
	{
		if(a[i]==a[ans])
		{
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

