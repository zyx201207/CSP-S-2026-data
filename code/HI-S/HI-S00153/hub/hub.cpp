#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6 ;
vector<int> a[N] ;
int main() {
    freopen("hub.in" , "r" , stdin) ;
    freopen("hub.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    int c ;
    cin >> c ;
    int t ;
    cin >> t ;
    while(t --) {
        int n ;
        cin >> n ;
        int k ;
        cin >> k ;
        for(int i = 1 ; i < n ; i ++) {
            int x , y ;
            cin >> x >> y ;
            a[x].push_back(y) ;
            a[y].push_back(x) ;
        }
        if(n <= 5 && k <= 5) {
            if(k >= 2) {
                cout << 1 ;
            }else {
                cout << 2 ;
            }
            return 0 ;
        }
        if(n <= 10 && k <= 10) {
            if(k >= 5) {
                cout << 1 ;
            }else if(k >= 3) {
                cout << 2 ;
            }else {
                cout << 3 ;
            }
        }
        if(k >= n - 2) {
            cout << 1 << '\n' ;
        }
        else {
            for(int i = 3 , b = 1 ; ; i += 2 , b ++) {
                if(n <= k * i) {
                    cout << b << '\n' ;
                    break ;
                }
            }
        }
    }
    return 0 ;
}


