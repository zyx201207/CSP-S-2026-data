#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define N 500005
#define M 500005
#define mod 998244353
using namespace std;
int n, k, dep[N], c, cho[N], uu[N], vv[N], dis[N], di[N], mi;
vector<int> G[N];
inline void dfs(int u, int fa)
{
    for (auto v : G[u])
    {
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
inline bool ok()
{
    int num = 0;
    fo(i, 1, n - 1)
    {
        int u = uu[i], v = vv[i];
        if (cho[u] && cho[v])
        {
            ++num;
        }
    }
    return k - num <= 2;
}
inline void dg(int s, int num)
{
    if (s == n + 1)
    {
        // fo(i, 1, n)
        // {
        //     if (!cho[i])
        //         continue;
        //     cout << cho[i];
        // }
        if (num != 0 || !ok())
            return;
        // cout << "OK\n";
        fo(i, 1, n) dis[i] = 1e18;
        fo(i, 1, n)
        {
            if (!cho[i])
                continue;
            fo(j, 1, n) di[j] = 1e18;
            di[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : G[u])
                {
                    if (di[v] > di[u] + 1)
                    {
                        di[v] = di[u] + 1;
                        q.push(v);
                    }
                }
            }
            fo(j, 1, n)
            {
                dis[j] = min(dis[j], di[j]);
            }
        }
        int mx = 0;
        fo(i, 1, n)
        {
            mx = max(mx, dis[i]);
        }
        mi = min(mi, mx);
        return;
    }
    if (n - s + 1 < num || num < 0)
        return;
    if (n - s + 1 == num)
    {
        cho[s] = 1;
        dg(s + 1, num - 1);
        return;
    }
    cho[s] = 0;
    dg(s + 1, num);
    cho[s] = 1;
    dg(s + 1, num - 1);
}
inline void solve()
{
    if (c == 7 || c == 11 || c == 12)
    {
        cin >> n >> k;
        fo(i, 1, n - 1)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        int mx = 0, id = 1;
        fo(i, 1, n)
        {
            if (dep[i] > mx)
            {
                mx = dep[i];
                id = i;
            }
        }
        fo(i, 1, n) dep[i] = 0;
        dep[id] = 1;
        dfs(id, 0);
        mx = 0;
        int id2 = 1;
        fo(i, 1, n)
        {
            if (dep[i] > mx)
            {
                mx = dep[i];
                id2 = i;
            }
        }
        cout << dep[id2] / 4 << '\n';
        fo(i, 1, n) vector<int>().swap(G[i]);
    }
    else
    {
        mi = 1e9;
        cin >> n >> k;
        fo(i, 1, n - 1)
        {
            int u, v;
            cin >> u >> v;
            uu[i] = u, vv[i] = v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dg(1, k);
        fo(i, 1, n) vector<int>().swap(G[i]);
        cout << mi << '\n';
    }
}
signed main()
{
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> c >> T;
    while (T--)
        solve();
}
/*
17:37 know how to do k<=2 start coding
17:43 wa k<=2
17:47 to do n,k<=10
17:58 n,k<=10 correct 15pts now :100+60+32+15=207pts
17:59 use Linux2.0 check
18:05 NOI LINUX correct
18:20 last check ok
*/