#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+12;
int n,m,a[N],ans=1,d[N];
bool check(int x)
{
	int mn=1e18;
	for(int i=1;i<=n-x+1;i++)
	{
		mn=min(mn,x*a[i+x-1]-(d[i+x-1]-d[i-1]));
	}
	if(mn<=m)return 1;
	return 0;
}
main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
