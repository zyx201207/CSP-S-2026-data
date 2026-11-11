#include <bits/stdc++.h>
#define int long long
using namespace std;

int rd() {
    int s = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        s = (s << 3ll) + (s << 1ll) + c - '0';
        c = getchar();
    }
    return s * f;
}

const int N = 2e6 + 10;
int _c, _t, n, d;
int x[N], a[N];
int f[N][4];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    _c = rd(), _t = rd();
    while (_t--) {
        n = rd(), d = rd();
        for (int i = 1; i <= n; i++) x[i] = rd();
        sort(x + 1, x + n + 1);
        int r = 1;
        for (int i = 1; i <= n; i++) {
            while (r < n && x[r + 1] - x[i] <= d) r++;
            a[i] = r;
        }
        int ans = 0;
        for (int u = n; u; u--) {
            int v = a[u];
            if (u == v) { f[u][0] = n - u; continue; }
            int w = a[v];
            if (w == v) { f[u][1] = v - u, f[u][0] = n - v; continue; } 
            int k2 = v - 1, k3 = v - 2;
            int cl1 = 1, cl2 = 1;
            int t2 = v, t3 = v;
            if (k2 > u) cl1 += (a[k2] >= w), cl2 += (a[k2] >= (w - 1)), t2 = max(t2, a[k2]);
            if (k3 > u) cl1 += (a[k3] >= w), cl2 += (a[k3] >= (w - 1)), t3 = max(t3, a[k3]);
            if (w == v + 1) {
                if (cl1 == 1) {
                    f[u][1] = v - u + f[v][1], f[u][2] = f[v][2], f[u][3] = f[v][3], f[u][0] = f[v][0]; 
                } else if (cl1 == 2) {
                    f[u][1] = v - u, f[u][2] = f[v][1], f[u][3] = f[v][2] + f[v][3], f[u][0] = f[v][0];
                } else f[u][1] = v - u, f[u][3] = f[v][1] + f[v][2] + f[v][3], f[u][0] = f[v][0]; 
                ans += f[u][2];
                continue;
            } 
            int fv1 = f[v][1] - w + v;
            if (cl1 == 1 && cl2 == 1) {
                f[u][1] = w - u + fv1, f[u][2] = f[v][2], f[u][3] = f[v][3], f[u][0] = f[v][0]; 
            } else if (cl1 == 1 && cl2 >= 2) {
                f[u][1] = w - u + fv1, f[u][3] = f[v][2] + f[v][3], f[u][0] = f[v][0]; 
            } else if (cl1 == 2) {
                f[u][1] = w - u, f[u][2] = fv1, f[u][3] = f[v][2] + f[v][3], f[u][0] = f[v][0];
            } else f[u][1] = w - u, f[u][3] = fv1 + f[v][2] + f[v][3], f[u][0] = f[v][0]; 
            f[u][1] -= t2 - v, f[u][2] += t2 - t3, f[u][3] += t3 - v;
            ans += f[u][2];
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) {
            f[i][0] = f[i][1] = f[i][2] = f[i][3] = 0;
        }
    }
    return 0;
}

/*
g++ migrate.cpp -o1 -O2 -std=c++14
./1
diff migrate.out migrate1.ans
*/