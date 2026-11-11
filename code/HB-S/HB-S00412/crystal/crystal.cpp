#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e5;
const ll M = 1e18;
ll n, m;
ll max_e;
ll min_e = 1e12;
ll a[N + 5];

ll need(ll target) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < target) {
            sum += target - a[i];
        }
    }
    return sum;
}

ll calc_cnt(ll target) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < target) {
            a[i] = target;
        }
        if (a[i] == target) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_e = max(max_e, a[i]);
        min_e = min(min_e, a[i]);
    }
    ll l = min_e;
    ll r = 1e13;
    ll mid, ans;

    while (l <= r) {
        mid = (r - l) / 2 + l;
        ll res = need(mid);
        if (res <= m) {
            ans = mid;
            if (res == m) {
                break;
            }
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << calc_cnt(ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}