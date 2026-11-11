#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
#define ll long long
#define mp make_pair 
int c, m, n, d, q;
const int M = 5e5 + 10;
const int N = 505;
int w[M];
int tim[N][M];
vector<int> stop[M];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' && ch < '0') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x < 10) {
        putchar(x + 48);
        return;
    }
    write(x / 10);
    putchar(x % 10 + 48);
} 
ll f[N][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    // cout << c << m << n << d << q;
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        int ki;
        ki = read();
        for (int j = 1; j <= ki; j++) {
            int ai, ti;
            ai = read(), ti = read();
            tim[i][ai] = ti;
            stop[ai].push_back(i);
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++) {
        if (stop[i].size() > 1) {
            for (int j = 0; j < stop[i].size(); j++) {
                for (int k = 0; k < stop[i].size(); k++) {
                    if (j == k) continue;
                    int u = stop[i][j], v = stop[i][k];
                    ll t = tim[u][i] + tim[v][i];
                    f[u][v] = min(f[u][v], t);
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)cout << f[i][j] << " ";
    //     cout << endl;
    // }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     f[i][i] = 0;
    //     for (int j = 1; j <= n; j++)cout << f[i][j] << " ";
    //     cout << endl;
    // }
    while (q--){
        int xr, yr;
        ll ans = 9e18;
        xr = read(), yr = read();  
        for (int i = 0; i < stop[xr].size(); i++) {
            for (int j = 0; j < stop[yr].size(); j++) {
                int u = stop[xr][i], v = stop[yr][j];
                if (u == v) {
                    ans = min(ans, 1ll * tim[u][xr] + tim[v][yr]);
                    continue;
                }
                ll w1 = 0, w2 = 0;
                if (stop[xr].size() >= 1) w1 = tim[u][xr];
                if (stop[yr].size() >= 1) w2 = tim[v][yr];
                ans = min(ans, f[u][v] + w1 + w2);
            }
        }
        write(ans + w[xr] + w[yr]);
        puts("");
    }
    return 0;
}