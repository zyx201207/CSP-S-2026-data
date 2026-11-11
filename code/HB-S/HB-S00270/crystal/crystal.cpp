#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll n, m, a[500005], l, r;

bool check(ll x) {
    ll ans = INF;
    for (int i = x - 1; i < n; i++) {
        ll sum = 0;
        for (int j = 1; j < x; j++) {
            sum += a[i] - a[i - j];
            if (sum > m)
                continue;
        }
        ans = min(ans, sum);
    }
    return ans <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    l = 1, r = n;
    sort(a, a + n);
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}
