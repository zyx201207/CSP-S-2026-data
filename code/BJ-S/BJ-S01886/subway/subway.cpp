#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
int n, c, m, d, q;
long long ans, dis[M];
int w[M], k[N], a[N][M], t[N][M], x[M], y[M];
bool b[M], b2[M];
vector<int> v[M], v2[M], v3[M];

struct Node{
    int dis, id;
    bool operator <(const Node&x) const{
        return x.dis < dis;
    }
};

int dj(int s)
{
    priority_queue<Node> q;
    q.push({0, s});
    b[s] = true;
    for(int i = 1; i <= m; i++)
    {
        dis[i] = 1e18;
    }
    dis[s] = 0;
    while(!q.empty())
    {
        int a = q.top().id;
        if(b[a]) continue;
        b[a] = true;
        for(int i = 0; i < v3[a].size(); i++)
        {
            int tmp = v3[a][i];
            if(dis[tmp] > dis[a] + 2 * t[1][1])
            {
                dis[tmp] = dis[a] + 2 * t[1][1];
                if(b[tmp]) q.push({dis[tmp], tmp});
            }
        }
    }
}

void solve(int u, int v)
{
    for(int i = 1; i <= m; i++)
    {
        if(v2[i].size() > 1) b[i] = true;
        for(int j = 1; j <= v2[i].size(); j++)
        {
            for(int k = 1; k <= v[v2[i][j]].size(); k++)
            {
                if(b[v[v2[i][j][k]])
                {
                    v3[i].push_back(v[v2[i][j][k]]);
                    v3[v[v2[i][j][k]].push_back(i);
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            v[i].push_back(a[i][j]);
            v2[a[i][j]].push_back(i);
        }
    }
    solve();
    for(int i = 1; i <= q; i++)
    {
        cin >> x[i] >> y[i];
        dj(x[i]);
        ans = w[x[i] + dis[y[i]]] + 2 * t[1][1];
        cout << ans << "\n";
    }
    return 0;
}
