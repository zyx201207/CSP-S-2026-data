#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
#define pb push_back
#define all(x) begin(x), end(x)
using namespace std;
const int N = 5e5 + 2;
int n, m, last, lp, a[N], lst[N], cnt[N], ans[N];
vector<int> pos[N];
void dfs(int u) {
    if (u > n) return;
    if (lst[a[u]] == u) ans[a[u]]++, dfs(u + 1);
    else dfs(lst[a[u]]);
}
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i], lst[a[i]] = i;
    rep(i, 1, n) dfs(i);
    rep(i, 1, m) cout << ans[i] << ' ';
    return 0;
}
// rep(i, 1, m) pos[i].pb(0);
// rep(i, 1, n) cin >> a[i], lst[a[i]] = i, pos[a[i]].pb(i);
// pre(i, n, 1) if (i == lst[a[i]]) {
//     if (!last) { last = a[i], lp = i, ans[a[i]] = n; continue; }
//     int tot = 0;
//     pre(j, pos[a[i]].size() - 1, 1) {
//         auto p = upper_bound(all(pos[last]), pos[a[i]][j]);
//         if (p == begin(pos[last])) break;
//         p--;
//         if (*p > pos[a[i]][j - 1]) tot += *p - pos[a[i]][j - 1];
//     }
//     cout << tot << ' ' << a[i] << ' ' << last << '\n';
//     ans[a[i]] = ans[last] - tot - (lp - i);
//     last = a[i], lp = i;
// }
// 我没有光明的未来