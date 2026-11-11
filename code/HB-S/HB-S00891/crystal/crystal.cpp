#include <bits/stdc++.h>
#define loop(i, a, b) for(int i = (a); i <= (b); i++)
#define rloop(i, a, b) for(int i = (a); i >= (b); i--)
#define lowbit(x) ((x) & (-(x)))
typedef long long ll;
using namespace std;
const int N = 5e5 + 5;

ll n, m;
ll a[N], b[N];
void solve() {
    cin >> n >> m;
    loop(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    loop(i, 1, n) b[i] = a[i] - a[i - 1];
    ll l = 1, res = 0, ans = 1;
    loop(r, 1, n) {
        res += (r - l) * b[r];
        while(l <= r && res > m) res -= (a[r] - a[l]), l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
}

signed main() {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
//g++ a.cpp -o a -O2 -static -std=c++14
//./a

