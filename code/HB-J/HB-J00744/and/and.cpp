#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, a[N];

bool cmp (int x, int y) {
    return x > y;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (m == 1) {
        int maxn = INT_MIN;
        for (int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
        cout << maxn << '\n';
    }
    else if (m == n) {
        int ans = a[1];
        for (int i = 2; i <= n; i++) ans &= a[i];
        cout << ans << '\n';
    }

    else if (m == 2) {
        int maxn = INT_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int rec = a[i] & a[j];
                maxn = max(maxn, rec);
            }
        }
        cout << maxn << '\n';
    }
    else if (m == n - 1) {
        int maxn = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int ans = a[1];
            if (a[1] == 1) ans = a[2];
            for (int j = 1; j <= n; j++) {
                if (j == i)continue;
                ans = ans & a[j];
            }
            maxn = max(maxn, ans);
        }
        cout << maxn << '\n';
    }
    else {
        sort(a + 1, a + n + 1, cmp);
        int ans = a[1];
        for (int i = 2; i <= m; i++) ans &= a[i];
        cout << ans << '\n';
    }
    return 0;
}
