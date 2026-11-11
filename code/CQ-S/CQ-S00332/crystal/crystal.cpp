//ok
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum[500005];
bool check(long long mid,long long i)
{
	long long cnt=(a[i]*(i-mid+1))-(sum[i]-sum[mid-1]);
	if(cnt>m)
		return 0;
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
		sum[i]=a[i]+sum[i-1];
	for(long long i=n;i>=max(1ll,ans);i--)
	{
		long long l=1,r=i,num=r;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid-1;
				num=mid;
			}
			else
				l=mid+1;
		}
		ans=max(ans,i-num+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
