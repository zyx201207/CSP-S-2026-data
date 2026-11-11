#include <bits/stdc++.h>
#define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rloop(i, a, b) for(omt i = (a) ; i >= (b) ; i--)
#define chkmax(x, y) ((x) = max((x), (y)))
#define chkmin(x, y) ((x) = min((x), (y)))
#define mid (((l) + (r)) / 2)
#define lowbit ((x) & (-(x)))
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
int find(int i) {
    int l = 0, r = i + 1;
    while(l + 1 < r) {
        if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid;
        else l = mid;
    }
    return i - r + 1;
}
void solve() {
    cin >> n >> m;
    loop(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    loop(i, 1, n) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    loop(i, 1, n) chkmax(ans, find(i));
    cout << ans << '\n';
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}