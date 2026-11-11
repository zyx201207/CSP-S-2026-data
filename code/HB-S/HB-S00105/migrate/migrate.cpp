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
    ll c, t;
    ll n, d, a[2000100];

    void main () {
        cin >> c >> t;
        if (c == 11 or c == 12) {
            while (t --> 0) {
                n = read(), d = read();
                for (int i = 1; i <= n; ++i) 
                    a[i] = read();
                ll c = abs(a[2] - a[1]);
                // cout << "c: "<< c << " d: " << d << endl;
                int t = d / c;
                // cout << "t : " << t << endl;
                if (d < 2 * c) {
                    write(0);
                    puts("");
                    continue;
                }
                if (n - t * 2 + 1 < 0) {
                    write(0);
                    puts("");
                    continue;
                }
                write(n - t * 2 + 1);
                puts("");

            }
        }
        return;
    }
}
int main () {
    OIer::open("migrate");
    OIer::main();
    return 0;
}