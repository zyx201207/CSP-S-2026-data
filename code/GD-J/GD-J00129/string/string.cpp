#include <bits/stdc++.h>
using namespace std ;
long long n , ans ;
const int maxn = 2 * 1e5 + 10 ;
pair<int,char> D[maxn] ;
int main ( ) {

    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;

    ios::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> n ;
    for (int i = 0 ; i < n ; i++) {
        int a ;
		char c ;
        cin >> a >> c ;
        D[i].first = a , D[i].second = c ;
    }

    for (int l = 0 , r = n-1 ; l < n && r >= 0 && l <= r ; ) {
        
        if (D[l].first == D[r].first && D[l].second == D[r].second)
        {l++ ; r-- ; continue ;}

        if (D[l].first != D[r].first && D[l].second != D[r].second) {
            if (D[l].first < D[r].first) {
                D[r].first = D[r].first-D[l].first ;
                ans += D[l].first ;
                l++ ;
            } 
            else{
                D[l].first = D[l].first-D[r].first ;
                ans+= D[r].first ;
                r-- ;
            } 
        }

        if (D[l].first == D[r].first && D[l].second != D[r].second) {
            ans += D[l].first ;
            l++ ; r-- ;
        } 

        if (D[l].first != D[r].first && D[l].second == D[r].second) {
            if (D[l].first < D[r].first) {
                D[r].first = D[r].first-D[l].first ;
                l++ ;
            } 
            else{
                D[l].first = D[l].first-D[r].first ;
                r-- ;
            } 
        }       
    }

    cout << ans ;
    return 0 ; 
}