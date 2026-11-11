#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
struct name{
    int x, ti;
};
vector<int> g[N];
int s[N];
int a[N];
int x, y, ans;
void dfs(int u) {
    if (u == y) {
        return ;
    }
    ans += s[u];
    for (int i = 0; i < g[u].size(); i ++) dfs(g[u][i]);
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> s[i];
    for (int i = 1; i <= n; i ++) {
         int k;cin >> k;
         if (k == 0) continue;
         int l1, r1;cin >> l1 >> r1;
         s[l1] += r1;
         for (int j = 1; j < k; j ++) {
            int l, r;cin >> l >> r;
            s[l] += r;
            g[l1].push_back(l);
            l1 = l;
         }
    }
    //for (int i = 1; i <= m; i ++) cout << s[i] << ' ';
    while (q --) {
        cin >> x >> y;
        ans = 0;
        dfs(x);
        cout << ans << '\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3   1 5  2 7  4 6
3   2 3  3 4  5 7
1 3
1 2
*/
