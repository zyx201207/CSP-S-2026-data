#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,r,da,q,h,z,md;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	l=1,r=1;
	for(long long i=1;i<=n;i++)
	{
		z=a[i]*(i-l)-(b[i-1]-b[l-1]);
		while(z>m)
		{
			l++;
			z=a[i]*(i-l)-(b[i-1]-b[l-1]);
		}
		da=max(da,i-l+1); 
	}
	printf("%lld",da);
	return 0;
}
//ø¥¥ÌÃ‚œÌ∏£¡À 
