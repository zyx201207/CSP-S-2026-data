#include<bits/stdc++.h>
using namespace std;
long long n , m , c , d , q , w[500001] , a[501][501] , t[501][501] , k[501] , x , y , b[500001][21] , z[500001] , dp[101][101] ;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c >> n >> m >> d >> q ;
    for ( int i = 1 ; i <= m ; i ++)
    {
        cin >> w[i] ;
    }
    for ( int i = 1 ; i <= n ; i ++)
    {
        cin >> k[i] ;
        for ( int j = 1 ; j <= k[i] ; j ++)
        {
            cin >> a[i][j] >> t[i][j] ;
        }
    }

    for ( int i = 1 ; i <= n ; i ++)
    {
        for ( int j = 1 ; j < k[i] ; j ++)
        {
            z[a[i][j]]++;
            b[a[i][j]][z[a[i][j]]] = i ;
            dp[a[i][j]][a[i][j+1]] = t[i][j]+t[i][j+1] ;
        }
    }
    for ( int i = 1 ; i < m ; i ++)
    {
        for ( int j = 2 ; j <= m ; j ++)
        {
            for ( int k1 = 1 ; k1 <= z[j] ; k1 ++)
            {
                int dd ;
                for ( int l = 1 ; l <= k[b[j][k1]] ; l ++)
                {
                    if ( a[k1][l] == j )
                    {
                        dd = l ;
                    }
                }
                for (int l = 1 ; l <= k[b[j][k1]] ; l ++)
                {
                    dp[i][j] = dp[i][a[k1][l]] + t[k1][l] + t[k1][dd] ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= q ; i ++)
    {
        cin >> x >> y ;
        cout << w[x]+w[y]+dp[x][y] << endl ;
    }
    return 0;
}
