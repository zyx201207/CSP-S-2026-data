#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],pr[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while((i-j+1)*a[i]-(pr[i]-pr[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
}
