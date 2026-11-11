#include<bits/stdc++.h>
#define N 1000005
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,U[N],V[N],k,now,head[N],to[N*2],nxt[N*2],vis[N],dis[N];
void add(int x,int y)
{
	to[++now]=y;
	nxt[now]=head[x];
	head[x]=now;
}
void clear()
{
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=now;i++) to[i]=nxt[i]=0;
	now=0;
}
void dfs(int x,int fa,int d)
{
	dis[x]=min(dis[x],d);
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa) continue;
		dfs(v,x,d+1);
	}
}
int fa[N],sz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y,sz[y]+=sz[x];
	return;
}
namespace s2
{
int U[N],V[N],ban;
struct Edge{int to,id;};
vector<Edge> e[N];
int f[N],g[N],dep[N];
void dfs1(int x,int fa)
{
	f[x]=0;
	for(int i=0;i<e[x].size();i++)
	{
		int id=e[x][i].id,v=e[x][i].to;
		if(id==ban) continue;
		if(v==fa) continue;
		dfs1(v,x);
		f[x]=max(f[x],f[v]+1);
	}
}
int root;
void dfs2(int x,int fa)
{
	multiset<int> s;
	for(int i=0;i<e[x].size();i++)
	{
		int id=e[x][i].id,v=e[x][i].to;
		if(id==ban) continue;
		if(v==fa) continue;
		s.insert(f[v]+2);
	}
	for(int i=0;i<e[x].size();i++)
	{
		int id=e[x][i].id,v=e[x][i].to;
		if(id==ban) continue;
		if(v==fa) continue;
		s.erase(s.find(f[v]+2));
		g[v]=max(g[x]+1,s.empty()?0:*s.rbegin());
		dfs2(v,x);
		s.insert(f[v]+2);
	}
	dep[x]=max(f[x],g[x]);
	if(dep[x]<dep[root]) root=x;
}
struct node
{
	int x,h;
	bool operator <(const node& t)const
	{
		return h<t.h;
	}
};
priority_queue<node> q;
bool vis[N];
void solve()
{
	dep[0]=1e9;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		U[i]=x,V[i]=y;
		e[x].push_back({y,i});
		e[y].push_back({x,i});
	}
	int mn=1e9;
	int rt;
	ban=0;
	dfs1(1,0),g[1]=0,dfs2(1,0),rt=root,root=0;
	dfs1(rt,0);
	for(int i=1;i<=n;i++) vis[i]=false;
	vis[rt]=true;
	while(!q.empty()) q.pop();
	for(int i=0;i<e[rt].size();i++)
	{
		int id=e[rt][i].id,v=e[rt][i].to;
		q.push({v,f[v]});
	}
	for(int _=1;_<=k-1;_++)
	{
		int x=q.top().x;
		q.pop();
		vis[x]=true;
		for(int i=0;i<e[x].size();i++)
		{
			int id=e[x][i].id,v=e[x][i].to;
			if(vis[v]) continue;
			q.push({v,f[v]});
		}
	}
	mn=min(mn,q.top().h+1);
	for(ban=1;ban<=n-1;ban++)
	{
		int rt1,rt2;
		dfs1(U[ban],0),g[U[ban]]=0,dfs2(U[ban],0),rt1=root,root=0;
		dfs1(V[ban],0),g[U[ban]]=0,dfs2(V[ban],0),rt2=root,root=0;
		dfs1(rt1,0),dfs1(rt2,0);
		for(int i=1;i<=n;i++) vis[i]=false;
		vis[rt1]=vis[rt2]=true;
		while(!q.empty()) q.pop();
		for(int i=0;i<e[rt1].size();i++)
		{
			int id=e[rt1][i].id,v=e[rt1][i].to;
			if(id==ban) continue;
			if(v==rt2) continue;
			q.push({v,f[v]});
		}
		for(int i=0;i<e[rt2].size();i++)
		{
			int id=e[rt2][i].id,v=e[rt2][i].to;
			if(id==ban) continue;
			if(v==rt1) continue;
			q.push({v,f[v]});
		}
		for(int _=1;_<=k-2;_++)
		{
			int x=q.top().x;
			q.pop();
			vis[x]=true;
			for(int i=0;i<e[x].size();i++)
			{
				int id=e[x][i].id,v=e[x][i].to;
				if(id==ban) continue;
				if(vis[v]) continue;
				q.push({v,f[v]});
			}
		}
		mn=min(mn,q.top().h+1);
	}
	printf("%d\n",mn);
	return;
}
}
void solve()
{
	clear();
	n=read(),k=read();
	if(n>10)
	{
		s2::solve();
		return;
	}
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
		U[i]=x,V[i]=y;
	}
	int ans=n+1;
	for(int S=0;S<(1<<n);S++) if(__builtin_popcount(S)==k)
	{
		for(int i=1;i<=n;i++) vis[i]=((S>>(i-1))&1);
		for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,dis[i]=n+1;
		for(int i=1;i<=n-1;i++) if(vis[U[i]]&&vis[V[i]]) merge(U[i],V[i]);
		int cnt=0;
		for(int i=1;i<=n;i++) if(fa[i]==i) cnt++;
		if(cnt>n-k+2) continue;
		for(int i=1;i<=n;i++) if(vis[i]) dfs(i,0,0);
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
		ans=min(ans,mx); 
	}
	printf("%d\n",ans);
	return;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--) solve();
	return 0;
}

