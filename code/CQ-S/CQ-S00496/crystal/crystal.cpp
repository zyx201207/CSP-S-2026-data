#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[500005];
long long s[500005];

bool check(int l, int r) {
    long long ss = (r - l + 1) * a[r] - s[r] + s[l - 1];
    return ss <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = 1, r = i + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, i)) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}