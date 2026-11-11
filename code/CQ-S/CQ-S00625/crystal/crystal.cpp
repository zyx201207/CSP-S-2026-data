#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n;
LL m, a[N], pre[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1;i <= n;i++)
        pre[i] = pre[i - 1] + a[i];
    int mx = 0;
    for (int i = 1;i <= n;i++) {
        int l = 1, r = i, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        mx = max(mx, i - ans + 1);
    }
    cout << mx << "\n";
    return 0;
}