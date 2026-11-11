#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long n, m; 

int check(int k) {
    long long cnt = a[k - 1] * k, res = 1e18 + 5;
    for (int i = 0; i < k; ++i) {
        cnt -= a[i];
    }
    res = min(res, cnt);
    for (int i = k; i < n; ++i) {
        cnt += a[i - k];
        cnt -= a[i - 1] * k;
        cnt += a[i] * k;
        cnt -= a[i];
        res = min(res, cnt);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    long long l = 1, r = n;
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid) > m) {
            r = mid - 1;
            ans = r;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}