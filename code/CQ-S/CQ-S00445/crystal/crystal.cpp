#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define db double
#define i128 __int128_t

#define endl "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

using namespace std;

template <class T> void cmax (T &a, T b) {a = max(a, b); }
template <class T> void cmin (T &a, T b) {a = min(a, b); }

const int inf = 1e9;
const ll INF = 2e18;
const int mod = 1e9 + 7;
const db eps = 1e-6;
const int maxn = 1e5 + 7;
const int N = 1e6 + 7;

void solve () {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(all1(a));
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++) if (a[i] < a[i - 1]) cerr << i << endl;
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    // for (int i = 1; i <= n; i++) cout << sum[i] << ' ';
    // cout << endl;
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll l = 1, r = i, pos = i;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll need = a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
            // cerr << i << ' ' << mid << ' ' << need << endl;
            // if (mid > i) cerr << 1 << endl;
            // if (need < 0) {
            //     cerr << a[pos] * (i - mid + 1) << ' ' << (sum[i] - sum[mid - 1]) << endl;
            // }
            if (need <= m) r = mid - 1, pos = mid;
            else l = mid + 1;
        }

        cmax(ans, i - pos + 1);
        // cerr << i << ' ' << pos << endl;
    }

    cout << ans << endl;
} 

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
