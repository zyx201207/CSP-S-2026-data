#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 510;
const int maxm = 5e5+10;
// 待优化 
struct edge
{
	int u,v,w;
};
// 线路数是n<=500，地铁站数是m<=5e5+10 
vector<edge> ed,mst;
int w[maxm],k[maxn];
int fa[maxn+maxm];
int find_dsu(int x)
{
	return (fa[x]==x?x:fa[x]=find_dsu(fa[x]));
}
bool combine(int x, int y)
{
	int a=find_dsu(x),b=find_dsu(y);
	if(a==b) return false;
	fa[x]=y;
	return true;
}
int n,m,d,q;
void kruskal()
{
	int uc=n+m;
	sort(ed.begin(),ed.end(),[&](edge a, edge b){
		return a.w<b.w;
	});
	for(int i=0;i<ed.size();i++)
	{
		if(uc==1) break;
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if(!combine(u,v)) continue;
		mst.push_back(ed[i]);
		uc--;
	}
}

struct Edge
{
	int to,nxt,w;
} e[(maxm+maxn)<<1];
int head[maxn+maxm],tot;
void addedge(int u, int v, int w)
{
	e[++tot]={v,head[u],w};
	head[u]=tot;
}
int go[maxn+maxm][21],dep[maxn+maxm];
ll len[maxn+maxm];
void dfs(int u, int fa)
{
	go[u][0]=fa;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to,w=e[i].w;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		len[v]=len[u]+w;
		dfs(v,u);
	}
}
void preprocess()
{
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n+m;i++)
		{
			go[i][j]=go[go[i][j-1]][j-1];
		}
	}
}
int lca(int u, int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=20;j>=0;j--) if(dep[go[u][j]]>=dep[v]) u=go[u][j];
	if(u==v) return u;
	for(int j=20;j>=0;j--) if(go[u][j]!=go[v][j]) 
	{
		u=go[u][j];
		v=go[v][j];
	}
	return go[u][0];
}
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	//ed.reserve(maxm);
	iota(fa,fa+n+m+1,0);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) // 第i条线路 
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t; // 线路链接站台编号以及站台走到站厅的时间 
			cin>>a>>t;
			ed.push_back({a,i+m,t});
		}
	}
	kruskal();
	for(int i=0;i<mst.size();i++)
	{
		addedge(mst[i].u,mst[i].v,mst[i].w);
		addedge(mst[i].v,mst[i].u,mst[i].w);
	}
	dfs(1,0);
	preprocess();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<len[x]+len[y]-2*len[lca(x,y)]+w[x]+w[y]<<'\n';
	}
	//cout<<(&a-&b)/1024/1024;
	// 映射：每个地铁站i映射到i，方便取w和查询。线路i映射到节点i+m 
	fclose(stdin);
	fclose(stdout);
}
