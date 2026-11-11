#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
int g[311][311],a[N+11],hav[311][311];
inline int read()
{
	int f=0,k=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')k=-1;
		c=getchar();
	}
	while(isdigit(c))
		f=f*10+c-'0',c=getchar();
	return k*f;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c=read(),t=read();
	while(t--)
	{
		int n=read(),d=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		if(c>6)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=LLONG_MAX,hav[i][j]=0;
		for(int i=1;i<=n;i++)
			g[i][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
					hav[i][j]=g[i][j]=1;
				else break;
			}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=i;k<=j;k++)
					if(g[i][k]!=LLONG_MAX&&g[k][j]!=LLONG_MAX)
					{
						if(g[i][k]+g[k][j]<g[i][j])
							g[i][j]=g[i][k]+g[k][j],hav[i][j]=hav[i][k]*hav[k][j];
						else if(g[i][k]+g[k][j]==g[i][j])
							hav[i][j]+=hav[i][k]*hav[k][j];
					}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=4;j<=n;j++)
				if(hav[i][j]==2)
					ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
