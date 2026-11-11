#include <bits/stdc++.h>
using namespace std ;

bool cmp(int a , int b)
{
    int p = a , q = b ;
    string x , y ;
    while (p) {
        x += (char)('0'+p%2) ;
        p /= 2 ;
    }
    while (q) {
        y += (char)('0'+q%2) ;
        q /= 2 ;
    }
    for (int i = 0 ; i < x.size() ; i++) {
        if (x[i] == '1') {
            p++ ;
        }
    }
    for (int i = 0 ; i < y.size() ; i++) {
        if (y[i] == '1') {
            q++ ;
        }
    }
    if (p != q) {
        return p > q ;
    } else {
        return a > b ;
    }
}

int main()
{
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int n , m ;
    long long ans ;
    cin >> n >> m ;
    vector<int> a(n+1) ;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
    }
    sort(a.begin()+1,a.end(),cmp) ;
    ans = a[1] ;
    for (int i = 1 ; i <= m ; i++) {
        ans &= a[i] ;
    }
    cout << ans ;
    return 0 ;
}
