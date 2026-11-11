#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
struct E
{
	int nex;
	int to;
	int w;
}e[500005];
int h[500005],bs;
int to[505],W[505];
int f[505][505];
char buf[1<<20],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p1=(p2=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p2++)
inline void read(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cid,n,m,d,q;
	read(cid),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1,k;i<=n;i++)
	{
		read(k);
		for(int j=1,x,t;j<=k;j++)
		{
			read(x),read(t);
			e[++bs]={h[x],i,t};
			h[x]=bs; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int l=0;
		for(int j=h[i];j;j=e[j].nex)
		{
			to[++l]=e[j].to;
			W[l]=e[j].w;
		}
		for(int j=1;j<=l;j++)
		{
			for(int k=1;k<=l;k++)
			{
				f[to[j]][to[k]]=min(f[to[j]][to[k]],W[j]+W[k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		read(x),read(y);
		int ans=1e18;
		for(int j=h[x];j;j=e[j].nex)
		{
			for(int k=h[y];k;k=e[k].nex)
			{
				ans=min(ans,e[j].w+e[k].w+f[e[j].to][e[k].to]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
