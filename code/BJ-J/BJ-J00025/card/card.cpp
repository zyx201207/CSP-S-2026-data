#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[300005], last[300005], ans[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    bool f = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            f = 0;
            break;
        }
    }
    if (f) {
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i + 1]) {
                ans[a[i]] = i;
            }
        }
        ans[a[n]] = n;
        for (int i = 1; i <= m; i++) {
            cout << ans[i] << ' ';
        }
        return 0;
    }
    if (m == 2) {
        int ans_special[5];
        memset(ans_special, 0, sizeof(ans_special));
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[n]) {
                ans_special[1]++;
                ans_special[2]++;
            } else {
                ans_special[a[n]]++;
            }
        }
        cout << ans_special[1] << ' ' << ans_special[2];
        return 0;
    }
    for (int o = 1; o <= n; o++) {
        int aa[300005];
        memset(aa, 0, sizeof(aa));
        for (int i = o; i <= n; i++) {
            i = last[a[i]];
            if (!aa[a[i]]) {
                aa[a[i]] = 1;
                ans[a[i]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
