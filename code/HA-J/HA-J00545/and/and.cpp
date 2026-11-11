#include<bits/stdc++.h>
using namespace std;
long long b[200010];
bool a[200010];
int n,m;
inline long long read()
{
	long long x=0;int f=1;
	char c=getchar();
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
long long dfs(int c,long long zhi)
{
	if(c==m)
	{
		return zhi;
	}
	long long maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			if(zhi&b[i]==0)continue;
			maxx=max(maxx,dfs(c+1,zhi&b[i]));
			a[i]=0;
		}
	}
	return maxx;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	long long maxxx=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=1;
		maxxx=max(maxxx,dfs(1,b[i]));
		a[i]=0;
	}
	cout<<maxxx;
	return 0;
}

