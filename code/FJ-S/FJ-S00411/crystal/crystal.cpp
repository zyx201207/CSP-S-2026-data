#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,a[500010],d[500010];
bool check(long long x)
{
	for (int ri=x;ri<=n;ri++)
	{
		int le=ri-x;
		if (a[ri]*x-(d[ri]-d[le])<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	d[0]=0;
	for (int i=1;i<=n;i++)d[i]=a[i]+d[i-1];
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if (check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

