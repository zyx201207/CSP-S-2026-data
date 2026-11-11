#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010],maxx;

void in(int &x)
{
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}

void out(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}

void dfs(int u,int x,int h)
{
	if(u==n+1||!x)
	{
		maxx=max(maxx,h);
		return;
	}
	if(n-u==x)
	{
		for(int i=u+1;i<=n;i++) h&=a[i];
		maxx=max(maxx,h);
		return;
	}
	dfs(u+1,x,h);
	dfs(u+1,x-1,h&a[u]);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	in(n),in(m);
	for(int i=1;i<=n;i++) in(a[i]);
	dfs(1,m,INT_MAX);
	out(maxx);
	return 0;
}
