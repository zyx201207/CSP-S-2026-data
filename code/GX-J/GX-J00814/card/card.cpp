#include <bits/stdc++.h>
using namespace std;
long long ans = 0 , cnt = 0 ,n;
string s , w;
int main(){
    freopen("string.in" , "r" , stdin) ;
    freopen("string.out" , "w" , stdout) ;
    cin >> n ;
    for (int i = 1 ; i  <= n ; i ++){
        long long b;
        string  a ;
        cin >> b ;
        cin >> a ;
        for (int j  = 1 ; j <= b ; j ++){
            s += a ;
            //cout << a  << endl ;
            //cout  << s;
        }
        //cout << s ;
    }
    cout << s ;
    long long len  = s.size() ;
    for (int i = len ; i >= 1 ; i ++){
        if(s[i] != s[len+1-i]){
            cout << s[i] << s[len+1-i] ;
            ans ++ ;
        }
    }
    cout << ans ;
    return 0 ;
}

