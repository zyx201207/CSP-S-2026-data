#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define _pair array<int, 2>
#define For(i, l, r) for (auto i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (auto i = (r); i >= (l); --i)
#define pb push_back
#define forT() int _; for (cin >> _; _--; solve())
template<typename T> void cmax(T& x, T y) { x = max(x, y); }
template<typename T> void cmin(T& x, T y) { x = min(x, y); }
#define N 500050
int n; ll m, a[N], pre[N];
void solve() {
    cin >> n >> m;
    For (i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    For (i, 1, n) pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    For (i, 1, n) {
        int res = i;
        for (int l = 1, r = i - 1; l <= r; ) {
            int mid = l + r >> 1;
            if (a[i] * (i - mid + 1) - pre[i] + pre[mid - 1] <= m) {
                res = mid, r = mid - 1;
            }
            else l = mid + 1;
        }
        cmax(ans, i - res + 1);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    solve();
    return 0;
}