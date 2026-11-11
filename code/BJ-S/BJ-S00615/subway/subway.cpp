#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;

const int maxn = 5e5 + 10, inf = 1e18, mod = 1e9 + 7;
int w[maxn];
struct node {
    int v, w;
}; vector<node> g[maxn];
int d[510][510];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, n, m, dd, q;
    cin >> c >> m >> n >> dd >> q;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int p, t;
            cin >> p >> t;
            g[p].pb({i, t});
        }
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= m; i++) d[i][i] = 0;
    for (int i = 1; i <= n; i++) 
        for (node j : g[i]) 
            for (node k : g[i])
                d[k.v][j.v] = d[j.v][k.v] = min(d[j.v][k.v], j.w + k.w);
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= m; k++)
            for (int j = 1; j <= m; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = inf;
        for (node i : g[l])
            for (node j : g[r]) 
                ans = min(ans, w[l] + w[r] + i.w + j.w + d[i.v][j.v]);
        cout << ans << endl;
    }
    return 0;
}
/*
g++ subway.cpp -o a -O2 -std=c++14 -fsanitize=address,leak,undefined
为什么跑得这么慢,1.29s
3e8不会死的对吧
相信FCC
求你了FCC求你了别卡我,我只是一个O(d^2m+n^3+d^2q)啊不会死的不会死
*/