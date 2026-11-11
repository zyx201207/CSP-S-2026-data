// 直接来手贪心（无证明），不喜勿喷
#include <bits/stdc++.h>
#define endl '\n'
#define inf 0x3f3f3f3f
using namespace std;
using ll = long long;
constexpr int maxn = 5e5 + 10;
ll a[maxn], d[maxn];
int n;
ll k, ans = -1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) d[i] = d[i - 1] + a[i];
    for(int i = 2; i <= n; i++) {
        int x = a[i];
        ll sum = x * (i - 1) - d[i - 1];
        if (sum <= k) ans = max(ans, (ll)i);
    }cout << ans << endl;
    return 0;
}