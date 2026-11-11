#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[500001],lpos=1,ans=0,sum=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum+=(i-lpos)*(a[i]-a[i-1]);
		while(lpos<=i&&sum>m)sum-=a[i]-a[lpos],lpos++;
		ans=max(ans,i-lpos+1);
	}
	printf("%lld",ans);
	return 0;
}
