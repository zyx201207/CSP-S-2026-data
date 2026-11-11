#include <bits/stdc++.h>
using namespace std ;

bool check(string a)
{
    string b = a ;
    reverse(b.begin(),b.end()) ;
    return b == a ;
}

int main()
{
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int n ;
    long long ans = 0 ;
    char c ;
    string sa , sb ;
    cin >> n ;
    vector<long long> a(n+1) ;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> c ;
        for (long long i = 1 ; i <= a[i] ; i++) {
            sa += c ;
        }
    }
    if (check(sa)) {
        cout << "0" ;
        return 0 ;
    }
    sb = sa ;
    reverse(sb.begin(),sb.end()) ;
    for (int i = n-1 , j = 1 ; i >= 0 ; i--,j++) {
        if (sa[i] != sb[i]) {
            sa[i] = sb[i] ;
            ans++ ;
        }
        if (check(sa)) {
            break ;
        }
    }
    cout << ans ;
    return 0 ;
}
