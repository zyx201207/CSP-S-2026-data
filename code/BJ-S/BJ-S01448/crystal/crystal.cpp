#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;
ll n, m, a[N];
ll s[N];
ll suf[N];
ll ans;

int main() {
freopen("crystal.in", "r", stdin);
freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    bool flag1 = true, flag2 = true;
    for (int i = 1; i <= n; i++) if (a[i] != i) flag1 = false;
    for (int i = 2; i <= n; i++) if (abs(a[i] - a[i - 1]) != abs(a[2] - a[1])) flag2 = false;
    if (flag1 || flag2) {
        int i = n / 2;
        ll sum = 0;
        for (int j = 1; j <= n / 2; j++) s[j] = abs(a[i] - a[j]);
        ll j;
        for (j = 2; j <= n / 2; j++) {
            if (sum + s[j] > m) {
                ans = max(ans, j - 2);
                break;
            }
            sum += s[j];
        }
        cout << ans;
        return 0;
    }
    for (ll i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = 1; j <= i; j++) s[j] = abs(a[i] - a[j]);
        ll j;
        for (j = 2; j <= i; j++) {
            if (sum + s[j] > m) {
                ans = max(ans, j - 2);
                break;
            }
            sum += s[j];
        }
        if (j > i) ans = max(ans, (ll)i);
    }
    cout << ans;
    return 0;
}