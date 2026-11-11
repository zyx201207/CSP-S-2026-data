#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,INF=1e9;
int C,T,n,m,h[N],cnt,f[N],dis[N],ans;
bool bz[N];
struct Edge
{
	int nxt,to;
}e[N<<1];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
int fnd(int x)
{
	if(f[x]==x) return x;
	return f[x]=fnd(f[x]);
}
bool chk()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(!bz[i]) continue;
		for(int j=h[i];j;j=e[j].nxt)
		{
			int v=e[j].to;
			if(bz[v])
			{
				int tx=fnd(i),ty=fnd(v);
				if(tx!=ty) f[tx]=ty;
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
		if(f[i]==i&&bz[i]) res++;
	return res<=2;
}
void wk(int u,int fa,int dep)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa||bz[v]) continue;
		dis[v]=min(dis[v],dep+1);
		wk(v,u,dep+1);
	}
}
void dfs(int x,int s)
{
	if(x>n)
	{
		if(s!=m) return;
		if(chk())
		{
			for(int i=1;i<=n;i++)
				dis[i]=1e9;
			for(int i=1;i<=n;i++)
				if(bz[i]) wk(i,0,0);
			int maxx=0;
			for(int i=1;i<=n;i++)
			{
				if(!bz[i]) maxx=max(maxx,dis[i]);
			}
//			for(int i=1;i<=n;i++)
//				if(bz[i]) printf("%d ",i);
//			printf("\n  %d\n",maxx);
			ans=min(ans,maxx);
		}
		return;
	}
	if(n-x+1<m-s) return;
	bz[x]=0;
	dfs(x+1,s);
	bz[x]=1;
	dfs(x+1,s+1);
	bz[x]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			h[i]=0;
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v),add(v,u);
		}
		ans=INF;
//		if(C<=3)
//		{
			dfs(1,0);
			printf("%d\n",ans);
			continue;
//		}
//		if(m==1) 
	}
	return 0;
}
