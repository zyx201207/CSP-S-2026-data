#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

const int N = 5e5 + 10;
int a[N], s[N];

bool chk(int x, int i) {
    int avg = a[i];
    if ((i - x + 1) * avg - (s[i] - s[x - 1]) <= m) return true;
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int mx = -2e9;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i + 1] || i == n) {
            int l = 1, r = i - 1, ans = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (chk(mid, i)) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            mx = max(mx, i - ans + 1);
        }
    }
    cout << mx;
    return 0;
}
