#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=505,M=5e5+5,T=M+M+M,Q=1e5+5;
int c,n,m,d,q,tot,w[M],tid[N],bel[T],dis[T],x[Q],y[Q],rk[M],fa[M];
bool vis[T];
//tid[i]:i站的站厅点编号，bel[i]:该点属于哪个站 
struct Hash
{
	size_t operator()(const pii& p)const
	{
		return (unsigned long long)p.first*1000039+p.second; 
	}
};
unordered_set<int>need;
vector<pii>G[T];
vector<int>to[M];
vector<int>L[M];
unordered_map<pii,int,Hash>ans;
void init()
{
	for(int i=1;i<=n;i++)fa[i]=i,rk[i]=1;
	
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int i,int j)
{
	int x=find(i),y=find(j);
	if(x==y)return ;
	if(rk[x]<rk[y])swap(x,y);
	fa[y]=x;
	if(rk[x]==rk[y])rk[x]++;
}
void add(int u,int v,int w)
{
	G[u].push_back({v,w});
	G[v].push_back({u,w});
}
void dijkstra(int s)
{
	for(int i=1;i<=tot;i++)dis[i]=inf,vis[i]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(pii e:G[u])
		{
			int v=e.first,w=e.second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		int w;
		scanf("%lld",&w);
		add(i,i+m,w);
		tid[i]=i+m;
		bel[i]=i,bel[i+m]=i;
	}
	tot=m<<1;
	for(int i=1;i<=n;i++)
	{
		int k,lst=-1;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%lld%lld",&a,&t);
			add(tid[a],++tot,t);//站厅到站台 
			//printf("u:%lld v:%lld\n",tid[a],tot);
			bel[tot]=j;
			if(lst==-1)lst=tot;
			else add(lst,tot,0);//坐地铁 
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		need.insert(x[i]);
		to[x[i]].push_back(y[i]);
	}
	for(int s:need)
	{
		dijkstra(s);
		for(int t:to[s])ans[{s,t}]=dis[t];
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[{x[i],y[i]}]);
	return 0;
}
