#include<bits/stdc++.h>

using namespace std;
//rp++ 歪比巴卜

typedef long long ll;

ll n;
ll front = 1;
ll ju_li[500005];
ll a[500005], m, ans[500005];

bool ok(int mid, int i) {
    ll cnt = 0;
    for (ll j = mid; j <= i; j++)
        cnt += a[i] - a[j];
    return ju_li[i] - cnt < m;
}

int erfen(int i) {
    ll l = 0, r = m + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (ok(mid, i))
            r = mid;
        else
            l = mid;
    }
    return l;
}

bool deng_cha_shu_lie() {
    for (int i = 2; i < n; i++)
        if (a[i] - a[i - 1] != a[i + 1] - a[i])
            return false;
    return true;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if (deng_cha_shu_lie()) {
        cout << m / (a[2] - a[1]) + 1;
        return 0;
    }
    for (ll i = 1; i <= n; i++) {
        ju_li[i] = ju_li[i - 1] + (i - 1) * (a[i] - a[i - 1]);
        if (ju_li[i] > m) {
            ll x = front;
            front = erfen(i);
            ans[i] = i - front + 1;
        }
        else
            ans[i] = i - front + 1;
    }
    if (ju_li[n] <= m) {
        cout << n;
        return 0;
    }
    sort(ans + 1, ans + n + 1);
    cout << ans[n];
    return 0;
}
