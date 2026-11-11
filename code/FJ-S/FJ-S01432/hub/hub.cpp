#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,m;
vector<int> g[1000010];
bool bb[1000010];
int fa[1000010];
int dis[1000010];
bool b[1000010];
int ans=1e9;
inline int Find(int k){if(k==fa[k]) return k;return fa[k]=Find(fa[k]);}
inline void Merge(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x!=y) fa[y]=x;
}
inline void dfs(int k,int ss)
{
	b[k]=1;
	dis[k]=min(dis[k],ss);
	for(register int i=0;i<g[k].size();i++)
	{
		int x=g[k][i];
		if(b[x]) continue;
		dfs(x,ss+1);
	}
	b[k]=0;
}
inline void dfs1(int k)
{
	if(k>n)
	{
		int cnt=0;
		for(register int i=1;i<=n;i++) cnt+=bb[i];
		if(cnt!=m) return;
		for(register int i=1;i<=n;i++) if(bb[i]) fa[i]=i;
		for(register int i=1;i<=n;i++)
			for(register int j=0;j<g[i].size();j++)
			{
				int u=i,v=g[i][j];
				if(bb[u]&&bb[v]) Merge(u,v);
			}
		int sss=0;
		for(register int i=1;i<=n;i++) if(bb[i]) if(Find(i)==i) sss++;
		if(sss>=3) return;
		for(register int i=1;i<=n;i++) dis[i]=1e9;
		for(register int i=1;i<=n;i++)
		{
			if(!bb[i]) continue;
			dfs(i,0);
		}
		int sum=0;
		for(register int i=1;i<=n;i++) sum=max(sum,dis[i]);
		ans=min(ans,sum);
		return;
	}
	bb[k]=0,dfs1(k+1),bb[k]=1,dfs1(k+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(register int i=1;i<=n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v),g[v].push_back(u);
		}
		ans=1e9,dfs1(1);
		printf("%d\n",ans);
		for(register int i=1;i<=n;i++)
		{
			vector<int> ().swap(g[i]);
			bb[i]=0,fa[i]=0,dis[i]=0,b[i]=0;
		}
	}
	return 0;
}
