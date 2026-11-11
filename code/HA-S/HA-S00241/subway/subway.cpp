#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N=1e5+5;
vector<PII> g[N];
int dis[N],cnt[N];
int n,m,s;
void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,s});
	while(!q.empty())
	{
		PII p=q.top();
		q.pop();
		int d=p.first;
		int u=p.second;
		if(d>dis[u])
		{
			continue;
		}
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+w)
			{
				cnt[v]=cnt[u]+1;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,c;
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({v,w});
		} 
		dijkstra();
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(cnt[i]==2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
