#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
ll n = 0 , m = 0 , ans = - 0x3f3f3f3f ;
ll arr [ 200010 ] ;

void dfs ( int i , int cnt , ll num )
{
    if ( cnt == m )
    {
        ans = max ( ans , num ) ;
        return ;
    }

    if ( i > n )
    {
        return ;
    }

    if ( num < ans )
    {
        return ;
    }

    if ( n - i + cnt < m )
    {
        return ;
    }

    dfs ( i + 1 , cnt + 1 , num & arr [ i ] ) ;
    dfs ( i + 1 , cnt , num ) ;
}

bool cmp ( const ll a , const ll b )
{
    return a > b ;
}

int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );

    freopen( "and.in" , "r" , stdin );
    freopen( "and.out" , "w" , stdout );

    cin >> n >> m ;

    for ( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr [ i ] ;
    }

    if ( n <= 23 )
    {
        for ( int i = 1 ; i <= n ; i ++ )
        {
            dfs ( i + 1 , 1 , arr [ i ] ) ;
        }

        cout << ans << endl ;
    }
    else
    {
        sort ( arr + 1 , arr + 1 + n , cmp ) ;

        ans = arr [ 1 ] ;

        for ( int i = 2 ; i <= m ; i ++ )
        {
            ans &= arr [ i ] ;
        }

        cout << ans << endl ;
    }

    return 0 ;
}
