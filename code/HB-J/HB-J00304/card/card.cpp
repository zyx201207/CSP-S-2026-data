#include <bits/stdc++.h>
#define lx int

using namespace std;
const lx N = 5e5 + 5;
lx n , m , a[N] , k , c[N] , ans[N] , sum[N];
bool flagA = 1 , vis[N];
int main () {
    freopen ("card.in" , "r" , stdin);
    freopen ("card.out" , "w" , stdout);
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> n >> m;
    for (lx i = 1 ; i <= n ; i ++) cin >> a[i];
    for (lx i = 1 ; i < n ; i ++) {
        if (a[i] > a[i + 1]) flagA = 0;
    }
    if (n <= 500) {
        for (lx i = 1 ; i <= n ; i ++) {
            k = 0;
            for (lx j = i ; j <= n ; j ++) {
                c[++ k] = a[j];
                for (lx l = 1 ; l < k ; l ++) {
                    if (c[l] == a[j]) {
                        k = l;
                        break;
                    }
                }
            }
            for (lx j = 1 ; j <= k ; j ++) ans[c[j]] ++;
        }
        for (lx i = 1 ; i <= m ; i ++) cout << ans[i] << " ";
    }
    else if (flagA == 1) {
        for (lx i = 1 ; i <= n ; i ++) {
            ans[a[i]] = max (ans[a[i]] , i);
        }
        for (lx i = 1 ; i <= m ; i ++) cout << ans[i] << " ";
    }
    return 0;
}
