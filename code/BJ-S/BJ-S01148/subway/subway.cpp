#include <cstdio>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e7 + 50, M = 5e5 + 50;
struct edge
{
    int to, w;
    bool operator >( const edge &e )
    const
    {
        return w > e.w;
    }
};
vector< edge > G[ N ];
int c, n, m, d, q;
int w[ M ], to[ M ], cost[ M ];
bool vis[ M ];
int dis[ M ];
int dijkstra( int s, int t )
{
    for( int i = 1; i <= m; ++i )
        dis[ i ] = 1e9;
    priority_queue< edge, vector< edge >, greater< edge > > pq;
    vis[ s ] = true;
    pq.push( { s, 0 } );
    dis[ s ] = 0;
    while( !pq.empty() )
    {
        edge now = pq.top();
        pq.pop();
        int u = now.to;
        vis[ u ] = true;
        for( edge v : G[ u ] )
        {
            if( !vis[ v.to ] )
                pq.push( v );
            if( dis[ u ] + now.w < dis[ v.to ] )
                dis[ v.to ] = dis[ u ] + now.w;
        }
        if( vis[ t ] )
        {
            for( int i = 1; i <= m; ++i )
                vis[ i ] = false;
            return dis[ t ];
        }
    }
    return 0;
}

int main( int argc, char *argv[] )
{
   freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    scanf( "%d%d%d%d%d", &c, &n, &m, &d, &q );
    for( int i = 1; i <= m; ++i )
        scanf( "%d", &w[ i ] );
    int node = m;
    for( int l = 1; l <= n; ++l )
    {
        int k{};
        scanf( "%d", &k );
        for( int j = 1; j <= k; ++j )
            scanf( "%d%d", &to[ j ], &cost[ j ] );
        G[ to[ 1 ] ].push_back( { ++node, cost[ 1 ] } );
        G[ node ].push_back( { to[ 1 ], cost[ 1 ] } );
        for( int i = 2; i <= k; ++i )
        {
            G[ node ].push_back( { node + 1, 0 } );
            G[ node + 1 ].push_back( { node, 0 } );
            ++node;
            G[ node ].push_back( { to[ i ], cost[ i ] } );
            G[ to[ i ] ].push_back( { node, cost[ i ] } );
        }
        for( int i = 1; i <= k; ++i )
            to[ i ] = cost[ i ] = 0;
    }
return 0;
}
