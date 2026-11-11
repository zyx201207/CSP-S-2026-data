#include <bits/stdc++.h>
using namespace std;
namespace OIer {
    namespace IO {
        typedef long long ll;
        inline ll read() {
            ll x = 0, f = 1;
            char ch = getchar();
            while (ch < '0' || ch > '9') {
                if (ch == '-') f = -1;
                ch = getchar();
            }
            while (ch >= '0' && ch <= '9') {
                x = x * 10 + (ch - '0');
                ch = getchar();
            }
            return x * f;
        }
        template<typename T> inline void write(T x) {
            if (x < 0) putchar('-'), x = -x;
            if (x > 9) write(x / 10);
            putchar((x % 10) + '0');
            return;
        }
        inline void open(string s) {
            string in = s + ".in", out = s + ".out";
            freopen (in.c_str(), "r", stdin);
            freopen (out.c_str(), "w", stdout);
        }
    }
    using namespace IO;
    ll n, m, a[1000100], sum[1000100];
    void main () {
        n = read(), m = read();
        for (int i = 1; i <= n; ++i) 
            a[i] = read();
        sort(a + 1, a + n + 1, [](ll x, ll y) {
            return x > y;
        });
        for (int i = n; i >= 1; --i) {
            sum[i] = sum[i + 1] + a[i];
        }
        ll ans = -0x3f3f3f3f3f3f3f3f;
        for (int k = 1; k <= n; ++k) {
            ll ty = a[k];
            ll s = (n - k) * ty - sum[k + 1];
            ll l = k, r = n;
            while (l <= r) {
                ll mid = (l + r + 1) / 2;
                if (s + sum[mid + 1] <= m + (n - mid) * ty) {
                    l = mid + 1;
                } else 
                    r = mid - 1;
            }
            ans = max(ans, l - k);
        }
        write(ans);

        return;
    }
}
int main () {
    OIer::open("crystal");
    OIer::main();
    return 0;
}