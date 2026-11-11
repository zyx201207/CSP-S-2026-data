#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e6 + 10;
#define ll long long
ll x[N]; int l[N], dp[N], cnt[N];
struct seg { int minn, sum; } s[N << 2];
int min(int x, int y) { return x < y ? x : y; }
void pushup(int u) {
    int ls = u << 1, rs = u << 1 | 1;
    s[u].minn = min(s[ls].minn, s[rs].minn); s[u].sum = 0;
    if (s[u].minn == s[ls].minn) s[u].sum += s[ls].sum; if (s[u].minn == s[rs].minn) s[u].sum += s[rs].sum;
}
void build(int l, int r, int u) {
    s[u].minn = 0x3f3f3f3f; s[u].sum = 0;
    if (l == r) return ;
    int mid = (l + r) >> 1, ls = u << 1, rs = u << 1 | 1;
    build(l, mid, ls); build(mid + 1, r, rs);
}
seg query(int l, int r, int L, int R, int u) {
    if (l <= L && R <= r) return s[u];
    int mid = (L + R) >> 1, ls = u << 1, rs = u << 1 | 1;
    if (l <= mid && r > mid) {
        seg lans = query(l, r, L, mid, ls), rans = query(l, r, mid + 1, R, rs);
        seg ans; ans.minn = min(lans.minn, rans.minn); ans.sum = 0;
        if (lans.minn == ans.minn) ans.sum += lans.sum; if (rans.minn == ans.minn) ans.sum += rans.sum;
        return ans;
    } else if (l <= mid) return query(l, r, L, mid, ls); else return query(l, r, mid + 1, R, rs);
}
void update(int p, int l, int r, int u, int x, int y) {
    if (l == r) { s[u].minn = x; s[u].sum = y; return ; }
    int mid = (l + r) >> 1, ls = u << 1, rs = u << 1 | 1;
    if (p <= mid) update(p, l, mid, ls, x, y); else update(p, mid + 1, r, rs, x, y); pushup(u);
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n; ll d;
        cin >> n >> d;
        if (n == 1) { cout << "0" << "\n"; continue; }
        for (int i = 1; i <= n; ++i) cin >> x[i];
        if (c == 11 || c == 12) {
            if (d < 2 * (x[2] - x[1])) { cout << "0" << "\n"; continue; }
            cout << max(n - 2 * (d / (x[2] - x[1])) + 1, 0ll) << endl;
        } else {
            for (int i = 1; i <= n; ++i) l[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
            int ans = 0;
            for (int st = 1; st <= n; ++st) {
                build(st, n, 1); dp[st] = 0; cnt[st] = 1;
                update(st, st, n, 1, dp[st], cnt[st]);
                for (int i = st + 1; i <= n; ++i) {
                    seg res = query(max(l[i], st), i, st, n, 1);
                    dp[i] = res.minn + 1, cnt[i] = min(res.sum, 3);
                    if (dp[i] > 0x3f3f3f3f) break;
                    update(i, st, n, 1, dp[i], cnt[i]);
                    if (cnt[i] == 2) ++ans; 
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}