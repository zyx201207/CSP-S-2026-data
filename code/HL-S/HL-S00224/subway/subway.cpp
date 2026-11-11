#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
struct node{
	int v,w;
};
const int MAXN=205;
vector<node> e[MAXN];
vector<node> line[MAXN];
int cost[MAXN];
int dis[MAXN];
bool vis[MAXN];
int c,n,m,d,q;//n:地铁线路数   m:地铁站数 
void solve(int s,int t)
{
	priority_queue<PII,vector<PII>,greater<PII> > q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].v;
			int w=e[u][i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	cout<<dis[t]+cost[s]+cost[t]<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>cost[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a[k+1];
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			a[j]=v;
			line[i].push_back({v,w});
		}
		for(int j=1;j<=k;j++)
		{
			for(int op=j+1;op<=k;op++)
			{
				e[j].push_back({op,line[i][j].w});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
