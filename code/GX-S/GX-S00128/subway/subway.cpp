#include<bits/stdc++.h>
#define ll long long
using namespace std ;

struct point {
    int t1 ;
    int t2[30] ;
};

ll c , n , m , d , q ;
ll w[600000] ;
ll k[600] ;
ll father[600000] ;
point a[600000] ;

ll find_(int x){
    if( father[x] == x ) return x ;
    return father[x] = find_(father[x]) ;
}

void init() {
    for( int i = 1 ; i <= m ; i ++ ) father[i] = i ;
}

int main() {
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q) ;
    init() ;
    for( ll i = 1 ; i <= m ; i ++ ) scanf("%lld",&w[i]) ;
    for( ll i = 1 ; i <= n ; i ++ ) {
        scanf("%lld",&k[i]) ;
        ll x[600000] , y[600000] ;
        for( ll j = 1 ; j <= k[i] ; j ++ ) {

            scanf("%lld%lld",&x[i],&y[i]) ;
        }
        for( ll j = 1 ; j < k[i] ; j ++ ) {
            ll fx = find_(x[i]) ;
            ll fy = find_(x[i+1]) ;
            father[fx] = father[fy] ;
        }
    }
    return 0 ;
}
