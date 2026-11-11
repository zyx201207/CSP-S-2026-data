# include <bits/stdc++.h>
# define int long long
using namespace std;

using ll = long long;

static const int N = 2e6 + 5;
static const ll INF = 1e18 + 5;
ll c, T, n, d, x[N], bfc[N];

vector <int> lj;
inline pair <int, int> dfs (int cur, int st, int ed)
{
    if (cur > ed)
    {
        lj.clear ();
        for (int i = st; i <= ed; i++)
        {
            if (bfc[i])
            {
                lj.push_back (i);
            }
        }
        if (lj.size () < 2)
        {
            return {1, 0};
        }
        if (lj.front () != st || lj.back () != ed)
        {
            return {1, 0};
        }
        for (int i = 1; i < (int) lj.size (); i++)
        {
            if (llabs (x[lj[i]] - x[lj[i - 1]]) > d)
            {
                return {1, 0};
            }
        }
        return {lj.size (), 1};
    }
    
    pair <int, int> lu, ru;
    bfc[cur] = 0; lu = dfs (cur + 1, st, ed);
    bfc[cur] = 1; ru = dfs (cur + 1, st, ed);
    if (lu.second == 0) { return ru; }
    if (ru.second == 0) { return lu; }
    if (lu.first == ru.first) { return {lu.first, lu.second + ru.second}; }
    else if (lu.first > ru.first) { return ru; }
    else { return lu; }
}

inline void solve1 ()
{
    ll ret = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            pair <int, int> w = dfs (i, i, j);
            if (w.second == 2) 
            { 
                ret ++; 
                // cout << w.first << " " << i << " " << j << "\n"; 
            }
            // cout << i << " " << j << " " << w << "\n";
        }
    }
    cout << ret << "\n";
}

static const int U2 = 5005;
pair <ll, ll> w[U2][U2];
ll f[U2][U2];

inline void solve2 ()
{
    ll ret = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            w[i][j] = {0, 0};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((llabs (x[i] - x[j]) <= d))
            {
                w[i][j] = {1, 1};
                continue ;
            }
            w[i][j] = {n + 1, 0};
            for (int k = i + 1; k < j; k++)
            {
                if ((llabs (x[k] - x[j]) > d)) continue ;
                // cout << i << " " << j << " " << k << " " << f[i][j].first << " " << f[i][j].second << " " << f[i][k].first << " " << f[i][k].second << "\n";
                if (w[i][k].first + 1 < w[i][j].first)
                {
                    w[i][j] = w[i][k];
                    w[i][j].first ++;
                }
                else if (w[i][k].first + 1 == w[i][j].first)
                {
                    w[i][j].second += w[i][k].second;
                }
            }
            ret += ((w[i][j].second == 2) ? 1 : 0);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         cout << f[i][j].first << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ret << "\n";
}

// namespace SGT
// {
//     ll tr[N << 2];
//     inline void pushup (int x) { tr[x] = min (tr[x << 1], tr[x << 1 | 1]); }
//     inline void clear (int sz) { for (int i = 0; i < (sz << 2); i++) { tr[i] = INF; } }
//     inline void update (int x, int l, int r, int ps, int v)
//     {
//         if (l == r) { tr[x] = min (tr[x], v); return ; }
//         int mid = (l + r) >> 1; 
//         if (ps <= mid) { update (x << 1, l, mid, ps, v); }
//         else update (x << 1 | 1, mid + 1, r, ps, v);
//         pushup (x);
//     }
//     inline int query (int x, int l, int r, int ql, int qr)
//     {
//         if (l > r || ql > qr || qr < l || ql > r) { return INF; }
//         if (ql <= l && r <= qr) { return tr[x]; }
//         int mid = (l + r) >> 1;
//         if (qr <= mid) { return query (x << 1, l, mid, ql, qr); }
//         if (ql > mid) { return query (x << 1 | 1, mid + 1, r, ql, qr); }
//         return min (query (x << 1, l, mid, ql, qr), query (x << 1 | 1, mid + 1, r, ql, qr));
//     }
// }

// using namespace SGT;

ll g[U2][U2];

inline void solve3 ()
{
    ll ret = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = 0;
            g[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // clear (n);
        f[i][i] = 0;
        g[i][i] = 1;
        // update (1, i, n, i, 0);
        for (int j = i + 1; j <= n; j++)
        {
            if (x[j] - x[j - 1] > d) { break ; }
            // cerr << j << " " << x[j] - d << " ";
            int l = upper_bound (x + i, x + j, x[j] - d - 1) - x;
            // cerr << l << "\n";
            // int w = query (1, i, n, l, j - 1);
            int r = j - 1, p = l, rt = l; 
            while (p <= r) 
            { 
                // cerr << p << " " << r << "\n"; 
                int mid = (p + r) >> 1;
                if (f[i][mid] > f[i][l]) { r = mid - 1; }
                else { rt = mid; p = mid + 1; }
            }
            f[i][j] = f[i][l] + 1;
            g[i][j] = g[i][j - 1] + g[i][rt] - g[i][l - 1];
            // cerr << i << " " << j << " " << l << " " << rt << f[i][j].first << " " << f[i][j].second << " " << g[i][j] << "\n";
            if (g[i][rt] - g[i][l - 1] == 2) { ret ++; }
            // cout << i << " " << j << " " << w << " " << p << " " << f[i][p].first << "\n";
            // cerr << i << " " << j << " " << w << " " << p << " " << l << " " << g[i][p - 1] << " " << g[i][l - 1] << "\n";
            // f[i][j] = {w + 1, g[i][p - 1] - g[i][l - 1]};
            // g[i][j] = g[i][j - 1] + f[i][j].second;
            // update (1, i, n, j, f[i][j].first);
            // cerr << f[i][j].first << " " << f[i][j].second << "\n";
            // if (f[i][j].second == 2) { ret ++; }
        }
    }
    cout << ret << "\n";
}

inline void solve (int tcc)
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) { cin >> x[i]; }
    if (tcc <= 2) { solve1 (); return ; }
    else if (tcc <= 6) { solve2 (); return ; }
    else if (tcc <= 10) { solve3 (); return ; }
}

signed main ()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    ios :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);

    cin >> c >> T;
    while (T--) { solve (c); }
    return 0;
}