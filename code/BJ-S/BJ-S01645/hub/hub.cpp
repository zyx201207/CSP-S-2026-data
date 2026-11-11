#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
typedef long long ll;
const int N = 1e6 + 10;
vector<int> g[N];
int f[N], siz[N], n;
il void dfs(int u, int fa)
{
    f[u] = fa;
    siz[u] = 1;
    for(auto v : g[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
il int getheavy(int u, int fa)
{
    int mx = 0, ans = 0;
    for(auto v : g[u])
    {
        if(v == fa) continue;
        ans = max(ans, getheavy(v, u));
        mx = max(mx, siz[v]);
    }
    mx = max(mx, n - siz[u]);
    if(2 * mx <= n) return u;
    return ans;
}
int fa[N];
il int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int dep[N];
queue<int> q;
il void bfs(int s)
{
    for(int i = 1;i <= n;++i) dep[i] = -1;
    dep[s] = 0;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(dep[v] != -1) continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}
int dist[N];
int qwq[3010][3010];
il bool chk(int mid)
{
    vector<int> awa;
    for(int i = 1;i <= n;++i)
        if(dist[i] > mid) awa.pb(i);
    for(int i = 1;i <= n;++i)
    {
        int mx = 0;
        for(auto j : awa)
        {
            mx = max(mx, qwq[i][j]);
            if(mx > mid) break;
        }
        if(mx <= mid) return true;
    }
    return false;
}
il void solvebl()
{
    int k;
    cin >> n >> k;
    for(int i = 1;i < n;++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    int ans = n;
    if(k == 1)
    {
        dfs(1, 0);
        int u = getheavy(1, 0);
        bfs(u);
        int mx = 0;
        for(int i = 1;i <= n;++i) mx = max(mx, dep[i]);
        ans = mx;
    }
    else if(k == 2)
    {
        for(int i = 1;i <= n;++i)
        {
            bfs(i);
            for(int j = 1;j <= n;++j) qwq[i][j] = dep[j];
        }
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= n;++j) dist[j] = qwq[i][j];
            int l = 0, r = n;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(chk(mid)) r = mid;
                else l = mid + 1;
            }
            if(chk(l)) ans = min(ans, l);
        }
    }
    else
    {
        dfs(1, 0);
        for(int S = 0;S < (1 << n);++S)
        {
            map<int, int> mp;
            for(int i = 0;i < n;++i)
                if((S >> i) & 1) mp[i + 1] = 1;
            if(mp.size() != k) continue;
            for(int i = 1;i <= n;++i) fa[i] = i;
            for(auto ii : mp)
            {
                int i = ii.first;
                if(mp.count(f[i])) fa[find(i)] = find(f[i]);
            }
            int cnt = 0;
            for(int i = 1;i <= n;++i)
                if(mp.count(i)) cnt += (fa[i] == i);
            if(cnt > 2) continue;
            for(int i = 1;i <= n;++i) dist[i] = (mp.count(i) ? 0 : 1e9);
            for(auto ii : mp)
            {
                int i = ii.first;
                bfs(i);
                for(int j = 1;j <= n;++j) dist[j] = min(dist[j], dep[j]);
            }
            int mx = 0;
            for(int i = 1;i <= n;++i) mx = max(mx, dist[i]);
            ans = min(ans, mx);
        }
    }
    cout << ans << "\n";
    for(int i = 1;i <= n;++i) g[i].clear();
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w",  stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--) solvebl();
    return 0;
}
