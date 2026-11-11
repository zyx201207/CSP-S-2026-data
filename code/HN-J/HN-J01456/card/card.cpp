#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 5e5 + 5;
int n, m, a[NR], lst[NR], ans[NR], sz[NR];
vector<pair<int, int> > g[NR];
bitset<NR> b;
void dfs(int x, int lst) {
    sz[x] = 1;
    for (const auto &i : g[x])
        if (i.first != lst) {
            int x = b[i.second];
            b[i.second] = 1;
            if (!x)
                ans[i.second] += sz[i.first];
            dfs(i.first, x);
            b[i.second] = x;
        }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; ++ i) {
        sz[i] ++;
        sz[lst[a[i]] + 1] += sz[i];
        g[lst[a[i]] + 1].emplace_back(i, a[i]);
    }
    dfs(n + 1, 0);
    for (int i = 1; i <= m; ++ i)
        cout << ans[i] << " \n"[i == m];
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    // cin >> oT_To;
    while (oT_To --)
        solve();
    return 0;
}
