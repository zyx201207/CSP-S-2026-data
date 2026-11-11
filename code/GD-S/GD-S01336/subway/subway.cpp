#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;

struct edge{ int v ; long long w ; } ;
vector<edge> g[N] ;

int c , n , m , d , q ;
long long w[N] , dis[N] ;

void dj( int s , int t )
{
	for(int i = 1 ; i <= m ; i++ )
	{
		dis[i] = 1e18 ;
	}
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int> > > q ;
	q.push({0,s}) ;
	dis[s] = 0 ;
	while(!q.empty())
	{
		long long d = q.top().first ;
		int u = q.top().second ;
		q.pop() ;
		
		if( d > dis[u]) continue ;
 
		for(int i = 0 ; i < g[u].size() ; i++ )
		{
			int v = g[u][i].v ;
			long long w = g[u][i].w ;
			
			if( dis[v] > dis[u] + w )
			{
				dis[v] = dis[u] + w ;
				q.push({dis[v],v}) ;
			}
		}
	}
	dis[t] += w[s] + w[t] ;
	printf("%lld\n",dis[t]) ;
}
int main()
{
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q) ;
	
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%lld",&w[i]) ; 
	}
	
	for(int i = 1 ; i <= n ; i++ )
	{
		int k , last_a , last_t , a , t ;
		
		scanf("%d%d%d",&k,&last_a,&last_t) ;
		
		for(int j = 2 ; j <= k ; j++ )
		{
			scanf("%d%d",&a,&t) ;
			g[last_a].push_back({a,t+last_t}) ;
			g[a].push_back({last_a,t+last_t}) ;
		}
	}

	for(int i = 1 ; i <= q ; i++ )
	{
		int x , y ;
		
		scanf("%d%d",&x,&y) ;
		
		dj(x,y) ;
	}
	
	return 0 ; 
} 
