#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
long long check( int mid ){
    long long ans = 0;
    for( int i = 1; i <= mid; i ++ ){
        ans += a[mid] - a[i];
    }
    return ans;
}
int search( int l , int r ){
    long long ans = 0;
    while( l <= r ){
        long long mid = l + ( r - l ) / 2;
        if( check( mid ) <= m ){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}
int main (){
    freopen( "crystal.in" , "r" , stdin );
    freopen( "crystal.out" , "w" , stdout );
    cin >> n >> m;
    for( int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    sort( a + 1 , a + n + 1 );
    cout << search( 1 , n );
    return 0;
}
