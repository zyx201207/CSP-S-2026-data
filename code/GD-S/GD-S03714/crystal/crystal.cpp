#include <iostream>
#include <algorithm>

using namespace std;

long long n,m,a[1000010],sum,ans;

//bool check(long long d)
//{
//	long long tmp=0;
//	for(long long i=1;i<=d;i++)tmp+=a[d]-a[i];
//	return tmp<=m;
//}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long l=1,r=1;l<=n&&r<=n;l++)
	{
		while(r<=n&&sum<=m)
		{
			r++;
			sum+=(r-l)*(a[r]-a[r-1]);
		}
		ans=max(ans,r-l);
		sum-=(a[r]-a[l]);
	}
	cout<<ans;
//	long long l=1,r=n,mid,ans=0;
//	while(l<=r)
//	{
//		mid=(l+r)>>1;
//		if(check(mid))
//		{
//			ans=mid;
//			l=mid+1;
//		}
//		r=mid-1;
//	}
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
