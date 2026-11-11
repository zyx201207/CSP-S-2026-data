#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,query,www[500510];

struct Edge{
	int u,v,w;
};

vector<Edge> g[500510];
priority_queue<pair<int,int> > q;
bool flag[500510];//confirmed
bool inq[500510];
int dis[500510];
bool type01=1;

void add(int u,int v,int w)
{
	g[u].push_back({u,v,w});
}

void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	q.push({0,s});
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		flag[u]=type01;
		q.pop();
		for(auto e:g[u])
		{
			int v=e.v,w=e.w;
			if(flag[v]==type01)continue;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
			}
			q.push({-dis[v],v});
		}
	}
	if(type01)type01=0;
	else type01=1;
}
queue<pair<int,int> > qq;
bool ff[500510];
int bfs(int s,int end)
{
	qq.push({s,0});
	memset(ff,0,sizeof(ff));
	while(!qq.empty())
	{
		auto tb=qq.front();
		qq.pop();
		if(tb.first==end)
		{
			return tb.second;
		}
		ff[tb.first]=1;
		for(auto e:g[tb.first])
		{
			if(ff[e.v])continue;
			qq.push({e.v,tb.second+e.w});
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>query;
	for(int i=1;i<=m;i++)
	{
		cin>>www[i];
	}
	bool B=0;int Btv;
	for(int i=1;i<=n;i++)
	{
		int ki;cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			int V,tv;cin>>V>>tv;
			if(i==1 && j==1)Btv=tv;
			else if(Btv!=tv)B=1;
			Btv=tv;
			add(m+i,V,tv);
			add(V,m+i,tv);
		}
	}
	for(int i=1;i<=query;i++)
	{
		int xi,yi;
		cin>>xi>>yi;
		if(!B)
		{
			cout<<bfs(xi,yi)+www[xi]+www[yi]<<"\n";
			continue;
		}
		dij(xi);
		cout<<dis[yi]+www[xi]+www[yi]<<"\n";
	}
}
