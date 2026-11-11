#include<bits/stdc++.h>
using namespace std;

const int qwq=500010;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long n,ans;
long long m,a[qwq];
namespace Hg
{
	bool check(long long x)
	{
		long long sum=0;
		for(int i=1;i<x;i++) sum+=a[x]-a[i];
		if(sum<=m) return 1;
		for(int i=x;i<n;i++)
		{
			sum+=(a[i+1]-a[i])*x;
			sum-=a[i]-a[i-x+1];
			if(sum<=m) return 1;
		}
		return 0;
	}
	inline void QvQ()
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		long long l=1,r=n;
		while(l<r)
		{
			long long mid=(l+r+1)>>1;
			if(check(mid)) l=mid,ans=mid;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
	inline void QwQ()
	{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	}
}
int main()
{
	Hg::QwQ();
	Hg::QvQ();
	return 0;
}
