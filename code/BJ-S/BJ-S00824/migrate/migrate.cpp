#include <bits/stdc++.h>
using namespace std;

namespace xieheng24 {
    #define endl '\n'
    #define rep(i, a, b) for (int i = (a); i <= (b); ++i)
    #define _rep(i, a, b) for (int i = (a); i < (b); ++i)
    #define per(i, a, b) for (int i = (a); i >= (b); --i)
    typedef long long ll;
    typedef unsigned long long ull;

    template<typename T, typename T1> 
    __inline void chkmax(T& x, T1 y) {
        if (y > x) x = y;
    }

    template<typename T, typename T2>
    __inline void chkmin(T& x, T2 y) {
        if (y < x) x = y;
    }

    constexpr int N  = 310;
    int c, T;
    int n;
    ll d;
    ll a[N];
    ll fm[N][N], fc[N][N];

    void solve() {
        cin >> n >> d;
        rep(i, 1,n ) {
            cin >> a[i];
        }
        ll res= 0;
        memset(fm, 0x3f ,sizeof fm);
        rep(i, 1, n) {
            fm[i][i] = 0;
            fc[i][i] = 1;
            rep(j, i + 1, n) {
                per(k, j - 1, i) {
                    if (a[j] - a[k] > d) break;
                    if (fm[i][k] >= 0x3f3f3f3f3f3f3f3f / 2) continue;
                    ll t= fm[i][k] + 1;
                    if (t == fm[i][j]) {
                        fc[i][j] += fc[i][k];
                    }
                    else if (t < fm[i][j]) {
                        fm[i][j] = t;
                        fc[i][j] = fc[i][k];
                    }
                }
                if (fc[i][j] == 2 && fm[i][j] < 0x3f3f3f3f3f3f3f3f / 2) {
                    // if (n == 8) cout << i << " " << j << " " << fm[i][j] << endl;
                    ++res;
                }
            }
        }
        cout << res << endl;
    }

    int main() {
        cin >> c >> T;
        while (T--) {
            solve();
        }

        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    return xieheng24::main();
}