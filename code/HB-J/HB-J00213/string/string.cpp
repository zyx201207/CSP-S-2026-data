#include <bits/stdc++.h>
using namespace std ;
int n ;
vector <int> v ;
long long ans ;
int gsg[200005] ;
char ch[200005] ;
int main (){
     freopen("string.in" , "r" , stdin) ;
   freopen("string.out" , "w" , stdout) ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++ ){
        cin >> gsg[i] >> ch[i] ;
        for (int j = 1 ; j <= gsg[i] ; j ++ ){
            v.push_back(ch[i]) ;
        }
    }
    for (int j = 0 ; j < v.size() / 2 ; j ++ ){
        if (v[j] != v[v.size() - j - 1]){
            ans ++ ;
        }
    }
    cout << ans ;
    return 0 ;
}
