#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 200005;
ll n, ans;
ll a[N];
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    for (int l = 1, r = n; l <= r; ) {
        if (c[l] == c[r]) {
            if (a[l] > a[r]) a[l] -= a[r], r--;
            else if (a[l] == a[r]) a[l] = a[r] = 0, l++, r--;
            else a[r] -= a[l], l++;
        }
        else {
            if (a[l] > a[r]) ans += a[r], a[l] -= a[r], r--;
            else if (a[l] == a[r]) ans += a[l], a[l] = a[r] = 0, l++, r--;
            else ans += a[l], a[r] -= a[l], l++;
        }
    }
    cout << ans;
    return 0;
}