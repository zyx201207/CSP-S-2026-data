#include <bits/stdc++.h>
#define ll long long
using namespace std ;

const int MAXM = 5e5+5 ; const int MAXN = 505 ;
int c , n , m , d , q , sum , ans ;
int cost[MAXM] , dis[MAXN+MAXM] ;
bool vis[MAXM+MAXN] ;
struct edge
{
	int to , val , nxt ;	
}G[MAXM<<1]; int head[MAXN] , cnt ;
void add_edge(int u , int v , int w) {G[++cnt] = (edge){v,w,head[u]} ; head[u] = cnt ;}

struct code
{
	int id , w ;
	bool operator < (const code &x) const { return w > x.w ; }
} ;

int dijkstra(int st , int ed )
{
	for (int i = 1 ; i <= m ; i++) { dis[i] = 0x3f3f3f3f; vis[i] = 0 ; }
	for (int i = 1+MAXM ; i <= n+MAXM ; i++) { dis[i] = 0x3f3f3f3f; vis[i] = 0 ; }
	priority_queue <code> pq ; dis[st] = 0 ; pq.push((code){st,0}) ;
	while(!pq.empty())
	{
		int u = pq.top().id ; pq.pop() ;
		if (vis[u]) continue ; vis[u] = 1 ;
		for (int i = head[u] , v , w ; i ; i = G[i].nxt )
		{
			v = G[i].to , w = G[i].val ;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u]+w ;
				pq.push((code){v,dis[v]}) ;
			}
		}
	}
	return dis[ed] ;
}


int main()
{
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> c >> n >> m >> d >> q ;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> cost[i] ;
	}
	for (int u = MAXM+1 , k ; u <= MAXM+n ; u++)
	{
		cin >> k ;
		for (int i = 1 , v , w ; i <= k ; i++)
		{
			cin >> v >> w ;
			add_edge(u,v,w) ; add_edge(v,u,w) ;
		}
	}
	for (int i = 1 , u , v ; i <= q ; i++)
	{
		cin >> u >> v ; ans = cost[u]+cost[v] ;
		ans += dijkstra(u,v) ;
		cout << ans << "\n" ;
	}
	return 0 ;
}
 
 
 
 
