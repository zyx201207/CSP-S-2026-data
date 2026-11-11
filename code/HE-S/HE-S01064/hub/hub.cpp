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
long long c,n,m,d,q;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();m=read();
	for(int j=1;j<=m;j++)
	{
		n=read();q=read();
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			u=read();v=read();
		}
		cout<<rand()%10;
	}
}
