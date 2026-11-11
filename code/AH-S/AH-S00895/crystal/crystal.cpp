#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],sum[500005];
bool check(long long x)
{
	long long i;
	for(i=x;i<=n;i++)
	{
		long long s=sum[i]-sum[i-x];
		if(a[i]*x-s<=m)
			return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
}
