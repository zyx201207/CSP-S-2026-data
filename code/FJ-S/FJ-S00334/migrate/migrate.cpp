#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5; 
int nxt[N], pre[N], a[N], f[N], g[N], cnt[N], ok[N], mn[N], mx[N];
int Sum = 0; 
inline void solve() {
    int n, d; cin >> n >> d; Sum += n; 
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    for (int i = n, j = n; i; i--) {
        while (a[j] - a[i] > d) j--;
        nxt[i] = j;
    }
    for (int i = 1, j = 1; i <= n; i++) {
        while (a[i] - a[j] > d) j++;
        pre[i] = j; 
    }
    for (int i = n, j = n, k = n; i; i--) {
        while (pre[j] > i) j--;
        mx[i] = j; 
        while (pre[k - 1] >= i) k--;
        mn[i] = k; 
    }
    for (int i = n; i; i--) {
        if (nxt[i] == i) f[i] = i, cnt[i] = g[i] = 0, ok[i] = 0;
        else {
            int j = nxt[i];
            if (pre[j] < i) {
                f[i] = i, cnt[i] = g[i] = 0; 
                if (pre[j] == i - 1 && pre[pre[j]] == pre[i])
                    g[i] = j - mn[i - 1] + 1, ok[i] = 1;
                else ok[i] = 0; 
            } else {
                f[i] = f[j], g[i] = g[j], ok[i] = ok[j]; 
                if (pre[i] < i - 1 && pre[i - 1] == pre[i])
                    g[i] += mx[i - 1] - mn[i - 1] + 1; 
                cnt[i] = cnt[j] + j - mn[i] + 1; 
            }
        }
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
        if (nxt[i] == i) continue; 
        int j = nxt[i];
        if (nxt[j] == j) continue; 
        int t = nxt[j]; 
        if (j - 1 > i) {
            if (pre[t] ^ j) {
                if (pre[t] < j - 1) continue;
                ans += t - mn[j - 1] + 1 + cnt[t];
                continue; 
            } else ans += mx[j - 1] - mn[j - 1] + 1; 
        }
        j = t; ans += g[j];  
        if (ok[j]) ans += cnt[nxt[f[j]]]; 
    }
    cout << ans << '\n'; 
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _, T; cin >> _ >> T;
    while (T--) solve(); 
    // cerr << Sum << '\n'; 
    return 0; 
}