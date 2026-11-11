#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 5 ;
int a[N] ;
int n , m ;
bool A = true ;
bool B = true ;
int CB = 0 ;
void solve1() {
    int ans = 0 ;
    for(int i = 1 ; i < n ; i ++) {
        if(m >= i) {
            m -= i ;
            ans ++ ;
        }else {
            cout << ans + 1 ;
            return ;
        }
    }
    cout << ans + 1 ;
}
void solve2() {
    int ans = 0 ;
    for(int i = 1 ; i < n ; i ++) {
        if(m >= i * CB) {
            m -= i * CB ;
            ans ++ ;
        }else {
            cout << ans + 1 ;
            return ;
        }
    }
    cout << ans + 1 ;
}
void solve3() {
    sort(a + 1 , a + n + 1) ;
    int mi = INT_MAX ;
    int idx = -1 ;
    for(int i = 2 ; i <= n ; i ++) {
        if(mi > a[i] - a[i - 1]) {
            mi = a[i] - a[i - 1] ;
            idx =  i ;
        }
    }
    int left = idx ;
    int right = idx ;
    int ans = 0 ;
    while(m >= 0) {
        ans ++ ;
        int c_l , c_r ;
        if(left - 1 != 0) 
            c_l = a[left] - a[left - 1] ;
        else 
            c_l = INT_MAX ;
        if(right != n)
            c_r = a[right + 1] - a[right] ;
        else 
            c_r = INT_MAX ;
        if(c_l >= c_r && right <= n) {
            m -= c_r ;
            right ++ ;
        }else if(left >= 1) {
            m -= c_l ;
            left -- ;
        }else {
            cout << n ;
            return ;
        }
    }
    cout << ans ;
}
int main() {
    freopen("crystal.in" , "r" , stdin) ;
    freopen("crystal.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> a[i] ;
        if(a[i] != i) {
            A = false ;
        }
        if(i == 2) {
            CB = a[i] - a[i - 1] ;
        }else if(i != 1) {
            if(a[i] - a[i - 1] != CB) {
                B = false ;
            }
        }
    }
    if(A == true) {
        solve1() ;
    }else if(B == true) {
        solve2() ;
    }else {
        solve3() ;
    }
    return 0 ;
}

