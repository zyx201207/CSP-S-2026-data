#include <bits/stdc++.h>
using namespace std ;
int n , m ;
long long a[200005] ;
int book[200005] ;
long long ans ;
void dfs(int x , long long zh){
     if (x == m){
        ans = max(ans , zh) ;
        return ;
     }
     for (int i = 1 ; i <= n ; i ++ ){
         if (book[i] == 0){
            book[i] = 1;
             if (x == 0){
                dfs(x + 1 , zh + a[i]) ;
             }
             else {
                dfs(x + 1 , (zh & a[i])) ;
             }
             book[i] = 0 ;
         }
     }
}
int main (){
     freopen("and.in" , "r" , stdin) ;
   freopen("and.out" , "w" , stdout) ;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i ++ ){
        cin >> a[i] ;
    }
    dfs(0 , 0) ;
    cout << ans ;
     return 0 ;
}
