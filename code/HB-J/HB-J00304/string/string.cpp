#include <bits/stdc++.h>
#define lx long long

using namespace std;
lx n , k , ans;
char c;
string s;
int main () {
    freopen ("string.in" , "r" , stdin);
    freopen ("string.out" , "w" , stdout);
    ios::sync_with_stdio (0);
    cin.tie (0);
    cin >> n;
    for (lx i = 1 , m ; i <= n ; i ++) {
        cin >> m >> c;
        for (lx j = 1 ; j <= m ; j ++) {
            s[k ++] = c;
        }
    }
    lx l = 0 , r = k - 1;
    while (l <= r) {
        if (s[l] != s[r]) ans ++;
        l ++ , r --;
    }
    cout << ans;
    return 0;
}
