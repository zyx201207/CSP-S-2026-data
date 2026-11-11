#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define m_p make_pair
#define fi first
#define se second
#define pcnt __builtin_popcountll
using namespace std;
const int inf = (sizeof(int) == 4 ? 0x3f3f3f3f : 0x3f3f3f3f3f3f3f3f);
const int N = 1e6 + 10;
vi v[N];
int f[N], g[N];
void dfs1(int x, int fa)
{
    f[x] = g[x] = 0;
    for (auto i : v[x])
    {
        if (i == fa) continue;
        dfs1(i, x);
        if (f[i] + 1 > f[x]) g[x] = f[x], f[x] = f[i] + 1;
        else if (f[i] + 1 > g[x]) g[x] = f[i] + 1;
    }
}
void dfs2(int x, int fa)
{
    for (auto i : v[x])
    {
        if (i == fa) continue;
        int val = (f[i] + 1 == f[x] ? g[x] : f[x]);
        if (val + 1 > f[i]) g[i] = f[i], f[i] = val + 1;
        else if (val + 1 > g[i]) g[i] = val + 1;
        dfs2(i, x);
    }
}
int t, cnt, mn, md, dep[N];
bool ok[N];
void dfs3(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    ok[x] |= (g[x] >= t);
    for (auto i : v[x]) if (i != fa && f[i] == t - 1) ok[x] = true;
    for (auto i : v[x])
    {
        if (i == fa) continue;
        if (f[i] >= t) ok[i] |= ok[x];
        if (!ok[x] && f[i] < t) md = min(md, dep[x] + t - f[i] - 1);
        dfs3(i, x);
    }
    if (ok[x]) cnt++, mn = min(mn, dep[x]);
}
int c[N], d[N];
void dfs4(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    bool ok = (g[x] >= t);
    for (auto i : v[x]) if (i != fa && f[i] == t - 1) ok = true;
    c[x] = ok, d[x] = (ok ? dep[x] : inf);
    for (auto i : v[x])
    {
        if (i == fa) continue;
        dfs4(i, x);
        c[x] += c[i], d[x] = min(d[x], d[i]);
        if (ok && c[i] > 0) c[x] += d[i] - dep[i];
    }
}
int rt, siz[N];
void dfs5(int x, int fa)
{
    siz[x] = (f[x] >= t);
    for (auto i : v[x])
    {
        if (i == fa) continue;
        dfs5(i, x);
        siz[x] += siz[i];
    }
    if (x != rt)
    {
        int val = c[x];
        if (val > 0) val += max(0ll, d[x] - dep[x] - 2 * t);
        mn = min(mn, val - siz[x]);
    }
}
int n, k;
bool check()
{
    for (int i = 1; i <= n; i++) ok[i] = false;
    int d = (v[rt].size() == 2 ? t : t - f[v[rt][2]] - 1);
    if (d > 0)
    {
        dep[rt] = 0;
        int s = 0, x[2], y[2];
        cnt = 0, mn = inf, md = t + 1;
        dfs3(v[rt][0], rt);
        s += cnt;
        x[0] = max(0ll, mn - md);
        x[1] = max(x[0], max(0ll, mn - d));
        cnt = 0, mn = inf, md = t + 1;
        dfs3(v[rt][1], rt);
        s += cnt;
        y[0] = max(0ll, mn - md);
        y[1] = max(y[0], max(0ll, mn - d));
        s += min(x[0] + y[1], x[1] + y[0]);
        if (s <= k) return true;
    }
    dfs4(rt, 0);
    mn = 0;
    dfs5(rt, 0);
    return siz[rt] + mn <= k;
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int id, T;
    cin >> id >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].pb(y), v[y].pb(x);
        }
        if (n == k)
        {
            cout << 0 << '\n';
            continue;
        }
        dfs1(1, 0);
        dfs2(1, 0);
        rt = 1;
        for (int i = 2; i <= n; i++) if (f[i] < f[rt]) rt = i;
        dfs1(rt, 0);
        sort(v[rt].begin(), v[rt].end(), [&](int x, int y){ return f[x] > f[y]; });
        int l = 1, r = f[rt], ans;
        while (l <= r)
        {
            t = l + r >> 1;
            if (check()) ans = t, r = t - 1;
            else l = t + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}