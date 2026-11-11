#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;

const int maxn = 2e6 + 10, inf = 1e18, mod = 1e9 + 7;
int a[maxn];
// struct bit {
//     int t[maxn];
//     int lowbit(int x) { return x & -x; }
//     void add(int x, int k) { for (; x < maxn; x += lowbit(x)) t[x] += k; }
//     int ask(int x) {
//         int ans = 0;
//         for (; x; x -= lowbit(x)) ans += t[x];
//         return ans;
//     }
//     int ask(int l, int r) { return ask(r) - ask(l - 1); }
// } t;
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, tt;
    cin >> c >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (a[j] - a[i] <= k || a[j] - a[i] > 2 * k) continue;
                int cnt = 0;
                for (int wow = i; wow <= j; wow++) cnt += (a[wow] <= a[i] + k && a[wow] >= a[j] - k);
                if (a[j] - a[i] > k && a[j] - a[i] <= 2 * k && cnt == 2) {
                    cout << i << " " << j << " ";
                    int l = i, r = j, lc = 0, rc = 0;
                    while (1) {
                        int p = lower_bound(a + 1, a + n + 1, a[l] - k) - a;
                        if (a[l + 1] - a[p] <= k) break;
                        lc++, l = p;
                    }
                    while (1) {
                        int p = upper_bound(a + 1, a + n + 1, a[r] + k) - a - 1;
                        if (a[p] - a[r - 1] <= k) break;
                        rc++, r = p;
                    }
                    cout << (lc + 1) * (rc + 1) << endl;
                    ans += (lc + 1) * (rc + 1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
g++ migrate.cpp -o a -O2 -std=c++14 -fsanitize=address,leak,undefined
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 1
10 3
1 4 7 8 9 10 11 12 15 18

10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

4 7 12
4 8 4
5 9 0
6 9 3
*/