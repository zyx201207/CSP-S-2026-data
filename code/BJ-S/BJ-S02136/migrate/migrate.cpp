# include <bits/stdc++.h>
# define int long long
const int N = 2e6 + 5;
const int inf = 1e18;
using namespace std;
int a[N], nxt[N];
int n, d;
vector <int> e[N];

struct node
{
    int id, val;
};

inline bool operator < (node x, node y)
{
    return x.val > y.val;
}

priority_queue <node> q;
int dis[N];
int cnt[N];
bool vis[N];


int dij(int s)
{
    for(int i = 1; i <= n; i++) dis[i] = inf, cnt[i] = 0, vis[i] = 0;
    cnt[s] = 1;
    dis[s] = 0;
    q.push({s, dis[s]});
    while(!q.empty())
    {
        node x = q.top();
        int u = x.id;
        //cout << u << endl;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            if(dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                cnt[v] = 0;
                q.push({v, dis[v]});
            }
            if(dis[v] == dis[u] + 1) cnt[v] += cnt[u];
        }
    }
    int t = 0;
    for(int i = s + 1; i <= n; i++)
        if(cnt[i] == 2) t++;
    return t;
}

void solve()
{

    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i++)
    {
        while(j < n && a[j + 1] - a[i] <= d) j++;
        nxt[i] = j;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= nxt[i]; j++)
        {
            e[i].push_back(j);
            e[j].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++) ans += dij(i);
    cout << ans << "\n";
    for(int i = 1; i <= n; i++)
    {
        e[i].clear();
    }
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    int c, T;
    cin >> c >> T;
    //T = 1;
    while(T--) solve();
    return 0;
}
