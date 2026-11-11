#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define ll long long
#define pb push_back
const int N = 1e6 + 5;
int cid, T, n, k, d, vis[N];
struct info 
{
    int w, tp, x, y;
    void clear() {w = 1e9; x = y = tp = 0;}
} f[N][3], h[3];
info mrg(info u, info v)
{
    if (u.tp > v.tp) swap(u, v);
    int x = u.x ? u.x : v.x;
    int y = u.y ? u.y : (x == v.x ? v.y : v.x);
    if (!u.tp && !v.tp) return {max(u.w, v.w), 0, x, y};
    if (!u.tp && u.w + v.w > d) return {u.w, 0, x, y};
    if (!u.tp) return {v.w, 1, x, y};
    return {min(u.w, v.w), 1, x, y};
}
info ch(info u, info v)
{
    if (u.tp > v.tp) swap(u, v);
    if (!u.tp && v.tp) return v;
    if (u.w < v.w) return u;
    return v;
}
vector <int> g[N];
void dp(int u, int fa)
{
    f[u][0].w = f[u][1].w = 0; f[u][1].tp = 1; f[u][1].x = u;
    for (int v : g[u]) if (v != fa)
    {
        dp(v, u);
        h[0].clear(); h[1].clear(); h[2].clear();
        f[v][0].w++; f[v][1].w++; f[v][2].w++;
        for (int i = 0; i < 3; i++) for (int j = 0; i + j < 3; j++)
            h[i+j] = ch(h[i+j], mrg(f[u][i], f[v][j]));
        for (int i = 0; i < 3; i++) f[u][i] = h[i];
    }
}
int q[N], p; int to[N], c[N];
int main()
{
    FILE("hub");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> cid >> T;
    while (T--)
    {
        for (int i = 1; i <= n; i++) g[i].clear(), to[i] = vis[i] = 0;
        cin >> n >> k;
        for (int i = 1, u, v; i < n; i++) cin >> u >> v, g[u].pb(v), g[v].pb(u);
        if (cid <= 6)
        {
            int mn = n;
            for (int u = 1; u <= n; u++) for (int v = u + 1; v <= n; v++)
            {
                for (int i = 1; i <= n; i++) to[i] = vis[i] = 0;
                p = 0; q[++p] = u; q[++p] = v; vis[u] = vis[v] = 1;
                for (int i = 1; i <= n; i++)
                {
                    int a = q[i]; c[i] = 1;
                    for (int b : g[a]) if (!vis[b]) vis[b] = 1, to[b] = a, q[++p] = b;
                }
                for (int i = n; i >= 1; i--) c[to[q[i]]] = max(c[to[q[i]]], c[q[i]] + 1);
                int l = 1, r = n, ans = n;
                while (l <= r)
                {
                    int mid = l + r >> 1, s = 0;
                    for (int i = 1; i <= n; i++) if (c[i] >= mid) s++;
                    if (s <= k) ans = mid - 1, r = mid - 1;
                    else l = mid + 1;
                }
                mn = min(mn, ans);
            }
            cout << mn << "\n";
        }
        else
        {
            int l = 0, r = n, ans = n;
            while (l <= r)
            {
                for (int i = 1; i <= n; i++) f[i][0].clear(), f[i][1].clear(), f[i][2].clear();
                d = l + r >> 1; dp(1, 0);
                if (f[1][2].tp) ans = d, r = d - 1;
                else l = d + 1;
            }
            d = ans; dp(1, 0);
            int u = f[1][2].x, v = f[1][2].y;
            for (int i = 1; i <= n; i++) to[i] = vis[i] = 0;
            p = 0; q[++p] = u; q[++p] = v; vis[u] = vis[v] = 1;
            for (int i = 1; i <= n; i++)
            {
                int a = q[i]; c[i] = 1;
                for (int b : g[a]) if (!vis[b]) vis[b] = 1, to[b] = a, q[++p] = b;
            }
            for (int i = n; i >= 1; i--) c[to[q[i]]] = max(c[to[q[i]]], c[q[i]] + 1);
            l = 1, r = n, ans = n;
            while (l <= r)
            {
                int mid = l + r >> 1, s = 0;
                for (int i = 1; i <= n; i++) if (c[i] >= mid) s++;
                if (s <= k) ans = mid - 1, r = mid - 1;
                else l = mid + 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
