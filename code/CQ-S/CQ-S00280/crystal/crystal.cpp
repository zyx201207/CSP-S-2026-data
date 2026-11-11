#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;

int main() {
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    
    sort(a.begin() + 1, a.end()); ll res = 0, ans = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    
    auto check = [&](ll x, ll res, ll i) -> bool {
        ll s = res - x * a[i] + (sum[x] - sum[0]);
        return s <= m;
    };

    for (int i = 1; i <= n; i++) {
        if (i != 1) res += (i - 1) * (a[i] - a[i - 1]);

        if (res <= m) ans = i;
        else {
            ll l = 1, r = i, ans_ = -1;
            while (l <= r) {
                ll mid = l + r >> 1;

                if (check(mid, res, i)) ans_ = mid, r = mid - 1;
                else l = mid + 1;
            }
            // if (ans_ == -1) break;

            // cerr << "i = " << i << ", res = " << res << ", res - ans_ = " << res - ans_ * a[i] + sum[ans_] - sum[0] << endl;
            ans = max(ans, i - ans_);
        }
    }

    cout << ans;
    return 0;
}