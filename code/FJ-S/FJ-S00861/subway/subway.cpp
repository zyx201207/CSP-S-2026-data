#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int w[500005];
int t[505][500005];
int dis[505][505];
int id[505];
int vis[505];
vector <pair<int,int> > mapp[505];
int c,n,m,d,q;
void dij(int s)
{
	memset(vis,0,sizeof(vis));
	memset(id,0,sizeof(id));
	memset(dis,63,sizeof(dis));
	for(int i = 1 ;i <= n ; i ++) dis[s][i] = 1e9 + 7;
	priority_queue<pair<int,int> > pq;
	dis[s][s] = 0;
	id[s] = 0;
	pq.push(make_pair(0,s)); 
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for(auto i : mapp[u])
		{
			int v = i.first;
			if(vis[v]) continue;
			int w = 0;
			if(id[u] != i.second && u != s)
			{
				w += t[id[u]][u] + t[i.second][u];
			}
			if(u == s)
			{
				w += t[i.second][u];
			}
			if(dis[s][v] > dis[s][u] + w)
			{
				id[v] = i.second;
				dis[s][v] = dis[s][u] + w;
				pq.push(make_pair(-dis[s][v],v));
			}
		}
		vis[u] = 1;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;  i <= m ; i ++) cin>>w[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		int k;
		cin>>k;
		int last = 0,crr;
		for(int j = 1 ; j <= k ; j ++)
		{
			cin>>crr;
			cin>>t[i][crr];
			mapp[last].push_back(make_pair(crr,i));
			last = crr; 
		}
	} 
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		dij(a);
		cout<<dis[a][b] + w[a] + w[b] + t[id[b]][b]<<endl;	
	}
	return 0;
}
