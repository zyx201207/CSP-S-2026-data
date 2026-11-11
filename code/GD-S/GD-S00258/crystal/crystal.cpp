#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 500005;
ll n, m, ans;
ll a[N], sum[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (ll i = 1; i <= n; i++) {
        int l = 1, r = i, pos = i;
        while (l <= r) {
            int mid = l + r >> 1;
            if ((__int128)(i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = (pos = mid) - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - pos + 1);
    }
    cout << ans;
    return 0;
}