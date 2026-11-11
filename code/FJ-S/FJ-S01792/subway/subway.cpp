#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int maxn=505,maxm=5*1e5+5;
int c,n,m,d,q,w[maxm],cnt=0,id2pos[maxm],dist[maxm];
struct Point
{
	int id;
	bool zt;
	vector<pii > g;
};
vector<Point> points;
void add(int u,int v,int w)
{
	points[u].g.push_back({v,w});
}
void dijk(int start)
{
	memset(dist,0x3f,sizeof dist);
	dist[start]=0;
	priority_queue<pii,vector<pii >,greater<pii > > pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		int dis=pq.top().first,u=pq.top().second;
		pq.pop();
		if(dis>dist[u])
			continue;
		for(const auto &i:points[u].g)
		{
			int v=i.first,w=i.second;
			if(dis+w<dist[v])
			{
				dist[v]=dis+w;
				pq.push({dist[v],v});
			}
		}
	}
}
void bfs(int start)
{
	memset(dist,0x3f,sizeof dist);
	dist[start]=0;
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(const auto &i:points[u].g)
		{
			int v=i.first,w=i.second;
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(id2pos,-1,sizeof id2pos);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		points.push_back({i,true});
		int cur=points.size()-1;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			if(id2pos[a]==-1)
			{
				Point tmp={a,false};
				points.push_back(tmp);
				id2pos[a]=points.size()-1;
			}
			a=id2pos[a];
			add(a,cur,t);
			add(cur,a,t);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if(c>=12 and c<=19)
			bfs(x);
		else
			dijk(x);
		cout<<w[x]+w[y]+dist[id2pos[y]]<<'\n';	
	}
	return 0;
}
