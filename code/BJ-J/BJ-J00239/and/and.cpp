#include <bits/stdc++.h>
using namespace std ;
int n , m  ;
int a[200005] , flag1[200005][40] , cnt[200005] ;
int sf[200005] ;
int zz[40] ;
int flag2[200005][40] ;
int main()
{
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        int ai2 = a[i] , sw = 1 ;
        while(ai2 > 0){
            if(ai2 % 2 == 1){
                flag1[i][sw]++ ;
                cnt[i]++ ;
            }
            ai2 /= 2 ;
            sw++ ;
        }
    }
    while(m--){
        int maxn = -1 , maxxb ;
        for(int i = 1 ; i <= n ;i++){
            if(sf[i]) continue ;
            if(maxn < cnt[i] || (a[maxxb] < a[i] && maxn <= cnt[i])){
                maxn = cnt[i] ;
                maxxb = i ;
            }
        }
        sf[maxxb] = 1 ;
    }
    bool one = 1 ;
    int ans ;
    for(int i = 1 ; i <= n ; i++){
        if(sf[i]){
            if(one){
                ans = a[i] ;
                one = 0 ;
            }
            else ans = ans & a[i] ;
        }
    }
    cout << ans ;
    return 0 ;
}
