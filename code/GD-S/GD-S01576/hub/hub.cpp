
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 2000006

int Tid;

int n, k;

vector<int> e[MAXN];

struct Item
{
    int t, d, k;
};

inline ostream &operator<<(ostream &out, const Item &v)
{
    return out << '[' << v.t << ' ' << v.d << ' ' << v.k << ']';
}

inline Item append(Item a, int d)
{
    if (a.t == 1)
    {
        if (a.d == d - 1)
        {
            return {2, 0, 1};
        }
        return {1, a.d + 1, 0};
    }
    else
    {
        if (a.d == d)
        {
            return {2, d, a.k + 1};
        }
        return {2, a.d + 1, a.k};
    }
}

inline Item merge(Item a, Item b, int d)
{
    if (a.t < b.t)
    {
        swap(a, b);
    }
    if (a.t == 1)
    {
        return {1, max(a.d, b.d), 0};
    }
    if (b.t == 1)
    {
        int nd = d - b.d;
        if (a.d <= nd)
        {
            return {2, a.d, a.k};
        }
        return {2, nd, a.k + (a.d - nd)};
    }
    return {2, 0, a.k + b.k + a.d + b.d - 1};
}

Item f[MAXN], g[MAXN], pf[MAXN], sf[MAXN];

void dfs1(int p, int fa, int d)
{
    f[p] = {1, 0, 0};
    for (int u : e[p])
    {
        if (u == fa)
        {
            continue;
        }
        dfs1(u, p, d);
        f[p] = merge(f[p], append(f[u], d), d);
    }
}

void dfs2(int p, int fa, int d)
{
    Item cur = p == fa ? Item{1, 0, 0} : append(g[p], d);
    for (int u : e[p])
    {
        if (u == fa)
        {
            continue;
        }
        pf[u] = cur;
        cur = merge(cur, append(f[u], d), d);
    }
    cur = Item{1, 0, 0};
    for (size_t i = e[p].size(); i--; )
    {
        int u = e[p][i];
        if (u == fa)
        {
            continue;
        }
        sf[u] = cur;
        cur = merge(cur, append(f[u], d), d);
    }
    for (int u : e[p])
    {
        if (u == fa)
        {
            continue;
        }
        // clog << "mer " << u << ' ' << pf[u] << ' ' << sf[u] << endl;
        g[u] = merge(pf[u], sf[u], d);
        dfs2(u, p, d);
    }
}

bool chk(int d)
{
    dfs1(1, 1, d);
    g[1] = {1, 0, 0};
    dfs2(1, 1, d);
    for (int i = 2; i <= n; i++)
    {
        // clog << i << ' ' << f[i] << ' ' << g[i] << endl;
        if (max(f[i].k, 1) + max(g[i].k, 1) <= k) // 2 <= k <= n
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (k == n)
    {
        cout << "0\n";
        return;
    }

    // chk(1);
    // return;

    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (chk(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> Tid >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
