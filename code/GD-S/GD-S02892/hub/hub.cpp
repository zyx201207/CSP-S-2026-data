#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,flag[1000005],f[1000005][21],d[1000005],ans=1e9,dep[1000005];
bool vis[1000005];
int head[1000005],cnt=0;
struct edge{int v,nxt;}e[2000005];
void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
void dfs3(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		f[v][0]=u;
		dfs3(v,u); 
	}
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=20;i>=0;i--) if(dep[f[a][i]]>=dep[b]) a=f[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
	{
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}
void dfs2(int u,int fa)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||!flag[v]) continue;
		dfs2(v,u);
	}
}
void dfs(int x,int tot)
{
	if(tot>k) return;
	if(x>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			d[i]=1e9;
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&flag[i])
			{
				if(sum==2) return;
				sum++;
				dfs2(i,0);
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(flag[j]) d[i]=min(d[i],dep[i]+dep[j]-2*dep[LCA(i,j)]);
			}
			mx=max(mx,d[i]);
		}
		if(mx<ans) ans=mx;
		return;
	}
	flag[x]=1;
	dfs(x+1,tot+1);
	flag[x]=0;
	dfs(x+1,tot);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		cnt=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		ans=1e9;
		dfs3(1,0);
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
