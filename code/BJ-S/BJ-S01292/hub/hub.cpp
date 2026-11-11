#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
vector<int> g[N];
int res = 1e9;
int n, k;
bool st[N];
vector<int> a;
int fa[N][20];
int dep[N];
bool check()
{
    vector<int> st(n+1, 0);
    vector<int> st1(n+1, 0);
    for(int i = 0; i < k; i++) st1[a[i]] = 1;
    int res1 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(st1[i] == 1 && st[i] == 0)
        {
            res1++;
            queue<int> q;
            q.push(i);
            while(q.size())
            {
                int u = q.front();
                q.pop();
                st[u] = 1;
                for(int i = 0; i < g[u].size(); i++)
                {
                    int k = g[u][i];
                    if(st1[k] == 1 && st[k] == 0) q.push(k);
                }
            }
        }
    }
    if(res1 <= 2) return 1;
    else return 0;
}
int lca_dep(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 15; i >= 0; i--)
    {
        if(dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
    }
    if(x == y) return dep[x];
    for(int i = 15; i >= 0; i--)
    {
        if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return dep[x] - 1;
}
void dfs(int u)
{
    if(u == k+1)
    {
        int res1 = 0;
        if(!check()) return;
        for(int i = 1; i <= n; i++)
        {
            if(st[i]) continue;
            int res2 = 1e9;
            for(int j = 0; j < k; j++)
            {
                int dep_lca = lca_dep(i, a[j]);
                //cout << i << ' ' << a[j] << ' ' << dep_lca << ' ';
                int q = dep[i] - dep_lca + dep[a[j]] - dep_lca;
                //cout << q << endl;
                res2 = min(res2, q);
            }
            res1 = max(res1, res2);
        }
        //cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        res = min(res, res1);
        //cout << res << endl;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i]) continue;
            a.push_back(i);
            st[i] = 1;
            dfs(u+1);
            a.pop_back();
            st[i] = 0;
        }
    }
}
void init_fa()
{
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            int k = g[u][i];
            if(dep[k] != 0) continue;
            dep[k] = dep[u] + 1;
            q.push(k);
            fa[k][0] = u;
            for(int i = 1; i <= 15; i++)
            {
                fa[k][i] = fa[fa[k][i-1]][i-1];
            }
        }
    }
}
void solve()
{
    memset(st, 0, sizeof st);
    memset(fa, 0, sizeof fa);
    memset(dep, 0, sizeof dep);
    res = 1e9;
    scanf("%lld %lld", &n, &k);
    //cout << n << ' ' << k << endl;
    for(int i = 1; i < n; i++)
    {
        int x, y; scanf("%lld %lld", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    init_fa();
    dfs(1);
    cout << res << endl;
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%lld %lld", &c, &t);
    while(t--) solve();
    return 0;
}
