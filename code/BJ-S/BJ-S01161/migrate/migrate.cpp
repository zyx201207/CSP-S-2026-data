#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
const int N = 300 + 5;
const int inf = 3e18 + 7;
int n, d, a[N], cnt[N][N], dis[N][N];
bool vis[N];
vector<int> e[N];
void dijkstra(int s, int dis[N], int cnt[N])
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
        cnt[i] = 1;
    }
    dis[s] = 0;
    cnt[s] = 1;
    while(1)
    {
        int minn = inf, u = -1;
        for(int i = 1; i <= n; i++)
        {
            if(dis[i] < minn && !vis[i])
            {
                minn = dis[i];
                u = i;
            }
        }
        if(u == -1) break;
        vis[u] = 1;
        for(auto v : e[u])
        {
            if(dis[u] + 1 == dis[v])    cnt[v] += cnt[u];
            else if(dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
            }
        }
    }
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _, t;
    cin >> _ >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i], e[i].clear();
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(a[j] - a[i] > d) continue;
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
        for(int i = 1; i <= n; i++)
            dijkstra(i, dis[i], cnt[i]);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(cnt[i][j] == 2)  ans++;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
