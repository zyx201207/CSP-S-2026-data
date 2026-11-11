#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=520,M=5e5;
vector<pair<int,int>> e[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int dis[M],w[M];
bool st[M];
int c,n,m,d,Q,ans;
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	memset(st,0,sizeof st);
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty())
	{
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(st[u])continue;
		st[u]=true;
		for(auto x:e[u])
		{
			int w=x.first;
			int v=x.second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=m+1;i<=m+n;i++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			int a,t;
			cin>>a>>t;
			e[i].push_back({t,a});
			e[a].push_back({t,i});
		}
	}
	int p=1e6;
	if(Q>2000)
	{
		while(Q--)
		{
			int s,t;
			cin>>s>>t;
			ans+=w[s]+w[t];
			if(p!=s)dijkstra(s);
			cout<<dis[t]+ans<<'\n';
			ans=0;
			p=s;
		}	
	}
	else
	{
		while(Q--)
		{
			int s,t;
			cin>>s>>t;
			ans+=w[s]+w[t];
			dijkstra(s);
			cout<<dis[t]+ans<<'\n';
			ans=0;
		}
	}
	return 0;
}
