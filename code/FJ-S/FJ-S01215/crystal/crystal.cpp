#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;

long long n,m,a[N],sum[N],ans=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	long long j=1;
	for(long long i=2;i<=n;i++)
	{
		while(sum[i]-sum[j]-(a[i]-a[j])*(j-1)>m && j<i) j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	
	return 0;
}

