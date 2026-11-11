#include <bits/stdc++.h>

#define ll long long
#define maxn 2000007
#define N  3145141145141145140

using namespace std;

ll n , d , T , ans , f[maxn][3][3] , x[maxn] , nxt[maxn] , lst[maxn];

int main()
{
    freopen( "migrate.in" , "r" , stdin );
    freopen( "migrate.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> T >> T;
    while( T -- ) {
        cin >> n >>d; x[n + 1] = N;
        for( int i = 1;  i <= n ; ++i ) {
            cin >>x[i];
        }
        for( int i = 1 ; i<= n ; ++i ) {
            nxt[i] = ( lower_bound( x + 1 , x + n + 1 , x[i] + d + 1 ) - x - 1 );
            if( nxt[i] > i && nxt[i] <= n ) {
                if( nxt[i] == i + 1 ) f[nxt[i]][0][1] ++;
                else f[nxt[i]][1][1] ++;
            }
            lst[i] = ( lower_bound( x + 1 , x + n + 1 , x[i] - d ) - x  );
        }
        for( int i = 1 ; i <= n ; ++i ) {
            if( nxt[i] > i ) {
                for( int j =0 ; j <= 2 ; ++j ) {
                    for( int k = 0 ; k <= 2 ; ++k ) {
                        ll s1 = 0 , s2= 0;
                        ll tmp = lst[nxt[i]];
                        if( tmp < i - 1 ) s2 = 3;
                        else if( tmp== i - 1 ) s2 = j + k;
                        else if( tmp == i ) s2 = k;
                        if( nxt[i] != i + 1 ) {
                            tmp = lst[nxt[i] - 1];
                            if( tmp < i - 1 ) s1 = 3;
                            else if( tmp== i - 1 ) s1 = j + k;
                            else if( tmp == i ) s1 = k;
                        }
                        s1 = min( s1 , (ll)2 );
                        if( s2 <= 2 ) {
                            f[nxt[i]][s1][s2] += f[i][j][k];
                        }
                      //  if( i == 4 && j == 1 && k == 1 ) cout <<nxt[i - 1] <<" " <<nxt[i - 2] << "\n";
                        if( k == 2 ) {
                            ans += f[i][j][k] * ( nxt[i] - nxt[i - 1] );
                        }else if( j + k == 2 ) {
                            ans += f[i][j][k] * ( nxt[i - 1] - ( i > 1 ? nxt[i - 2] : 0 ) );
                        }
                    }
                }

            }
        }
        cout << ans <<"\n"; ans = 0;
        for( int i = 1;  i <= n + 1 ; ++i ) {
            for( int j = 0 ; j<= 2 ; ++j )
                for( int k = 0 ;k <= 2 ; ++k )
                    f[i][j][k] = 0;
            x[i] = nxt[i] = lst[i] = 0;
        }
    }
    return 0;
}
