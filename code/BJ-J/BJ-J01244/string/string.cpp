#include <bits/stdc++.h>
using namespace std ;
const int maxn = 2e5+5 ;
int a[maxn] ;
char c[maxn];
long long ans = 0 ;
int main (){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    int n ;
    cin >> n ;

    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i] >> c[i] ;
    }
    int l = 1 ;
    int r = n ;
    while (l <= r){
        int dell = min(a[l],a[r]) ;
        a[l] -= dell ;
        a[r] -= dell ;
        if (c[l] != c[r]) ans += dell ;
        if (a[r] == 0){
            r -- ;
        }
        else {
            l ++ ;
        }
    }
    cout << ans ;
    return 0 ;
}
