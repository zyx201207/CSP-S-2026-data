#include<bits/stdc++.h>
#define N 500005
typedef long long i64;
i64 n,m,a[N];
int main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	std::sort(a+1,a+n+1);
	i64 c=0,r=1,l=1;
	for(int i=2;i<=n;++i)
	{
 		i64 nc=c+(a[i]-a[i-1])*(i-l);
		while(nc>m)nc-=a[i]-a[l],++l;
		c=nc,r=std::max(r,i-l+1); 
	}
	printf("%lld",r);
	return 0;
}
