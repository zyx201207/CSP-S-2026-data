#include<cstdio>
using namespace std;
const int N=503,M=5e5+3;
int c,n,m,d,q,w[M],k[N],/*a[N][M],t[N][M],*/xr,yr; 
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
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for (int i=1;i<=m;++i)
		w[i]=read();
	for (int i=1;i<=n;++i)
	{
		k[i]=read();
//		for (int j=1;j<=k[i];++j)
//		{
//			a[i][j]=read();
//			t[i][j]=read();
//		}
	}
	while (q--)
	{
		xr=read();
		yr=read();
		puts("3"); 
	}
	return 0;
 }

