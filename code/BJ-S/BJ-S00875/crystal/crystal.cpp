#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500005;
int n, m, a[N], l, r, ans = 0;

signed main() {
    // Solution. Two-pointer & Summation transformation
    // found at 15:23
    // finished at 15:35

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    r = l = n;

    while(r >= 1) {
        while(m >= 0 && l >= 1) {
            ans = max(ans, r - l + 1);
            // printf("%d %d %d\n", l, r, m);
            l--;
            m -= (a[r] - a[l]);


        }
        if(!l) break;
        while(m < 0) {
            // printf("%d %d %d\n", l, r, m);
            m += (a[r] - a[r - 1]) * (r - l);
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}

