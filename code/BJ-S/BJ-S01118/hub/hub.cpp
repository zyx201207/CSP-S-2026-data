#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 1e6;
const int N1 = 1e5;
const int N2 = 4e3;

int c;

int n, m;

vector < int > e[N + 5];

vector < int > tmp;

int ans;

int fa[N + 5], siz[N + 5];

bool flag[N + 5];

int find(int x)
{
    return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

queue < int > q;

bool vis[N + 5];

int dis[N + 5];

void dfs(int i, int now)
{
    if (now == 0)
    {
        for (int i = 1 ; i <= n ; i++) fa[i] = i, siz[i] = 1, vis[i] = false;
        int idk = m;
        for (int j : tmp)
        {
            for (int k : e[j])
            {
                if (flag[k])
                {
                    int a = find(j), b = find(k);
                    if (a != b)
                    {
                        idk--;
                        if (siz[a] < siz[b]) swap(a, b);
                        fa[b] = a;
                    }
                }
            }
        }
        if (idk > 2) return;
        for (int j : tmp) q.push(j), vis[j] = true, dis[j] = 0;
        int ANS = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : e[u])
            {
                if (vis[v]) continue;
                vis[v] = true;
                dis[v] = dis[u] + 1;
                ANS = max(ANS, dis[v]);
                q.push(v);
            }
        }
        ans = min(ans, ANS);
        return;
    }
    for (int j = i ; j <= n ; j++)
    {
        tmp.push_back(j);
        flag[j] = true;
        dfs(j + 1, now - 1);
        tmp.pop_back();
        flag[j] = false;
    }
    return;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) e[i].clear();
    for (int i = 1 ; i <= n - 1 ; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (m == n)
    {
        cout << "0\n";
        return;
    }
    if (13 <= c && c <= 14)
    {
        if (m >= n / 2)
        {
            cout << "1\n";
            return;
        }
        ans = ceil(1.0 * (n / 2 + 4 - m) / 4);
        cout << ans << '\n';
        return;
    }
    ans = n;
    dfs(1, m);
    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T;
    cin >> c >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
