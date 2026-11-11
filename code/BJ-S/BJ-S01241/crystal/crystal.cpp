#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum[500005];
long long check(long long x)
{
	for(long long i = x;i <= n;i++)
	{
		if(sum[i]-sum[i-x]-b[i]*x <= m) return true;
	}
	return false;
}
main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i = 1;i <= n;i++)
	{
		b[i] = a[n]-a[i];
		sum[i] = sum[i-1]+b[i];
	}
	long long l = 0,r = n,ans;
	while(l <= r)
	{
		long long mid = (l+r)>>1;
		if(check(mid))
		{
			l = mid+1;
			ans = mid;
		}
		else
		{
			r = mid-1;
		}
	}
	cout<<ans;
}
