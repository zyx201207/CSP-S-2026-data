#include <bits/stdc++.h>
using namespace std ;
int a[500005] ;

int main () {
    freopen ( "and.in" , "r" , stdin ) ;
    freopen ( "and.out" , "w" , stdout ) ;
    int n , m ; cin >> n >> m ;
    for ( int i = 0 ;i < n ; i++ ) {
        cin >> a[i] ;
    }
    sort( a , a + n ) ;
    int sum = a[n-1] ;
    for ( int i = 0 ; i < m ; i++ ) {
        sum = sum & a[n-i-1] ;
    }
    cout << sum ;
    return 0 ;
}
