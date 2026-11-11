#include<bits/stdc++.h>
#define pii pair < int , int >
#define st first
#define nd second

using namespace std;

void init()
{
    freopen( "migrate.in" , "r" , stdin );
    freopen( "migrate.out" , "w" , stdout );
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int c , t;
int n;
long long a[2000010] , d;
vector < int > g[5010];

int dis[5010][5010][3];

inline void upd( int x , int y , int k )
{
    int tmp[4] = { dis[x][y][0] , dis[x][y][1] , dis[x][y][2] , k };
    sort( tmp , tmp + 4 );
    for ( int i = 0 ; i < 3 ; i++ )
        dis[x][y][i] = tmp[i];
}

inline void bfs( int s )
{
    queue < pii > q;
    q.push( { s , 0 } );
    while ( !q.empty() )
    {
        pii tmp = q.front();
        q.pop();
        int x = tmp.st;
        int y = tmp.nd;
        if ( y >= dis[s][x][2] ) continue;
        for ( int &u : g[x] )
        {
            upd( s , u , y + 1 );
            q.push( { u , y + 1 } );
        }
    }
}

int main()
{
    init();
    cin >> c >> t;
    while ( t-- )
    {
        long long ans = 0;
        cin >> n >> d;
        for ( int i = 1 ; i <= n ; i++ )
        {
            cin >> a[i];
            for ( int j = i - 1 ; j >= 1 ; j-- )
                if ( a[i] - a[j] <= d )
                    g[j].push_back(i);
                else break;
        }
        #ifdef lhw
        for ( int i = 1 ; i <= n ; i++ )
        {
            cout << i << ':';
            for ( auto &x : g[i] )
                cout << x << ' ';
            cout << endl;
        }
        #endif
        for ( int i = 1 ; i <= n ; i++ )
            for ( int j = 1 ; j <= n ; j++ )
                dis[i][j][0] = dis[i][j][1] = dis[i][j][2] = 1e9;
        for ( int i = 1 ; i <= n ; i++ )
            bfs(i);
        #ifdef lhw
        for ( int i = 1 ; i <= n ; i++ )
        {
            cout << "QWQ:" << i << endl;
            for ( int j = 1 ; j <= n ; j++ )
                cout << j << ':' << dis[i][j][0] << ' ' << dis[i][j][1] << ' ' << dis[i][j][2] << endl;
            cout << endl;
        }
        #endif
        for ( int i = 1 ; i <= n ; i++ )
            for ( int j = i + 3 ; j <= n ; j++ )
                if ( dis[i][j][0] == dis[i][j][1] && dis[i][j][1] < dis[i][j][2] )
                    ans++;
        cout << ans << endl;
        for ( int i = 1 ; i <= n ; i++ )
            g[i].clear();
    }
    return 0;
}