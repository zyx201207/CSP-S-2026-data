#include<bits/stdc++.h>
#define pii pair < long long , int >
#define st first
#define nd second

using namespace std;

void init()
{
    freopen( "subway.in" , "r" , stdin );
    freopen( "subway.out" , "w" , stdout );
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const long long inf = ~0ULL >> 1;

int c , n , m , dd , q;
long long a[500010];
vector < pii > g[500510];
long long dis[1510][1510];

inline void dijk( int x )
{
    priority_queue < pii , vector < pii > , greater < pii > > q;
    q.push( { 0 , x } );
    while ( !q.empty() )
    {
        auto tmp = q.top();
        q.pop();
        long long t = tmp.st;
        int u = tmp.nd;
        if ( dis[x][u] <= t )
            continue;
        dis[x][u] = t;
        for ( auto &p : g[u] )
        {
            long long s = t + p.st;
            int v = p.nd;
            q.push( { s , v } );
        } 
    }
}

inline void solve1()
{
    memset( dis , 0x3f , sizeof dis );
    for ( int i = n + 1 ; i <= n + m ; i++ )
        dijk(i);
    while ( q-- )
    {
        int u , v;
        cin >> u >> v;
        cout << dis[u + n][v + n] + a[u] + a[v] << endl;
    }
}

long long tt;
int d[500510][2];

struct state
{
    int x , t;
    bool op;
};

inline int bfs( int x , int y )
{
    queue < state > q;
    vector < int > s;
    s.push_back(x);
    s.push_back(y);
    // memset( d , 0 , sizeof d );
    q.push( ( state ) { x , 0 , 0 } );
    q.push( ( state ) { y , 0 , 1 } );
    int ret = 0;
    while ( !q.empty() )
    {
        auto tmp = q.front();
        q.pop();
        int u = tmp.x;
        int t = tmp.t;
        bool op = tmp.op;
        for ( auto &p : g[u] )
        {
            int v = p.nd;
            if ( d[v][!op] )
            {
                ret = t + 1 + d[v][!op];
                break;
            }
            if ( !d[v][op] )
            {
                d[v][op] = t + 1;
                q.push( ( state ) { v , t + 1 , op } );
                s.push_back(v);
            }
        }
        if ( ret ) break;
    }
    for ( auto &u : s )
        d[u][0] = d[u][1] = 0;
    return ret;
}

inline void solve2()
{
    tt = g[1][0].st;
    while ( q-- )
    {
        int u , v;
        cin >> u >> v;
        cout << tt * bfs( u + n , v + n ) + a[u] + a[v] << endl;
    }
}

int main()
{
    init();
    cin >> c >> n >> m >> dd >> q;
    for ( int i = 1 ; i <= m ; i++ )
        cin >> a[i];
    for ( int i = 1 ; i <= n ; i++ )
    {
        int k;
        cin >> k;
        for ( int j = 1 ; j <= k ; j++ )
        {
            int x , t;
            cin >> x >> t;
            g[i].push_back( { t , x + n } );
            g[x + n].push_back( { t , i } );
        }
    }
    if ( c <= 11 )
        solve1();
    else if ( c >= 12 && c <= 19 )
        solve2();
    else solve1();
    return 0;
}