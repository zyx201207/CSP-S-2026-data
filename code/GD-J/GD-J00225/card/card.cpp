# include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const int N = 5e5 + 5, M = 3e5 + 5;
ll n, m, a[N], lst[N], nxt[N], d[M], w[M], indeg[M];
vector <int> col[M], G[M];
queue <int> q;

int main ()
{
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    ios :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);

    cin >> n >> m; for (int i = 1; i <= n; i++) { cin >> a[i]; lst[i] = d[a[i]]; nxt[d[a[i]]] = i; d[a[i]] = i; col[a[i]].push_back (i); } nxt[0] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (!nxt[i])
        {
            G[a[i]].push_back (a[i + 1]);
            indeg[a[i + 1]] ++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        w[i] = col[i].size ();
        if (!indeg[i])
        {
            q.push (i);
        }
    }

    while (!q.empty ())
    {
        int u = q.front ();
        q.pop ();
        for (int v : G[u])
        {
            w[v] += w[u];
            indeg[v] --;
            if (!indeg[v])
            {
                q.push (v);
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << w[i] << " ";
    }
    
    return 0;
}