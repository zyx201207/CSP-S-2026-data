#include <bits/stdc++.h>
#define lx int

using namespace std;
const lx N = 2e5 + 5;
lx n , m , a[N] , cnt[N] , ans , s[15];
bool vis[N] , flag , flagA = 1 , flagB = 1 , flagC = 1;
void dfs (lx pos) {
    if (pos > m) {
        lx sum = a[cnt[1]];
        for (lx i = 2 ; i <= m ; i ++) {
            // cout << cnt[i] << " ";
            sum &= a[cnt[i]];
        }
        ans = max (ans , sum);
        // cout << endl;
        return;
    }
    for (lx i = 1 ; i <= n ; i ++) {
        if (!vis[i]) {
            cnt[pos] = i;
            vis[i] = 1;
            dfs (pos + 1);
            vis[i] = 0;
        }
    }
}
int main () {
    freopen ("and.in" , "r" , stdin);
    freopen ("and.out" , "w" , stdout);
    cin >> n >> m;
    for (lx i = 1 ; i <= n ; i ++) {
        cin >> a[i];
        if (a[i] != i - 1) flagB = 0;
        if (a[i] >= 4) flagC = 0;
    }
    sort (a + 1 , a + n + 1);
    if (m == n) {
        for (lx i = 1 ; i <= n ; i ++) ans &= a[i];
        cout << ans;
    }
    else if (m == 1) {
        cout << a[n];
    }
    else if (m == 2) {
        for (lx i = 1 ; i <= n ; i ++) {
            for (lx j = i + 1 ; j <= n ; j ++) {
                if (i != j) ans = max (ans , a[i] & a[j]);
            }
        }
        cout << ans;
    }
    else if (flagC == 1) {
        for (lx i = 1 ; i <= n ; i ++) {
            s[a[i]] ++;
        }
        if (s[3] >= m) cout << "3";
        else if (s[3] + s[2] >= m) cout << "2";
        else cout << "1";
    }
    else if (n <= 20) {
        dfs (1);
        cout << ans;
    }
    else {
        ans = a[n];
        for (lx i = n - 1 ; i >= n - m + 1 ; i --) ans &= a[i];
        cout << ans;
    }
    return 0;
}
