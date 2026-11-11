#include <bits/stdc++.h>
using namespace std ;

const int M = 500005 ;
const int N = 505 ;
#define PII pair<int,int>

int c , n , m , d , q ;
int w[M] ;
PII g[M][N] ;
unordered_map<int,int> l[M] ;
map<PII,int> ans ;

map<PII,int> dist ;
map<PII,bool> visited ;
int dijkstra( int &x , int &y )
{
	dist.clear();
	visited.clear();
    priority_queue<pair<int,PII >,vector<pair<int,PII > >,greater<pair<int,PII > > > heap ;
    for ( PII i : l[x] ) heap.push({i.second,{x,i.first}});
    while ( !heap.empty() )
    {
        pair<int,PII > ht = heap.top() ;
        heap.pop() ;
        int v = ht.second.first ;
        int k = ht.second.second ;
        int w = ht.first ;
        if ( visited[{v,k}] ) continue ;
        visited[{v,k}] = true ;
        dist[{v,k}] = w ;
        ans[{x,v}] = ans[{v,x}] = min(ans[{x,v}],w+l[v][k]);
        if ( ans[{x,v}] == 0 ) ans[{x,v}] = ans[{v,x}] = w+l[v][k] ;
        if ( g[v][k].first != 0 ) heap.push({w,{g[v][k].first,k}});
        if ( g[v][k].second != 0 ) heap.push({w,{g[v][k].second,k}});
        int out = l[v][k] ;
        for ( PII i : l[v] )
        {
            if ( i.first == k ) continue ;
            int neww = w + out + i.second ;
            if ( dist[{v,i.first}] == 0 || dist[{v,i.first}] > neww )
            {
                dist[{v,i.first}] = neww ;
                heap.push({neww,{v,i.first}}) ;
            }
        }
    }
    return ans[{x,y}] ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for ( int i = 1 ; i <= m ; i ++ ) scanf("%d",&w[i]);
    int k , a , t , last_a , last_last_a ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        scanf("%d",&k);
        last_a = 0 , last_last_a = 0 ;
        for ( int j = 1 ; j <= k ; j ++ )
        {
            scanf("%d%d",&a,&t);
            l[a][i] = t ;
            g[last_a][i] = {last_last_a,a};
            last_last_a = last_a ;
            last_a = a ;
        }
		g[last_a][i] = {last_last_a,0} ;
    }
    int x , y , asn ;
    while ( q -- )
    {
        scanf("%d%d",&x,&y);
        asn = ans[{x,y}] ;
        if ( asn == 0 ) asn = dijkstra(x,y);
        printf("%d\n",asn+w[x]+w[y]);
    }
    return 0 ;
}

