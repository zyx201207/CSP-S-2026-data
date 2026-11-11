// 贵阳市第一中学 林钰涵 GZ-S00198
#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m, a[500005], s[500005];

long long calc(int l, int r) {
    return a[r] * (r - l + 1) - s[r] + s[l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int L = 0, R = i;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            if (calc(mid, i) <= m) R = mid;
            else L = mid;
        }
        ans = max(ans, i - R + 1);
    }
    cout << ans << '\n';
    return 0;
}
