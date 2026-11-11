#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace usr
{
    const ll N = 1e6 + 5;
    vector<ll> g[N];
    bool vis[N];
    ll q[N], head, tail;
    // ll dep[N], eur[N << 1], st[25][N << 1], lg2[N << 1], fir[N], tot;
    ll dep[N], fa[N][25];
    ll n, k, r;
    void rootff()
    {
        head = 1, tail = 0;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            if (g[i].size() == 1) {q[++tail] = i,vis[i] = 1;}
        }
        while (head <= tail)
        {
            ll u = q[head];
            r = u;
            head++;
            for (auto &v : g[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q[++tail] = v;
                }
            }
        }
    }
    void dfs(ll u, ll f)
    {
        fa[u][0] = f;
        dep[u] = dep[f] + 1;
        for (auto &v : g[u])
        {
            if (v != f)
            {
                dfs(v, u);
            }
        }
    }
    // ll comp(ll x, ll y)
    // {
    //     if (!x) return y;
    //     if (!y) return x;
    //     return dep[x] < dep[y] ? x : y;
    // }
    // ll find(ll l, ll r)
    // {
    //     ll len = r - l + 1, g = lg2[len];
    //     return comp(st[g][l], st[g][r - (1ll << g) + 1]);
    // }
    // ll lca(ll x, ll y)
    // {
    //     if (fir[x] > fir[y]) swap(x, y);
    //     return find(fir[x], fir[y]);
    // }
    ll lca(ll x, ll y)
    {
        if (!x) return y;
        if (!y) return x;
        if (dep[x] < dep[y]) swap(x, y);
        for (int k = 23; k >= 0; k--) if (dep[fa[x][k]] >= dep[y]) x = fa[x][k];
        if (x == y) return x;
        for (int k = 23; k >= 0; k--) if (fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
        return fa[x][0];
    }
    ll jump(ll x, ll p)
    {
        for (int k = 23; k >= 0; k--)
        {
            if ((p >> k) & 1) x = fa[x][k]; 
        }
        if (!x) x = r;
        return x;
    }
    bool check(ll x)
    {
        ll lst = 0, i;
        ll sum = 0, maxx = 0, tmxx = -1e18;
        for (i = 1; i <= n; i++)
        {
            if (g[i].size() == 1)
            {
                lst = jump(i, x);
                break ;
                // cout << lst << "-";
            }
        }
        for (i++; i <= n; i++)
        {
            if (g[i].size() == 1)
            {
                ll u = jump(i, x);
                ll l = lca(lst, u);
                sum += dep[lst] + dep[u] - dep[l] - dep[l];
                if (dep[lst] - dep[l] <= x + x) maxx = max(maxx, dep[lst] - dep[l] - 1);
                if (dep[u] - dep[l] <= x + x) maxx = max(maxx, dep[u] - dep[l] - 1);
                if (dep[lst] + dep[u] - dep[l] - dep[l] <= x + x) tmxx = dep[lst] + dep[u] - dep[l] - dep[l] - 1;
                // cout << lst << '-' << u << "^-" << l << ' ' << dep[lst] + dep[u] - dep[l] - dep[l] << '\n';
                lst = l;
            }
        }
        sum++;
        // cout << sum << ' ' << maxx << ' ' << tmxx << '\n';
        maxx = max(maxx, tmxx);
        return sum - maxx <= k;
    }
    ll ef()
    {
        ll l = 0, r = n, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    void solve(ll cas)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        rootff();
        // cout << r << ' ';
        dfs(r, 0);
        for (int k = 1; k <= 23; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                fa[i][k] = fa[fa[i][k - 1]][k - 1];
            }
        }
        cout << ef() << '\n';
        // cout << check(0) << '\n';
    }
    void main()
    {
        freopen("hub.in", "r", stdin);
        freopen("hub.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        // -Wall -Wextra -fsanitize=address,undefined
        ll T = 1, cas = 0;
        cin >> cas;
        cin >> T;
        while (T--) solve(cas);
    }
};
int main()
{
    usr::main();
    return 0;
}