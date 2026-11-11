#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
using ll = long long;
ll a[N], pre[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) r = mid;
            else l = mid;
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans;
    return 0;
}