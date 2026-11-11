#include <bits/stdc++.h>
#define lx long long

using namespace std;
const lx N = 5e5 + 5;
lx c , T , n , d , a[N] , s[N];
int main () {
    freopen ("migrate.in" , "r" , stdin);
    freopen ("migrate.out" , "w" , stdout);
    cin >> c >> T;
    for (lx q = 1 ; q <= T ; q ++) {
        bool flagA = 1;
        cin >> n >> d;
        for (lx i = 1 ; i <= n ; i ++) cin >> a[i];
        lx sumA = a[2] - a[1];
        for (lx i = 1 ; i < n ; i ++) {
            if (a[i + 1] - a[i] != sumA || a[i + 1] - a[i] > d) flagA = 0;
        }
        if (flagA == 1) {
            lx cnt = d / sumA * 2;
            cout << n - cnt + 1 << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}
