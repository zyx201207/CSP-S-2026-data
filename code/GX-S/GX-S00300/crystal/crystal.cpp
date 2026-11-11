#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], c[500005], mx ;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i] ;
    }
    sort(a+1,a+n+1);
    for ( int i = 2; i <= n ; i++ ) {
        c[i] = a[i] - a[i-1] ;
    }
    long long l = 1, tw = 0, dw = 0, tg = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        tw += c[i] * tg ;
        dw += c[i] ;
        tg++ ;
        while ( tw > m ) {
            tg-- ;
            tw -= dw ;
            dw -= c[l+1] ;
            l++ ;
        }
        mx = max(mx,tg);
    }
    cout << mx ;
    return 0;
}
