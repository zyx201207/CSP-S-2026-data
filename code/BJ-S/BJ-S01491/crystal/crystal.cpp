#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 1;
ll n, m, a[N], ans, cnt1, cnt2;

// 判断前 lim 个是否够合成水晶
bool check(ll lim) {
    ll res = 0, pivot = a[lim];
    for (int i = 2; i < lim; i++) {
        res += abs(pivot - a[i]);
    }
    return res <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll l = 1, r = n;
    // 二分
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}

// Oct31==Dec25?
