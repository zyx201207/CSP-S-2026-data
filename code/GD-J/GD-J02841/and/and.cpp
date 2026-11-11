#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2*10000+5],ma;
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ma=max(a[i],ma);
	}
	printf("%lld",ma);
	return 0;
}
