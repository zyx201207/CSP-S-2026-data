#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define PII pair<int,int>//ll
const int N=510,M=5e5+10,inf=0x3f3f3f3f;
int n,m,D,q,p[M];
ll w[M];
struct node
{
	int u,v,w;
	bool operator<(const node z1)const
	{
		return w<z1.w;
	}
}a[M];
//priority_queue<node> q;
map<PII,int> mp;
vector<PII> e1[M],e2[N],e[M];
int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}
int dep[M],f[M][20];
void dfs(int u,int fa)
{
	f[u][0]=fa;
	for(int i=1;i<=19;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(auto t:e[u])
	{
		int v=t.first;
		ll w=t.second;
		if(v==fa)continue;
		dep[v]=dep[u]+w;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;i--)
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return f[u][0];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c<=6)
	{
		ll d[444][444];
		memset(d,inf,sizeof(d));
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int v;
				ll t;
				cin>>v>>t;
				if(k!=1)d[m+i][v]=d[v][m+i]=min(d[m+i][v],t);
			}
		}
		for(int k=1;k<=n+m;k++)
			for(int i=1;i<=n+m;i++)
				for(int j=1;j<=n+m;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+d[u][v]<<"\n";
		}
		return 0;
	}
	if(c>=7&&c<=11)
	{
		int mm=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			if(k==1)cin>>k>>k;
			else
			{
				int x,y,T,t;
				cin>>x>>t>>y>>T;
				a[++mm]={x,y,t+T};
			}
		}
		for(int i=1;i<=n;i++)cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<"\n";
		for(int i=1;i<=m;i++)p[i]=i;
		sort(a+1,a+1+mm);
		for(int i=1;i<=mm;i++)
		{
			int pa=find(a[i].u),pb=find(a[i].v);
			if(pa!=pb)
			{
				p[pa]=pb;
				e[a[i].u].push_back({a[i].v,a[i].w});
				e[a[i].v].push_back({a[i].w,a[i].w});
				cnt++;
			}
			if(cnt==m-1)break;
		}
		dfs(1,1);
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			//cout<<lca(u,v)<<" ";
			cout<<w[u]+w[v]+dep[u]+dep[v]-2*dep[lca(u,v)]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v;
			ll t;
			cin>>v>>t;
			e1[v].push_back({i,t});
			e2[i].push_back({v,t});
		}
	}
	for(int i=1;i<=m;i++)p[i]=i;
	for(int u=1;u<=m;u++)
		for(auto t1:e1[u])
		{
			int d=t1.first,w1=t1.second;
			for(auto t2:e2[d])
			{
				int v=t2.first,w=t2.second+w1;
				if(u==v)continue;
				if(!mp.count(make_pair(min(u,v),max(u,v))))mp[make_pair(min(u,v),max(u,v))]=w;
				else mp[make_pair(min(u,v),max(u,v))]=min(mp[make_pair(min(u,v),max(u,v))],w);
//				int pa=find(u),pb=find(v);
//				if(pa!=pb)
				//if(u!=v)q.push({u,v,d});
			}
		}
	int mm=0,cnt=0;
	for(auto t:mp)a[++mm]={t.first.first,t.first.second,t.second};
	sort(a+1,a+1+mm);
	for(int i=1;i<=mm;i++)
	{
		int pa=find(a[i].u),pb=find(a[i].v);
		if(pa!=pb)
		{
			p[pa]=pb;
		//	cout<<a[i].u<<' '<<a[i].v<<"\n";
			e[a[i].u].push_back({a[i].v,a[i].w});
			e[a[i].v].push_back({a[i].w,a[i].w});
			cnt++;
		}
		if(cnt==m-1)break;
	}
	dfs(1,1);
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		//cout<<lca(u,v)<<" ";
		cout<<w[u]+w[v]+dep[u]+dep[v]-2*dep[lca(u,v)]<<"\n";
	}
	return 0;
}
