#include <bits/stdc++.h>

#define ll long long
#define maxn 500007
#define N  1145141145141145140

using namespace std;

ll n , m , d , q , W[maxn] , f[1007][1007];
vector< ll >v[maxn] , w[maxn];

int main()
{
    freopen( "subway.in" , "r" , stdin );
    freopen( "subway.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cin >>n >>n >>m >>d >>q; //cout <<n <<" " <<m <<" " <<d <<" " << q <<" "; return 0;
    for( int i = 1;  i <= m; ++i ) cin>> W[i];
    for( int i = 1 ; i <= n; ++i ) {
        ll k; cin >> k;
        for( int j = 0 ; j< k ; ++j ) {
            ll s1 , s2; cin>> s1 >> s2; v[s1].push_back( i ); w[s1].push_back( s2 );
        }
    }
    for( int i = 1 ; i <= n ; ++i ) for( int j = 1 ; j<= n ; ++j ) f[i][j] = ( i == j ? 0 : N );
    for( int i = 1 ; i <= m ; ++i )
        for( int j = 0 ; j < v[i].size() ; ++j )
            for( int k = 0 ; k< v[i].size() ; ++k )
                f[v[i][j]][v[i][k]] = min( f[v[i][j]][v[i][k]] , w[i][j] + w[i][k] );
    for( int k = 1; k <= n ; ++k )
        for( int i = 1 ; i <= n ; ++i )
            for( int j = 1 ; j <= n ; ++j )
                f[i][j] = min( f[i][j] , f[i][k] + f[k][j] );
    while( q -- ) {
        ll s1, s2; cin >>s1 >>s2;
        ll sum = N;
        for( int i = 0 ; i< v[s1].size() ; ++i )
            for( int j = 0 ; j< v[s2].size() ; ++j ) {
                sum = min( sum , f[v[s1][i]][v[s2][j]] + w[s1][i] + w[s2][j] );
              //  if( sum == 9 ) cout <<v[s1][i] <<" " <<v[s2][j] <<"\n";
            }
        //cout <<sum <<"\n";
        cout << sum + W[s1] + W[s2] << "\n";
    }
    return 0;
}
