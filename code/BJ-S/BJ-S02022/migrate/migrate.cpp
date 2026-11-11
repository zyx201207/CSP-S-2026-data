#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)) f = (c == '-' ? -1 : f), c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N = 2e6 + 5;
int ttt, n, d, x[N], ll[N], rr[N];
namespace sub1 {
    int tn, dis[N], tot[N], ans, bit[N];
    vector<int> hs;
    void vadd(int x, int y) {
        for(int i = x; i <= n; i += i & -i) bit[i] += y;
    }
    int query(int x) {
        int tot = 0;
        for(int i = x; i; i -= i & -i) tot += bit[i];
        return tot;
    }
    void add(int l, int r, int k) {
        if(l > r) return;
        vadd(l, k), vadd(r + 1, -k);
    }
    void solve() {
        ans = 0;
        for(int i = 1; i <= n; i++) {
            hs.clear();
            int nw = i;
            while(nw != n) {
                if(nw == rr[nw]) break;
                hs.push_back(rr[nw]);
                nw = rr[nw];
            }
            add(i + 1, rr[i], 1);
            for(int j = 0; j < (int)hs.size() - 1; j++) {
                int ltl = (j == 0 ? i + 1 : hs[j - 1] + 1), rtr = hs[j];
                for(int k = ltl; k <= rtr; k++) add(hs[j] + 1, rr[k], min(4ll, query(k)));
            }
            for(int j = 1; j <= n; j++) if(query(j) == 2) ans++;
            for(int j = 1; j <= n; j++) bit[j] = 0;
        }
        cout << ans << "\n";
    }
}
namespace sub2 {
    void solve() {
        int ln = d / (x[2] - x[1]), ans = 0;
        for(int i = 1; i <= n; i++) if(i - 2 * ln + 1 >= 1) ans++;
        if(ln <= 1) ans = 0;
        cout << ans << "\n";
    }
}
bool chk1() {
    for(int i = 2; i <= n; i++) if(x[i] - x[i - 1] != x[2] - x[1]) return 0;
    return 1;
}
void solve() {
    n = read(), d = read();
    for(int i = 1; i <= n; i++) x[i] = read();
    if(n == 1) return cout << "0\n", void();
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l <= r) {
            int mid = l + r >> 1;
            if(x[i] - x[mid] <= d) ll[i] = mid, r = mid - 1;
            else l = mid + 1;
        }
        l = i, r = n;
        while(l <= r) {
            int mid = l + r >> 1;
            if(x[mid] - x[i] <= d) rr[i] = mid, l = mid + 1;
            else r = mid - 1;
        }
    }
    if(1 <= ttt && ttt <= 10) {
        sub1 :: solve();
        return;
    }
    if(chk1()) {
        sub2 :: solve();
        return;
    }

}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ttt = read();
    int T = read();
    while(T--) solve();
    return 0;
}
