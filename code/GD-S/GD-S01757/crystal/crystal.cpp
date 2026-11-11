#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],sum[500005];
bool check(long long x)
{
	for(long long i=x;i<=n;i++)
	{
		if(a[i]*x-sum[i]+sum[i-x]<=m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long l=0,r=n+1;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << l << endl;
	return 0;
}
