#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+3;
long long a[N],n,ans[N],m,maxn=1;
bool qh(ll mid)
{
	for(ll i=mid;i<=n;i++)
	{
		ll t=ans[i-mid+1]-ans[i+1]-(a[n]-a[i])*mid;
		if(t<=m)
			return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >>n >>m;
	for(ll i=1;i<=n;i++)
		cin >>a[i];	
	sort(a+1,a+1+n);
	for(ll i=n;i>=1;i--)
		ans[i]=ans[i+1]+a[n]-a[i];
	ll l=0,r=n+1;
	while(l+1<r)
	{
		ll mid=(l+r)>>1;
		if(qh(mid))			
			l=mid;	
		else
			r=mid;
	}
	cout <<l;
	return 0;
 } 
