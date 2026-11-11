#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 510;
const int maxm = 5e5 + 10;
const int inf = 1e17;
int c,n,m,d,q,dis[maxn][maxn],w[maxm];
vector<pair<int,int>> vec[maxm];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    memset(dis,63,sizeof(dis));
    for(int i = 1;i <= n;i++)dis[i][i] = 0;
    for(int i = 1;i <= m;i++)cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        int k;cin >> k;
        for(int j = 1;j <= k;j++){int a,t;cin >> a >> t;vec[a].push_back({i,t});}
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < vec[i].size();j++)
        {
            for(int k = 0;k < j;k++)
            {
                int u = vec[i][j].first,w1 = vec[i][j].second;
                int v = vec[i][k].first,w2 = vec[i][k].second;
                dis[u][v] = dis[v][u] = min({dis[u][v],w1 + w2});
            }
        }
    }
    for(int k = 1;k <= n;k++)for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while(q--)
    {
        int u,v;cin >> u >> v;
        int ans = inf;
        for(int j = 0;j < vec[u].size();j++)
        {
            for(int k = 0;k < vec[v].size();k++)
            {
                int fir = vec[u][j].first,w1 = vec[u][j].second;
                int sec = vec[v][k].first,w2 = vec[v][k].second;
                ans = min(ans,dis[fir][sec] + w1 + w2);
            }
        }
        cout << ans + w[u] + w[v] << '\n';
    }
    return 0;
}

/*
！
先建模：对于每一条地铁线路都开一个新点，然后转化为新点和每一个在线路上的点连边
然后我们注意到我们只能对于新点跑 floyd，所以我们考虑先求出 d_{i,j} 表示只换乘一次时，第 i 条线路到第 j 条线路的最短时间。这个我们可以 $\mathrm O(\sum d_i^2)$ 求。
然后先跑一遍 floyd，求出任意两条线路在换乘的时候的最短时间。然后在询问的时候枚举第一次和最后一次坐的是什么线路即可。
时间复杂度 $\mathrm O(md^2+n^3+qd^2)$。
100

绿？
*/