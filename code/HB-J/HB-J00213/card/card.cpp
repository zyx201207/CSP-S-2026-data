#include <bits/stdc++.h>
using namespace std ;
int n , m , a[500005] , book[300005] , yl[300005] , ans[300005] ;
int main (){
    freopen("card.in" , "r" , stdin) ;
   freopen("card.out" , "w" , stdout) ;
      cin >> n >> m ;
      for (int i = 1 ; i <= n ; i ++ ){
          cin >> a[i] ;
      }
      for (int i = 1 ; i <= n ; i ++ ){
            memset(book , 0 , sizeof(book)) ;
            memset(yl , 0 , sizeof(yl)) ;
          for (int j = i ; j <= n ; j ++ ){
              if (yl[a[j]] != 0 && book[yl[a[j]]] == 0){
                  for (int k = yl[a[j]] ; k < j ; k ++ ){
                      book[k] = 1 ;
                  }
                  yl[a[j]] = j ;
              }
              yl[a[j]] = j ;
          }
          for (int j = i ; j <= n ; j ++ ){
               if (book[j] == 0) {
                    ans[a[j]] ++ ;
               }
          }
      }
      for (int i = 1 ; i <= m ; i ++ ){
           cout << ans[i] << " " ;
      }
     return 0 ;
}
