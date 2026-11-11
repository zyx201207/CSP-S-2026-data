#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define N 1005
#define M 200005
#define mod 998244353
#define INF 1e18
using namespace std;
int c, n, m, d, q, w[M], f[N][N], k[N], a[505][50005], t[505][50005], dis[M];
vector<array<int, 2>> G[M];
inline void solve()
{
    cin >> c >> n >> m >> d >> q;
    fo(i, 1, m)
    {
        cin >> w[i];
    }
    if (c >= 12 && c <= 15)
    {
        fo(i, 1, n)
        {
            cin >> k[i];
            fo(j, 1, k[i])
            {
                cin >> a[i][j] >> t[i][j];
            }
            if (k[i] == 1)
                continue;
            fo(j, 2, k[i])
            {
                G[a[i][j]].push_back({a[i][1], i}), G[a[i][1]].push_back({a[i][j], i});
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int ll = min(l, r), rr = max(l, r);
            l = ll, r = rr;
            fo(i, 1, m)
            {
                dis[i] = INF;
            }
            dis[l] = 1;
            queue<array<int, 2>> q;
            q.push({l, -1});
            while (!q.empty())
            {
                auto [u, l] = q.front();
                q.pop();
                if (u == r)
                    break;
                for (auto [v, w] : G[u])
                {
                    if (l == -1 || w == l)
                    {
                        if (dis[v] > dis[u])
                        {
                            dis[v] = dis[u];
                            q.push({v, w});
                        }
                    }
                    else
                    {
                        if (dis[v] > dis[u] + 1)
                        {
                            dis[v] = dis[u] + 1;
                            q.push({v, w});
                        }
                    }
                }
            }
            // cout << t[1][1];
            // cout << dis[r];
            // cout << w[l];
            // cout << w[r];
            cout << 2 * t[1][1] * dis[r] + w[l] + w[r] << '\n';
        }
        return;
    }
    fo(i, 1, m)
    {
        fo(j, 1, m)
        {
            f[i][j] = INF;
        }
    }
    fo(i, 1, n)
    {
        cin >> k[i];
        fo(j, 1, k[i])
        {
            cin >> a[i][j] >> t[i][j];
        }
        fo(j, 1, k[i])
        {
            fo(l, j + 1, k[i])
            {
                int aa = min(a[i][j], a[i][l]), bb = max(a[i][j], a[i][l]);
                f[aa][bb] = min(f[aa][bb], t[i][j] + t[i][l]);
                // cout << aa << " " << bb << " " << t[i][j] << " " << t[i][l] << '\n';
            }
        }
    }
    fo(k, 1, m)
    {
        fo(i, 1, m)
        {
            if (f[i][k] == INF)
                continue;
            fo(j, i, m)
            {
                f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
            }
        }
    }
    // fo(i, 1, m)
    // {
    //     fo(j, 1, m)
    //     {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ll = min(l, r), rr = max(l, r);
        l = ll, r = rr;
        cout << f[l][r] + w[l] + w[r] << '\n';
    }
}
signed main()
{
    // int ti = clock();
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    // cerr << clock() - ti << "Ms\n";
}
/*
15:20 coding 44pts
15:35 44pts ok
16:10 check 44pts ok
16:13 coding 12-15 16pts
16:28 16pts ok  but checking
16:30 checking ok 60pts
16:30 0+60+32+0=92pts
跳 T1
18:17 NOI LINUX correct
18:20 last check ok
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

12-15
in:
12 2 5 20 2
4 1 9 2 5
3 1 5 2 5 4 5
3 2 5 3 5 5 5
1 3
1 2
ans:
33
15
*/