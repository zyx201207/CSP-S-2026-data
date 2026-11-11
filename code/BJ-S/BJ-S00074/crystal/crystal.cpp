#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m;
ll a[500021];
ll sum[500021];

bool check(ll k) {
    for (int i = k; i <= n; i++) {
        if ((k-1) * a[i] - (sum[i-1]-sum[i-k-1]) <= m) {
            return true;
        }
    }
    return false;
}

ll b_search(ll l, ll r) {
    ll ans;
    while (l <= r) {
        ll mid = (l+r) >> 1;
        if (check(mid)) {
            l = mid+1;
            ans = mid;
        } else {
            r = mid-1;
        }
    }
    return ans;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%ld %ld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%ld", &a[i]);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    printf("%ld", b_search(1, n));
    return 0;
}
