#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		maxn+=(i-1)*(a[i]-a[i-1]);
		if(maxn>m)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%lld",n);
	return 0;
}
