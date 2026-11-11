#include <bits/stdc++.h>
#define lx long long

using namespace std;
const lx N = 5e5 + 5;
lx n , m , a[N] , b[N] , sum[5005][5005] , ans;
bool flagA = 1 , flagB = 1;
int main () {
    freopen ("crystal.in" , "r" , stdin);
    freopen ("crystal.out" , "w" , stdout);
    ios::sync_with_stdio (0);
    cin.tie (0);
    cin >> n >> m;
    for (lx i = 1 ; i <= n ; i ++) {
         cin >> a[i];
         if (a[i] != i) flagA = 0;
    }
    lx sumB = a[2] - a[1];
    for (lx i = 2 ; i < n ; i ++) {
        if (a[i + 1] - a[i] != sumB) flagB = 0;
    }
    sort (a + 1 , a + n + 1);
    for (lx i = 2 ; i <= n ; i ++) {
        b[i - 1] = a[i] - a[i - 1];
    }
    if (flagA == 1) {
        lx k = m;
        for (lx i = 1 ; i <= n ; i ++) {
            if (k >= i) k -= i , ans ++;
            else break;
        }
        cout << ans;
    }
    else if (flagB == 1) {
        lx cnt = sumB , k = m;
        for (lx i = 1 ; i <= n ; i ++) {
            if (k >= cnt) k -= cnt , ans ++;
            else break;
            cnt += sumB;
        }
        cout << ans;
    }
    else if (n <= 5000) {
        for (lx i = 1 ; i < n ; i ++) {
        lx cnt = 0;
            for (lx j = i ; j < n ; j ++) {
                cnt ++;
                sum[i][j] = b[j] * cnt;
            }
        }
        for (lx i = 1 ; i < n ; i ++) {
            lx cnt = 1 , k = m;
            for (lx j = i ; j < n ; j ++) {
                if (k >= sum[i][j]) k -= sum[i][j] , cnt ++;
            }
            ans = max (ans , cnt);
        }
        cout << ans;
    }
    return 0;
}
