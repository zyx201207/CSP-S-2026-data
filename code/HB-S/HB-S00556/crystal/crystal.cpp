#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
bool check(long long x)
{
	for(long long i=1;i+x-1<=n;i++)//start point
	{
		long long cnt=0;
		cnt=x*a[i+x-1]-(sum[i+x-1]-sum[i-1]);
		if(cnt<=m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,mid,ans;
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
