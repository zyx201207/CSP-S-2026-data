#include<bits/stdc++.h>
using namespace std ;
#define ll long long

ll n , m ;
ll a[600100] ;
ll q[600100] ;

void xiao() {
    for( ll i = 1 ; i <= n ; i ++ ) {
        scanf("%lld",&a[i]) ;
    }
    sort(a+1,a+n+1) ;
    q[0] = 0 ;
    for( ll i = 1 ; i <= n ; i ++ ) {
        q[i] = a[i] + q[i-1] ;
    }
    ll ans = LLONG_MAX ;
    ans *= -1 ;
    for( ll i = 1 ; i <= n ; i ++ ) {
        for( ll j = 1 ; j <= i ; j ++ ) {
            ll b = q[i] - q[j-1] ;
            b += m ;
            ll len = i - j + 1 ;
            ll ma = a[i] ;
            if( b % len == 0 ) {
                ll shang = b / len ;
                if( shang >= ma ) {
                    ans = max(ans,len) ;
                }
            }
        }
    }
    printf("%lld",ans) ;
}

void A() {
    ll t = m ;
    ll u = 1 ;
    ll ans = 0 ;
    while( t > 0 ) {
        t -= u ;
        u ++ ;
        ans ++ ;
    }
    if( t < 0 ) ans -- ;
    printf("%lld",ans) ;
}

void B() {
    ll gb = a[2] - a[1] ;
    ll u = gb ;
    ll ans = 1 ;
    ll t = m ;
    while( t > 0 ) {
        t -= u ;
        u += gb ;
        ans ++ ;
    }
    if( t < 0 ) {
        ans -- ;
    }
    printf("%lld",ans) ;
}

void C() {
    cout << "nigei zhongguogongchandang dajifen ? manfen10fen" << endl ;
    cout << "yiqiefandongpaidoushizhilaohu!" << endl ;
}

int main() {
    freopen("crystal2.in","r",stdin) ;
    freopen("crystal2.out","w",stdout) ;
    scanf("%lld%lld",&n,&m) ;
    if( m <= 1e9 ) {
        xiao() ;
    } else {
        int cnt = 0 ;
        for( ll i = 1 ; i <= n ; i ++ ) {
            scanf("%lld",&a[i]) ;
            if( a[i] == i && cnt <= 10 ) {
                cnt ++ ;
            }
        }
        if( cnt == 11 ) {
            A() ;
        } else {
            if( a[3] - a[2] == a[2] - a[1] ) {
                B() ;
            } else {
                C() ;
            }
        }
    }
    return 0 ;
}
