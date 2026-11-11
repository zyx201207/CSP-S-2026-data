#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using ll = long long;
constexpr int MAXN = 5e5 + 5;
int n;
ll m, a[MAXN], s[MAXN];
int main() {
    IOS;
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
        int L = 1, R = i, mid, pos = i;
        while (L <= R) {
            mid = (L + R) >> 1;
            if ((ll)a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) pos = mid, R = mid - 1;
            else L = mid + 1;
        }
        ans = max(ans, i - pos + 1);
    }
    cout << ans << '\n';
    return 0;
}