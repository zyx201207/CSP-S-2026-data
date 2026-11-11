#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6 + 5;
int a[MAXN], pre[MAXN], nxt[MAXN], wl[MAXN], wr[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--){
        int n, d;
        cin >> n >> d;
        for (int i = 0; i <= n + 1; i++) wl[i] = wr[i] = 0, pre[i] = nxt[i] = 0;
        pre[n + 1] = n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++){
            nxt[i] = max(nxt[i - 1], i);
            while (nxt[i] < n && a[nxt[i] + 1] - a[i] <= d) nxt[i]++;
        }
        for (int i = n; i >= 1; i--){
            pre[i] = min(pre[i + 1], i);
            while (pre[i] > 1 && a[i] - a[pre[i] - 1] <= d) pre[i]--;
        }
        for (int i = 1; i <= n; i++) wl[nxt[i]] += nxt[i] != i;
        for (int i = 1; i <= n; i++){
            if (nxt[pre[i]] == i) wl[i] += wl[pre[i]];
        }
        for (int i = n; i >= 1; i--) wr[pre[i]] += pre[i] != i;
        for (int i = n; i >= 1; i--){
            if (pre[nxt[i]] == i) wr[i] += wr[nxt[i]];
        }
        int ans = 0;
        for (int i = 3; i < n; i++){
            if (pre[i] == pre[i - 1] && nxt[pre[i]] == i && nxt[i] == nxt[i - 1] && pre[nxt[i - 1]] == i - 1){
                ans += wl[pre[i]] * wr[nxt[i]];
            }
            int l1 = pre[i];
            int r1 = min(i - 2, pre[i + 1] - 1);
            int l2 = max(i + 1, nxt[i - 2] + 1);
            int r2 = nxt[i - 1];
            if (pre[i] == pre[i - 1] && nxt[pre[i]] == i){
                ans += wl[pre[i]] * max(0ll, r2 - l2 + 1);
            }
            if (nxt[i] == nxt[i - 1] && pre[nxt[i - 1]] == i - 1){
                ans += wr[nxt[i]] * max(0ll, r1 - l1 + 1);
            }
            ans += max(0ll, r1 - l1 + 1) * max(0ll, r2 - l2 + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}