// O(n^3) 假掉了
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int ll

const int N = 4e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int id;
int n, lim;
vector<int> e[N];
int /* d[N],  */tong[N];
int dep[N][N]/* , mx_d[N] */;
int ans;

void dfs(int u, int fa, int rt)
{
    dep[rt][u] = dep[rt][fa] + 1;
    // mx_d[rt] = max(mx_d[rt], dep[rt][u]);
    for (auto v : e[u])
        if (v != fa)
            dfs(v, u, rt);
}

void solve()
{
    cin >> n >> lim;
    ans = n;
    rep(i, 1, n) e[i].clear()/* , mx_d[i] = 0 */;
    ref(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    rep(rt, 1, n) dfs(rt, 0, rt);
    rep(a, 1, n) rep(b, a, n)
    {
        rep(i, 1, n) tong[i] = 0;
        int mx = 0;
        rep(i, 1, n) tong[min(dep[a][i], dep[b][i])]++, mx = max(mx, min(dep[a][i], dep[b][i]));
        int cnt = 0;
        rep(i, 1, mx)
        {
            if (cnt + tong[i] <= lim) cnt += tong[i], ans = min(ans, mx - i);
            else break;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> id >> T;
    while (T--) solve();
    // cerr << fixed << setprecision(4) << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
