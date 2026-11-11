#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int N=510,M=5e5+650,INF=0x3f3f3f3f3f3f3f3f;
int op,n,m,d,Q;
int dis[M*2],vis[M*2],w[M*2];
vector<pr>g[M*2];
void dij(int st)
{
	for(int i=1;i<=m+n;i++)
	{
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<pr,vector<pr>,greater<pr>>q;
	q.push({0,st});
	dis[st]=0;
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto i:g[x])
		{
			int y=i.first,v=i.second;
			if(vis[y]) continue;
			if(dis[x]+v<dis[y])
			{
				dis[y]=dis[x]+v;
				q.push({dis[y],y});
			}
		}
	}
}
struct node{int x,y,id,ans;}q[100050];
bool cmp_x(node a,node b){return a.x<b.x;}
bool cmp_id(node a,node b){return a.id<b.id;}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>op>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;cin>>x>>y;
			g[m+i].push_back({x,y});
			g[x].push_back({m+i,y});
		}
	}
	if(op>=9&&op<=11)
	{
		for(int i=1;i<=Q;i++)
		{
			cin>>q[i].x>>q[i].y;
			q[i].id=i;
		}
		sort(q+1,q+1+Q,cmp_x);
		for(int i=1;i<=Q;i++)
		{
			if(q[i-1].x!=q[i].x)
				dij(q[i].x);
			q[i].ans=dis[q[i].y]+w[q[i].x]+w[q[i].y];
		}
		sort(q+1,q+1+Q,cmp_id);
		for(int i=1;i<=Q;i++)
			cout<<q[i].ans<<'\n';
		return 0;
	}
	while(Q--)
	{
		int x,y;cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}


