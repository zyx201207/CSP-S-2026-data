#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+505;
int w[maxn];
vector<pair<int,int> >g[maxn];
int dist[maxn],vis[maxn];
int c,n,m,d,q;
int dj(int s,int t)
{
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dist[s]=0;
	q.push({0,s});
	while(q.size())
	{
		int node=q.top().second;
		q.pop();
		if(vis[node])continue;
		vis[node]=1;
		for(int i=0;i<g[node].size();i++)
		{
			int nnode=g[node][i].first;
			int val=g[node][i].second;
			if(dist[nnode]>dist[node]+val)
			{
				dist[nnode]=dist[node]+val;
				q.push({dist[nnode],nnode});
			}
		}
	}
	return dist[t];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+dj(s,t)<<"\n";
	}
	return 0;
}

