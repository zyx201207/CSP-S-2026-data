#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,tot=1,ans=1;
LL m,a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		while(tot<=i&&(LL)(i-tot)*a[i]-(sum[i-1]-sum[tot-1])>m) tot++;
		ans=max(ans,i-tot+1);
	}
	printf("%d",ans);
	return 0;
}
