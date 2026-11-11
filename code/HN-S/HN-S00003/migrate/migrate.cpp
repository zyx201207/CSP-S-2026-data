#include<cstdio>
using namespace std;
const int N=2e6+3;
long long c,t,n,d,x[N];
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
void A()
{
	while (t--)
	{
		n=read();
		d=read();
		for (int i=1;i<=n;++i)
			x[i]=read();
		if (x[2]-x[1]>d)
			puts("0");
		else
			printf("%lld\n",n*(n-1)>>1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	if (c==11||c==12)
		A();
	return 0;
 }

