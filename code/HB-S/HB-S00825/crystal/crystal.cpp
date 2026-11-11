#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int N = 500005;

int n;
ll m, a[N], sum[N];

int main() {
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);

    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

    int ans = 0;

    for (int id = n; id; --id) {
        int l = 1, r = id, mid = 0, res = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            int len = id - mid + 1;
            ll need = a[id] * len - (sum[id] - sum[mid - 1]);
            if (need <= m) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, id - res + 1);
    }

    cout << ans << endl;

    true;

    return 0;
}