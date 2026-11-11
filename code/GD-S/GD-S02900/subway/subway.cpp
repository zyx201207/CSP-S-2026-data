#include<bits/stdc++.h>
#define int long long
#define pa pair<int,int>
#define fre freopen("subway.in","r",stdin),freopen("subway.out","w",stdout)
using namespace std;
const int MAXN=5e5+34,inf=1e16;
struct asd{
	vector<int> to,to_l;
}g[MAXN];
int n,m,d,c,q,dis[666][666],a[MAXN];
void add(const int u,const int v,const int w){g[u].to.push_back(v),g[u].to_l.push_back(w);}
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(const int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	fre,c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1,k;i<=n;i++)
	{
		k=read();
		for(int u,w;k;k--) u=read(),w=read(),add(u,i,w);
		for(int j=1;j<=n;j++) dis[i][j]=inf;
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<g[i].to.size();j++)
			for(int k=0;k<g[i].to.size();k++)
				if(j!=k) dis[g[i].to[j]][g[i].to[k]]=g[i].to_l[j]+g[i].to_l[k];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[j][i]=dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	for(int u,v,ans;q;q--)
	{
		u=read(),v=read(),ans=inf;
		for(int i=0;i<g[u].to.size();i++)
			for(int j=0;j<g[v].to.size();j++)
				ans=min(ans,dis[g[u].to[i]][g[v].to[j]]+g[u].to_l[i]+g[v].to_l[j]);
		write(ans+a[u]+a[v]),putchar('\n');
	}
	return 0;
}
