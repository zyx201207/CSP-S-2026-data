#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;
const int N = 5e5 + 10;
const int M = 1e13 + 5;
int n;
ll a[N], pre[N], m, ans = 0;
int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    ios ::sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; i ++) {
        int l = 1, r = i - 1;
        ll j = M;
        while (l <= r) {
            int mid = (l + r + 1) / 2;
            int k = pre[i - 1] - pre[mid - 1];
            if ((i - mid) * a[i] - k <= m) {
                j = (i - mid + 1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (j == M) j = 1;
        ans = max (ans, j);
    }
    cout << ans;
    return 0;
}
