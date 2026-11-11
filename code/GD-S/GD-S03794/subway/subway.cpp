#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18+7;
int sub_num[510],dis[510][510],a[500010];
struct SUBWAY
{
	int num,tim;
};
vector<SUBWAY> sub[500010];
struct Node
{
	int v,w;
	bool operator < (const Node &t) const
	{
		return w>t.w;
	}
};
vector<Node> G[510];
bool vis[510][510];
void Dijkstra(int st)
{
	priority_queue<Node> q;
	q.push({st,0});
	dis[st][st]=0;
	while(!q.empty())
	{
		Node t=q.top();q.pop();
		int u=t.v;
		if(vis[st][u]) continue;
		vis[st][u]=true;
		for(auto i:G[u])
		{
			int v=i.v,w=i.w;
			if(dis[st][v]>dis[st][u]+w)
			{
				dis[st][v]=dis[st][u]+w;
				q.push({v,dis[st][v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int ttt,n,m,d,q;
	cin>>ttt>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>sub_num[i];
		for(int j=1;j<=sub_num[i];j++)
		{
			int x,y;cin>>x>>y;
			sub[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(sub[i].size()>1)
		{
			for(auto j:sub[i])
			{
				for(auto k:sub[i])
				{
					G[j.num].push_back({k.num,j.tim+k.tim});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) Dijkstra(i);
	while(q--)
	{
		int x,y,ans=INF;
		cin>>x>>y;
		for(auto i:sub[x])
		{
			for(auto j:sub[y])
			{
				if(ans>dis[i.num][j.num]+i.tim+j.tim)
				{
					ans=dis[i.num][j.num]+i.tim+j.tim;
				}
			}
		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}
