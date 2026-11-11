#include <bits/stdc++.h>
using namespace std;
long long ans = 0 , cnt = 0 , jg  = 0,n;
long long a[200005] ;
char b [200005] ;
string s , w;
int main(){
    freopen("string.in" , "r" , stdin) ;
    freopen("string.out" , "w" , stdout) ;
    cin >> n ;
    for (int i = 1 ; i  <= n ; i ++){
        cin >> a[i] >> b[i] ;
    }
    for(int i = 1 , j = n ; i <= n&& j >= 1 ; i ++,j--){
        if(b[i] == b[j]){
            ans += a[i] ;
            cnt+=a[j] ;
            cout << ans << ' ' << cnt  << endl ;
        }
        else{
            jg += abs(ans-cnt) ;
            ans = 0 ;
            cnt = 0 ;
        }
    }
    cout << jg  ;
    return 0 ;
}

