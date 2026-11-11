#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int c , n , m , d , q;
int a[N];
int k[505][N];
int t[505][N];
int kx[505];
int vis[505];

struct Node{
    int line , time;
};
vector<Node> g[505];
int ans;

void dfs( int u , int cnt , int e ) {
    if ( u == e ){
        ans = min( ans , cnt );
        return ;
    }
    for ( int i = 0 ; i < g[u].size() ; i ++ ) {
        Node T = g[u][i];
        for ( int j = 1 ; j <= kx[T.line] ; j ++ ) {
            if ( k[T.line][j] == u )
                continue;
            if ( vis[k[T.line][j]] == 0 ) {
                vis[k[T.line][j]] = 1;
                dfs( k[T.line][j] , cnt + T.time + t[T.line][j] , e );
                vis[k[T.line][j]] = 0;
            }
        }
    }
}

int main() {
    freopen( "subway.in" , "r" , stdin );
    freopen( "subway.out" , "w" , stdout );
    cin >> c >> n >> m >> d >> q;
    for ( int i = 1 ; i <= m ; i ++ ) {
        cin >> a[i];
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> kx[i];
        for ( int j = 1 ; j <= kx[i] ; j ++ ) {
            cin >> k[i][j] >> t[i][j];
            g[k[i][j]].push_back( { i , t[i][j] } );
        }
    }
    for ( int i = 1 ; i <= q ; i ++ ) {
        int l , r;
        cin >> l >> r;
        ans = 2e9 + 1e8;
        memset( vis , 0 , sizeof vis );
        vis[l] = 1;
        dfs( l , 0 , r );
        ans = ans + a[l] + a[r];
        cout << ans << endl;
    }
}
