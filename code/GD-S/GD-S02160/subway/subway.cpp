#include<unordered_map>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 510,M = 5e5,D = 21;
const ll inf = 0x7f7f7f7f7f7f7f7f;
#define pLL pair <ll,int>
int c,n,m,d,q,tot,w[M];
vector <ll> dis;
vector <bool> vis;
vector <pair <int,int>> tmp;
vector <vector <pair <int,int>>> g;
unordered_map <int,int> id;
priority_queue <pLL,vector <pLL>,greater <pLL>> pq;
void dijkstra(int st,int ed)
{
	while(!pq.empty())
		pq.pop();
	for(int i = 1;i <= tot;i++)
		dis[i] = inf,vis[i] = false;
	pq.push(make_pair(0ll,st));
	dis[st] = 0;
	while(!pq.empty())
	{
		pLL f = pq.top();
		pq.pop();
		int u = f.second;
		if(u == ed)
			return;
		if(vis[u])
			continue;
		vis[u] = true;
		for(auto& x : g[u])
		{
			int v = x.first;
			ll w = x.second;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	g.resize(m + 1);
	tot = m;
	tmp.push_back(make_pair(0,0));
	for(int i = 1;i <= n;i++)
	{
		int k,x,y,t,lst = 0;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> x >> t;
			tot++;
			g[x].push_back(make_pair(tot,t));
			tmp[0] = make_pair(x,t);
			g.push_back(tmp);
			if(lst)
			{
				g[tot].push_back(make_pair(lst,0));
				g[lst].push_back(make_pair(tot,0));
			}
			lst = tot;
		}
	}
	dis.resize(tot + 1),vis.resize(tot + 1);
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		dijkstra(x,y);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}

