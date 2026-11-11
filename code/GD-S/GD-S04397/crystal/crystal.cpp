#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 500010;
int n, ans;
ll m, a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int j = 1;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        while (1ll * (i - j + 1) * a[i] - sum > m) {
            sum -= a[j];
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << "\n";
}