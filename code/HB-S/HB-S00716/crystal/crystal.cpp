#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,l,r,x,a[500005],s[500005];
bool check(long long ans)
{
	for(long long i=1;i<=n-ans+1;i++)
	{
		if(s[i+ans-1]-s[i-1]>=ans*(a[i+ans-1])-m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	l=1;
	r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << r;
	return 0;
}
