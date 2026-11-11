#include <bits/stdc++.h>
using namespace std ;
const int maxn = 5e5 + 5 ;
int a[maxn]  ;
int ha[300005] ;

int tab[maxn];
int main (){
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    int n , m ;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
    }
    for (int i = 1 ; i <= n ; i ++){//第i局
        int r = 0 ;
        for (int j = i ; j <= n ; j ++){//选第j张牌
            for (int k = 1 ; k <= r ; k ++){
                if (tab[k] == a[j]){
                    r = k - 1 ;
                    break ;
                }
            }
            tab[r+1] = a[j] ;
            r ++ ;
        }
        for (int j = 1 ; j <= r ; j ++){
            ha[tab[j]] ++ ;
        }
    }
    for (int i = 1 ; i <= m ; i ++){
        cout << ha[i] << ' ';
    }
    return 0 ;
}
