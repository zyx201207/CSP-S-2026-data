#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u, dx;
    bool operator<(const node& otr) const {
        return dx < otr.dx;
    }
};

const int N = 505, M = 5e5+10;

int c, n, m, d, q;
int w[N], t[N][M], a[N][M], k[N], dis[3 * M];
vector<int> g[3 * M]; // 2* = grd, 1* = station, 0* = rod

void solve()
{
    memset(dis, 0x3f, sizeof(dis));
    int x, y;
    cin >> x >> y;
    priority_queue<node> q;
    dis[2 * M + x] = 0;
    q.push({2 * M + x, 0});
    while(!q.empty())
    {
        int u = q.top().u, dx = q.top().dx; q.pop();
        if(u > 2 * M)
        {//on grd
            if(dis[u] + w[u - 2 * M] < dis[u - M])
            {
                q.push({u - M, w[u - 2 * M]});
                dis[u - M] = dis[u] + w[u - 2 * M];
            }
        }
        else if(u > M)
        {//in station
            for(int v : g[u])
            {
                if(dis[u] + t[v][u - M] < dis[v])
                {
                    q.push({v, dis[u] + t[v][u - M]});
                    dis[v] = dis[u] + t[v][u - M];
                }
            }
            if(dis[u] + w[u - M] < dis[u + M])
            {
                q.push({u + M, dis[u] + w[u - M]});
                dis[u + M] = dis[u] + w[u - M];
            }
        }
        else
        {// in rd
            for(int v : g[u])
            {
                if(dis[u] + t[v - M][u] < dis[v])
                {
                    q.push({v, dis[u] + t[u][v - M]});
                    dis[v] = dis[u] + t[u][v - M];
                }
            }
        }
    }
    cout << dis[2 * M + y] << '\n';
}

int main() 
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            g[M + a[i][j]].push_back(i);
            g[i].push_back(M + a[i][j]); 
        }
    }
    while(q--) {solve();}
    return 0;
}