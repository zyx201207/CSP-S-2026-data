#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[500005];
bool check(long long x)
{
	long long ans=9*1e18;
	for(int i=1;i+x-1<=n;i++)
	{
		long long num=0;
		for(int j=i;j<=i+x-1;j++)
		{
			num+=a[i+x-1]-a[j];
		}
		ans=min(ans,num);
	}
	return ans<=m;
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
	long long l=1,r=n,ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << ans << endl;
}
