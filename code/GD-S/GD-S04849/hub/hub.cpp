#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main()
{
#ifndef QWQ
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
#endif
    cin.tie(0)->sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10);

    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        vector<array<int, 2>> ed;
        for (int i = 1, u, v; i < n; ++i)
        {
            cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
            ed.push_back({u, v});
        }
        if (k == n)
        {
            cout << 0 << '\n';
            continue;
        }
        if (n <= 100)
        {
            auto solve = [&](int rt, int ban)
            {
                // cerr << rt << ' ' << ban << ' ';
                int p = rt, q = rt;
                vector<int> dis(n + 1), fat(n + 1);
                auto dfs = [&](auto &&dfs, int u, int ft, int &mst) -> void
                {
                    fat[u] = ft;
                    if (dis[mst] < dis[u])
                    {
                        mst = u;
                    }
                    for (int v : g[u])
                    {
                        if (v != ft && v != ban)
                        {
                            dis[v] = dis[u] + 1;
                            dfs(dfs, v, u, mst);
                        }
                    }
                };
                dis[1] = 0, dfs(dfs, rt, 0, p);
                dis[p] = 0, dfs(dfs, p, 0, q);
                int len = dis[q] / 2;
                rt = q;
                while (len--)
                {
                    rt = fat[rt];
                }
                // cerr << "==========\n";
                // cerr << rt << ' ' << p << ' ' << q << '\n';
                vector<int> res(k), hig(n + 1), son(n + 1);
                auto G = g;
                auto calc = [&](auto &&calc, int u, int ft) -> void
                {
                    hig[u] = 0, son[u] = 0;
                    for (int v : G[u])
                    {
                        if (v != ft && v != ban)
                        {
                            calc(calc, v, u);
                            if (hig[v] + 1 > hig[u])
                            {
                                hig[u] = hig[v] + 1;
                                son[u] = v;
                            }
                        }
                    }
                };
                for (int i = 1; i < k; ++i)
                {
                    calc(calc, rt, 0);
                    res[i] = hig[rt];
                    if (!res[i])
                    {
                        break;
                    }
                    assert(son[rt]);
                    G[rt].erase(find(G[rt].begin(), G[rt].end(), son[rt]));
                    for (int v : G[son[rt]])
                    {
                        if (v != ban && v != rt)
                        {
                            G[rt].push_back(v);
                            G[v].erase(find(G[v].begin(), G[v].end(), son[rt]));
                            G[v].push_back(rt);
                        }
                    }
                }
                return res;
            };
            int ans = n;
            for (auto [U, V] : ed)
            {
                auto resu = solve(U, V);
                auto resv = solve(V, U);
                for (int i = 1; i < k; ++i)
                {
                    ans = min(ans, max(resu[i], resv[k - i]));
                }
            }
            cout << ans << '\n';
            continue;
        }
        if (k == 2)
        {
            int p = 1, q = 1;
            vector<int> dis(n + 1), fat(n + 1);
            auto dfs = [&](auto &&dfs, int u, int ft, int &mst) -> void
            {
                fat[u] = ft;
                if (dis[mst] < dis[u])
                {
                    mst = u;
                }
                for (int v : g[u])
                {
                    if (v != ft)
                    {
                        dis[v] = dis[u] + 1;
                        dfs(dfs, v, u, mst);
                    }
                }
            };
            dis[1] = 0, dfs(dfs, 1, 0, p);
            dis[p] = 0, dfs(dfs, p, 0, q);
            int len = dis[q];
            vector<int> a, dep;
            for (int x = q; x; x = fat[x])
            {
                if (x)
                {
                    a.push_back(x);
                    dep.push_back(0);
                }
            }
            for (int i = 1; i < len; ++i)
            {
                auto dfs = [&](auto &&dfs, int u, int ft, int d) -> void
                {
                    dep[i] = max(dep[i], d);
                    for (int v : g[u])
                    {
                        if (v != ft)
                        {
                            dfs(dfs, v, u, d + 1);
                        }
                    }
                };
                for (int v : g[a[i]])
                {
                    if (v != a[i - 1] && v != a[i + 1])
                    {
                        dfs(dfs, v, a[i], 1);
                    }
                }
            }
            vector<int> pre(len + 1), suf(len + 1);
            for (int i = 1; i < len; ++i)
            {
                pre[i] = max(pre[i - 1], dep[i] + i);
            }
            for (int i = len - 1; i; --i)
            {
                suf[i] = max(suf[i + 1], dep[i] + len - i);
            }
            int ans = len;
            for (int i = 0; i < len; ++i)
            {
                ans = min(ans, max(max(i, pre[i]), max(len - i - 1, suf[i + 1])));
            }
            cout << (ans + 1) / 2 << '\n';
            continue;
        }
    }

    return 0;
}
/*
别急！！
17:20 考虑断边两边分开做，然后是什么 nkT(n) 的
17:25 先打 k=2 吧
17:43 k=2 OK
18:11 OK nk???
*/