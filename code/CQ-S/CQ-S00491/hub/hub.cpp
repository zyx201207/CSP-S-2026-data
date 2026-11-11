#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 2e5 + 10; /// change the range
int n, k;
bool vis[15];
int d[15];
vector <int> v[15];
void dfs(int u)
{
    vis[u] = true;
    for (int j : v[u])
        if (!vis[j]) dfs (j);
}
int bfs(int x)
{
    queue <int> q;
    for (int i = 0; i < n; i++)
        if ((x >> i) & 1) q.push (i + 1), d[i + 1] = 0;
    int res = 0;
    while (q.size ())
    {
        int u = q.front (); q.pop ();
        res = max (res, d[u]);
        for (int j : v[u])
            if (d[j] == -1)
                d[j] = d[u] + 1, q.push (j);
    }
    return res;
}
signed main()
{
    freopen ("hub.in", "r", stdin); ///write the name
    freopen ("hub.out", "w", stdout); ///write the name
    int c, t; scanf ("%d %d", &c, &t);
    while (t--)
    {
        scanf ("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) v[i].clear ();
        for (int i = 1; i < n; i++)
        {
            int x, y; scanf ("%d %d", &x, &y);
            v[x].push_back (y);
            v[y].push_back (x);
        }
        int ans = 2e9;
        for (int i = 1; i < (1 << n); i++)
        {
            for (int j = 1; j <= n; j++) vis[j] = false, d[j] = -1;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (!((i >> j) & 1)) continue;
                if (!vis[j + 1]) dfs (j + 1), cnt++;
            }
            if (cnt > 2) continue;
            ans = min (ans, bfs (i));
        }
        cout << ans << "\n";
    }
    return 0;
}