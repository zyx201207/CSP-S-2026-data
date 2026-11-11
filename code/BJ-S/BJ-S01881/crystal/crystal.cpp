#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 5e5 + 10;
ll n, m;
ll a[N], d[N], sum[N];
ll oo = 1e18;

inline ll check() {
    ll flag = d[2];
    for (ll i = 3; i <= n; ++i) {
        if (flag != d[i]) return -oo;
    }
    return flag;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; ++i) { 
        d[i] = a[i] - a[i - 1];
        sum[i] = sum[i - 1] + a[i];
    }   
    ll d = check();
    if (d != -oo) {
        if (d == 0) return cout << n, 0;
        ll cnt = d, ans = 1, it = 0;
        while (m > cnt && it <= n - 1) {
            m -= cnt;
            ++ans;
            cnt += d;
            ++it;
        }
        cout << ans;
    } else {
        int maxn = 1;
        for (int i = n; i >= 1; --i) {
            for (int j = 1; j < n; ++j) {
                int len = i - j + 1;
                if (maxn >= len) break;
                int plus = sum[i - 1] - sum[j - 1] - a[i] * (i - j + 1);
                if (plus <= m) {
                    maxn = len;
                }
            }
        }
        cout << maxn;
    }
    return 0;
}