#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+3;
long long n,m,a[N],s,l,r,p[N];
long long read()
{
	long long k=1,x=0;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return k*x;
}
long long check(long long b,long long x)
{
	long long i=upper_bound(a+b,a+n+1,x)-a;
	return x*(i-b)+p[b-1]-p[i-1];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i) 
		p[i]=p[i-1]+a[i];
	for (int i=1;i<=n;++i)
	{
		l=a[i];
		r=a[n]+m;
		while (l<r)
		{
			long long mid=(l+r+1)>>1;
			if (check(i,mid)<=m)
				l=mid;
			else
				r=mid-1;
		}
		s=max(s,upper_bound(a+i,a+n+1,l)-a-i);
	 } 
	printf("%lld",s);
	return 0;
 } 
