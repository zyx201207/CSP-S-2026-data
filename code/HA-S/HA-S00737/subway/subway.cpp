#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
int cnt;
int w[500005];
struct node
{
	int v,w;
	bool operator<(const node& x)const{
		return w>x.w;
	}
};
vector<node> vec[1000005];
int dis[1000005];
bool vis[1000005];
void add(int u,int v,int w)
{
	vec[u].push_back({v,w});
	vec[v].push_back({u,w});
	return;
}
priority_queue<node> q;
int Dijstra(int x,int y)
{
	for(int i=1;i<=cnt;i++)dis[i]=INT_MAX;
	dis[x]=0;
	q.push({x,0});
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==y)return dis[u];
		for(int i=0;i<vec[u].size();i++)
		{
			int v=vec[u][i].v;
			int w=vec[u][i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
void clear()
{
	for(int i=1;i<=cnt;i++)dis[i]=0;
	for(int i=1;i<=cnt;i++)vis[i]=0;
	while(!q.empty())q.pop();
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>qq;
	cnt=m;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			if(j!=1)
			{
				add(cnt,cnt+1,0);
				cnt++;
				add(a,cnt,t);
			}
			else add(a,cnt+1,t),cnt++;
		}
	}
	while(qq--)
	{
		int x,y;
		cin>>x>>y;
		cout<<Dijstra(x,y)+w[x]+w[y]<<'\n';
		clear();
	}
	return 0;
}

