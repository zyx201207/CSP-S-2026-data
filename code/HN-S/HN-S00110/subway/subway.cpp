#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 505 , kMaxM = 5e5 + 5 ;
int n , m , d , q ;
ll w[kMaxM] ;
struct subway
{
	int x ;
	ll t ;
};
vector<subway> ve[kMaxM] ;
struct edge
{
	int v ;
	ll w ;
};
vector<edge> G[kMaxN] ;
struct node
{
	int u ;
	ll w ;
	bool operator < (const node &a) const
	{
		return w > a.w ;
	}
};
map<pair<int , int> , ll> mp ;
ll dis[kMaxN][kMaxN] ;
bool vis[kMaxN] ;
void dij(int s)
{
	for( int i = 1 ; i <= n ; i++ ) vis[i] = 0 ;
	dis[s][s] = 0 ;
	priority_queue<node> pq ;
	pq.push({s , 0}) ;
	while(!pq.empty())
	{
		int u = pq.top().u ;
		pq.pop() ;
		if(vis[u]) continue ;
		vis[u] = 1 ;
		for( int i = 0 ; i < G[u].size() ; i++ )
		{
			int v = G[u][i].v ;
			ll w = G[u][i].w ;
			if(dis[s][v] > dis[s][u] + w)
			{
				dis[s][v] = dis[s][u] + w ;
				pq.push({v , dis[s][v]}) ;
			}
		}
	}
}
void solve()
{
	cin >> n ;
	cin >> n >> m >> d >> q ;
	for( int i = 1 ; i <= m ; i++ ) cin >> w[i] ;
	for( int i = 1 ; i <= n ; i++ )
	{
		int k ;
		cin >> k ;
		while(k--)
		{
			int a ;
			ll c ;
			cin >> a >> c ;
			ve[a].push_back({i , c}) ;
		}
	}
	for( int i = 1 ; i <= m ; i++ )
	{
		for( int j = 0 ; j < ve[i].size() ; j++ )
		{
			for( int k = j + 1 ; k < ve[i].size() ; k++ )
			{
				if(!mp.count({ve[i][j].x , ve[i][k].x})) mp[{ve[i][j].x , ve[i][k].x}] = ve[i][j].t + ve[i][k].t ;
				else 
				{
					mp[{ve[i][j].x , ve[i][k].x}] = min(ve[i][j].t + ve[i][k].t , mp[{ve[i][j].x , ve[i][k].x}]) ;
				}
			}
		}
	}
	for( auto it : mp )
	{
		int u = it.first.first , v = it.first.second , w = it.second ;
		G[u].push_back({v , w}) ;
		G[v].push_back({u , w}) ;
	}
	memset(dis , 0x3f , sizeof dis) ;
	for( int i = 1 ; i <= n ; i++ )
	{
		dij(i) ;
	}
	while(q--)
	{
		int x , y ;
		cin >> x >> y ;
		ll minn = 1e18 ;
		for( int i = 0 ; i < ve[x].size() ; i++ )
		{
			for( int j = 0 ; j < ve[y].size() ; j++ )
			{
				minn = min(minn , w[x] + w[y] + ve[x][i].t + ve[y][j].t + dis[ve[x][i].x][ve[y][j].x]) ;
			}
		}
		cout << minn << "\n" ;
	}
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}
/*
OK呀，思路出来了，就是通过点把两条铁路进行连接。

有个坑点，需要只连接最小的边。只要连的条数才是k(k-1) 

然后进行全源最短路，求出答案。然后对于每次查询进行枚举先走哪个地铁，加上W和t

我真是个天才 
*/
