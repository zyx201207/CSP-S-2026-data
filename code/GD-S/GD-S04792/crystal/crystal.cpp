#include <iostream>
#include <fstream>
#include <algorithm>
#define ll long long
using namespace std;
ll a[500005],s[500005],n,m,ans;
ll x(ll i)
{
	ll l=1,r=i,mid,res=i;
	while(l<=r){
		mid=(l+r)>>1;
		//[mid,i]
		if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
			r=mid-1,res=min(res,mid);
		else
			l=mid+1;
	}
	return i-res+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)s[i]=s[i-1]+a[i];
	for(int i=1; i<=n; i++)
		ans=max(ans,x(i));
	cout<<ans;
	return 0;
}
