#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;

ll n, m, a[N], sum[N], ans;

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++ ) sum[i] = sum[i - 1] + a[i];

    for (int i = 1; i <= n; i ++ ) {
        int l = 1, r = i, pos = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, (ll)i - pos + 1);
    }

    cout << ans;

    return 0;
}