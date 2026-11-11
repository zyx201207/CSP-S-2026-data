#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mx=5e5+5;
int c,n,m,d,q;
int w[mx];
int k;
vector<pair<int,int>>p[mx];
vector<pair<int,int>>g[505];
int dis[mx];
bool vis[mx];
void dijkstra(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=m;i++)dis[i]=1e9,vis[i]=0;
	q.push({0,s});
	dis[s]=0;
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(pair<int,int>i:p[u])
		{
			int w=i.second;
			for(pair<int,int> v:g[i.first])
			{
				if(vis[v.first])continue;
				if(dis[u]+w+v.second<dis[v.first])
				{
					dis[v.first]=dis[u]+w+v.second;
					q.push({dis[v.first],v.first}); 
				}
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
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			int x,t;
			cin>>x>>t;
			p[x].push_back({i,t});
			g[i].push_back({x,t});
		}
	}
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		dijkstra(s);
		cout<<dis[t]+w[s]+w[t]<<'\n';
	}
	return 0;
}
/*

48pts~60pts（9~11） 

*/


//许愿；希望能拿一等qwq  
