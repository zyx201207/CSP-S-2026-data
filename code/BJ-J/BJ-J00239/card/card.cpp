#include <bits/stdc++.h>
using namespace std ;
int n , m , a[500005] , cnt[300005];
int ans[300005] ;
int main()
{
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        ans[a[i]] += i ;
    }
    for(int i = 1 ; i <= n ; i++){
            for(int i = 1 ; i <= 300005 ; i++) cnt[i] = 0 ;
            for(int j = i ; j <= n ; j++){
                if(cnt[a[j]] == 1){
                    for(int k = i ; k <= j ; k++)
                        if(a[k] == a[j]){
                            for(int l = k ; l <= j ; l++){
                                if(a[l] == -1) continue ;
                                ans[a[l]]-- ;
                                a[l] = -1 ;
                            }
                        }

                }
            }
    }
    for(int i = 1 ; i <= m ; i++){
        cout << ans[i] % (n+1) << " " ;
    }
    return 0 ;
}
