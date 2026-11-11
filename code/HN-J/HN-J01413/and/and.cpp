#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define gc() getchar() 
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}
void write(int x)
{
	int st[35]={0},top=0,t=0;
	while(x)
	{
		t=x%10;
		st[++top]=t;
		x/=10;
	}
	while(top) putchar(st[top]+'0'),top--;
}
int ans=0;
int n,m,a[1000005],dp[1000005];
void dfs(int u,int s,int sum)
{
	if(s>=m||u>n)
	{
		if(s>=m) ans=max(ans,sum);
		return;
	}
	dfs(u+1,s+1,sum&a[u]);
	dfs(u+1,s,sum);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dfs(1,0,0);
	write(ans);
	return 0;
}
