#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],a[510][N/500+10],t[510][N/500+10],k[510];
vector<pair<int,int> >v[1010];
int dist[N];
void dijkstra(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push({0,s});
	while(q.size())
	{
		int pos=q.top().second,t=q.top().first;
		q.pop();
		if(t>dist[pos]) continue;
		for(int i=0;i<v[pos].size();i++)
		{
			int pos1=v[pos][i].first,t1=v[pos][i].second;
			if(dist[pos1]>dist[pos]+t1)
			{
				dist[pos1]=dist[pos]+t1;
				q.push({dist[pos1],pos1});
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int nothing,n,m,q;
	cin>>nothing>>n>>m>>nothing>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int k1=1;k1<=k[i];k1++) v[a[i][j]].push_back({a[i][k1],0});
			v[a[i][j]+m].push_back({a[i][j],t[i][j]});
			v[a[i][j]].push_back({a[i][j]+m,t[i][j]});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x+m);
		cout<<dist[y+m]+w[x]+w[y]<<"\n";
	}
	return 0;
}
