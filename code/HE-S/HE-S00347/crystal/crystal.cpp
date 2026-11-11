#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if((x*a[i])-(sum[i]-sum[i-x])<=m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=2,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
