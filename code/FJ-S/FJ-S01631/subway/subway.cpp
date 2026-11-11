#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N=5e5+510;
int c,n,m,d,q,w[N];
bool st[N];
ll dist[N];
vector<pair<int,int>> g[N];
void dijzstra(int s)
{
	for(int i=1;i<=n+m;i++) dist[i]=0x3f3f3f3f,st[i]=0;
	dist[s]=0;
	priority_queue<pli,vector<pli>,greater<pli>> q;
	q.push({0,s});
	while(q.size())
	{
		pli t=q.top();
		q.pop();
		int u=t.second,v=t.first;
		if(st[u]) continue;
		st[u]=1;
		for(pli x:g[u])
		{
			ll i=x.first,j=x.second;
			if(dist[j]>dist[u]+i)
			{
				dist[j]=dist[u]+i;
				q.push({dist[j],j});
			}
		}
	}
}
void bfs(int s)
{
	for(int i=1;i<=n+m;i++) dist[i]=0x3f3f3f3f,st[i]=0;
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(auto y:g[u])
		{
			int x=y.second;
			if(st[u]) continue;
			st[u]=1;
			dist[x]=dist[u]+1;
			q.push(x);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			g[m+i].push_back({y,x});
			g[x].push_back({y,m+i});
		}
	}
	if(c>=12&&c<=19)
	{
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		ll _time=w[s]+w[e];
		ll t=g[1][0].first;
		bfs(s);
		
		_time+=dist[e]*t;
		cout<<_time<<"\n";
	}
	}
	else
	{
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		ll _time=w[s]+w[e];
		dijzstra(s);
//		for(int i=1;i<=m;i++) cout<<dist[i]<<" ";cout<<"\n";
		
		_time+=dist[e];
		cout<<_time<<"\n";
	}
	}
	
	return 0;
}
