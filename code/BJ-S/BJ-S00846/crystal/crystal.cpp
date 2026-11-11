#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Rof(i, j, k) for (int i = j; i >= k; -- i)
#define eb emplace_back
using namespace std;
using ll = long long;
using db = double;
using vi = vector<int>;
using pii = array<int, 2>;
const int N = 5e5 + 10;
int n;
ll a[N], m, pre[N];
ll sum(int l, int r) { return pre[r] - pre[l - 1]; }
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    For (i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    // For (i, 1, n) cout << a[i] << ' '; cout << '\n';
    For (i, 1, n) pre[i] = pre[i - 1] + a[i];
    int ans = 1;
    For (i, 1, n) { 
        // cout << "chk" << i << ':';
        // For (j, 1, i - 1) cout << a[i] * (i - 1 - j + 1) - sum(j, i - 1) << ' '; cout << '\n';
        if (a[i] - a[i - 1] > m) continue;
        int l = 1, r = i - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (1ll * a[i] * (i - 1 - mid + 1) - sum(mid, i - 1) <= m) r = mid;
            else l = mid + 1;
        }
        // cout << "!" << i << ':' << l << '\n';
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}