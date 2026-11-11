// Author: lzm0107
// 14:41

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    sort(a.begin(), a.end());
    vector<long long> prefix(a);
    for (int i = 1; i < n; i++) { prefix[i] += prefix[i - 1]; }
    int ans = numeric_limits<int>::min();
    auto rgs = [&](int l, int r) -> long long {
        if (l == 0) { return prefix[r]; }
        return prefix[r] - prefix[l - 1];
    };
    for (int i = n - 1; i >= 0; i--) {
        int l = -1, r = i;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            int len = i - mid + 1;
            long long cost = (long long)len * a[i] - rgs(mid, i);
            if (m >= cost) { r = mid; }
            else { l = mid; }
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans << '\n';
    return 0;
}