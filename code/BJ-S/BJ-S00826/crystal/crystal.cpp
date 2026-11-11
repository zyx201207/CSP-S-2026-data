#include <bits/stdc++.h>

#define ll long long
#define maxn 500007

using namespace std;

ll n, m , ans ,  a[maxn] , q[maxn];

ll check( ll l , ll r )
{
    return ( ( a[r] * ( r - l + 1 ) - ( q[r] - q[l - 1] ) )<= m );
}

int main()
{
    freopen( "crystal.in" , "r" , stdin );
    freopen( "crystal.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cin>>n >>m;
    for( int i = 1 ; i <= n ; ++i ) {
        cin >>a[i];
    }
    sort(a + 1 , a + n+ 1 ); ll tmp = 1;
    for( int i = 1 ; i<= n ; ++i ) q[i] = q[i - 1] + a[i];
    for( int i = 1 ; i <= n ; ++i ) {
        while( !check( tmp , i ) ) {
            tmp ++;
        }
        ans = max( ans , i - tmp+ 1 );
    }
    cout <<ans;
    return 0;
}
