#include<bits/stdc++.h>
using namespace std ;
int main() {
    freopen("migrate.in" , "r" , stdin) ;
    freopen("migrate.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    int c ;
    cin >> c ;
    int t ;
    cin >> t ;
    while(t --) {
        vector<int> a(2e6 + 5) ;
        int n , d ;
        cin >> n >> d ;
        int CB = -1 ;
        bool C = true ;
        for(int i = 1 ; i <= n ; i ++) {
            cin >> a[i] ;
            if(i == 2) {
                CB = a[i] - a[i - 1] ;
            }else if(i != 1) {
                if(a[i] - a[i - 1] != CB) {
                    C = false ;
                }
            }
        }
        long long ans = 0 ;
        if(C) {
            
            long long canfly = d / CB ;
            for(long long i = 1 ; i + canfly < n ; i ++) {
                if(i + canfly + canfly - 1 <= n) {
                    ans ++ ;
                }
            }
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}


