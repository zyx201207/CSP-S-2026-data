#include <bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
bool b[500005];
int w[500005];
vector < int > a[500005] , t[500005] , sta[500005];
int dfs( int s , int f , int ans ){
    if( s == f ){
        return ans;
    }
    int sta_size = sta[s].size();
    for( int i = 1; i <= sta_size; i ++ ){
        int new_sta = sta[s][i];
        if( b[new_sta] == 0 ){
            b[new_sta] = 1;
            dfs( new_sta , f , ans + t[s][new_sta] );
            b[new_sta] = 0;
        }
    }
}
int main (){
    freopen( "subway.in" , "r" , stdin );
    freopen( "subway.out" , "w" , stdout );
    cin >> c >> n >> m >> d >> q;
    for( int i = 1; i <= m; i ++ ){
        cin >> w[i];
    }
    for( int i = 1; i <= n; i ++ ){
        int k;
        cin >> k;
        for( int j = 1; j <= k; j ++ ){
            int a_i , t_i;
            cin >> a_i >> t_i;
            a[i].push_back( a_i );
            t[i].push_back( t_i );
        }
        int size = a[i].size();
        for( int j = 1; j <= size; j ++ ){
            for( int x = 1; x <= size; x ++ ){
                if( j != x ){
                    sta[a[i][j]].push_back( a[i][x] );
                }
            }
        }
    }
    for( int i = 1; i <= q; i ++ ){
        int s , f;
        cin >> s >> f;
        cout << dfs( s , f , 0 ) << endl;
    }
    return 0;
}
