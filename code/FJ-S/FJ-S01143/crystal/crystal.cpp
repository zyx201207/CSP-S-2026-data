#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],sum[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(long long i=1,j=1;i<=n;i++)
	{
		while(j<=i&&(i-j+1)*a[i]-(sum[i]-sum[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
