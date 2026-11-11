#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char c=getchar();
	int op=1,kl=0;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			op=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		kl=kl*10+c-'0';
		c=getchar();
	}
	return op*kl;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	char c[105]={ };
	int cnt=0;
	do{
		c[++cnt]=x%10+'0';
		x/=10;
	}while(x);
	for(int i=cnt;i>=1;i--)
	{
		putchar(c[i]);
	}
	putchar('\n');
}
long long c,n,m,d,q,w[500008],a[501][100001],b[501][1000001],sum=INT_MAX;
void dfs(long long x,long long ti,long long y)
{
	if(x==y)
	{
		sum=min(sum,ti);
		return ;
	}
	for(int i=1;i<=a[x][0];i++)
	{
		dfs(a[x][i],ti+b[x][i]+w[a[x][i]],y);
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		a[i][0]=read();
		for(int j=1;j<=a[i][0];j++)
		{
			a[i][j]=read();
			b[i][j]=read();
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		u=read();
		v=read();
		sum=INT_MAX;
		write(sum+w[u]+w[v]);
	}
}
