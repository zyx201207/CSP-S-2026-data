#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;

ll n = 0 , ans = 0 ;
struct node
{
    ll num ;
    char ch ;

    node ()
    {
        num = 0 ;
        ch = '0' ;
    }
};
node arr [ 200010 ] ;

int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );

    freopen( "string.in" , "r" , stdin );
    freopen( "string.out" , "w" , stdout );

    cin >> n ;

    for ( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr [ i ].num >> arr [ i ].ch ;
    }

    int l = 1 , r = n ;

    while ( l < r )
    {
        ll val = min ( arr [ l ].num , arr [ r ].num ) ;
        if ( arr [ l ].ch == arr [ r ].ch )
        {
            arr [ l ].num -= val ;
            arr [ r ].num -= val ;
        }
        else
        {
            ans += val ;
            arr [ l ].num -= val ;
            arr [ r ].num -= val ;
        }

        if ( 0 == arr [ l ].num )
        {
            l ++ ;
        }

        if ( 0 == arr [ r ].num )
        {
            r -- ;
        }
    }

    cout << ans << endl ;

    return 0 ;
}
