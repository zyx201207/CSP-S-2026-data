#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=6e5+5,inf=1e18;

int T=1,c,n,m,d,Q,pr=-1;

int w[N],k[N],ans[N],dis[N];

bool vis[N];

bool flag=1;

struct query
{
	int x,y;
}qu[N];

struct edge
{
	int v,w;
};

struct node
{
	int u,dis;
};

bool operator<(const node& a,const node& b)
{
	return a.dis>b.dis;
}

vector<edge> e[N];

inline void dijk(int s)
{
	priority_queue<node> q;
	for(int i=1;i<=n+m;i++) dis[i]=inf,vis[i]=0;
	q.push({s,0});
	dis[s]=0;
	int cnt=1;
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1,cnt++;
//		if(cnt==n+m) return;
		for(auto it:e[u])
		{
			int v=it.v,w=it.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}

inline void bfs(int s)
{
	queue<int> q;
	for(int i=1;i<=n+m;i++) dis[i]=inf,vis[i]=0;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	int cnt=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto it:e[u])
		{
			int v=it.v,w=it.w;
			if(vis[v]) continue;
			vis[v]=1,cnt++;
			dis[v]=dis[u]+w;
//			if(cnt==n+m) return;
			q.push(v);
		}
	}
}

void solve()
{
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int a,t,j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			if(pr==-1) pr=t;
			else if(pr!=t) flag=0;
			e[i+m].push_back({a,t});
			e[a].push_back({i+m,t});
		}
	}
	for(int x,y,i=1;i<=Q;i++)
	{
		cin>>x>>y;
		qu[i]={x,y};
		ans[i]=inf;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag) bfs(i+m);
		else dijk(i+m);
		for(int j=1;j<=Q;j++)
		{
			int x=qu[j].x,y=qu[j].y;
			ans[j]=min(ans[j],dis[x]+dis[y]+w[x]+w[y]);
		}
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cin>>T;
	while(T--) solve();
	return 0;
}

