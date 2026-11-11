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

    constexpr int N = 5e5 + 10;
    int n;
    ll m;
    ll a[N], sum[N];

    int main() {
        cin >> n >> m;
        rep(i, 1, n) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        rep(i, 1, n) {
            sum[i] = sum[i - 1] + a[i];
        }
        ll res = 0;
        rep(i, 1, n) {
            int l = 1, r = i;
            while (l < r) {
                int mid =l + r >> 1;
                if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid;
                else l = mid + 1;
            }
            chkmax(res, i - r + 1);
        }
        cout << res << endl;

        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    return xieheng24::main();
}