#include <bits/stdc++.h>

using namespace std;

const int N = 525, M = 100000005, INF = 1e9;
struct node
{
    int v, t;
};
vector<node> g[N];
long long w[M], dis[M];
bool vis[M];
long long m, n;
void SPFA(int s)
{
    for(int i = 0; i <= m + n; i++)
    {
        dis[i] = INF;
        vis[i] = false;
    }

    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(!vis[u])
            continue;
        vis[u] = false;

        for(node i : g[u])
        {
            int v = i.v, t = i.t;
            if(v == u)
                continue;
            if(dis[u] + t < dis[v])
            {
                dis[v] = dis[u] + t;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];

    int cnt = m + 1;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            g[cnt].push_back({a, t});
            g[a].push_back({cnt, t});
        }
        cnt++;
    }

    while(q--)
    {
        int s, t;
        cin >> s >> t;
        SPFA(s);
        cout << dis[t] + w[s] + w[t] << '\n';
    }

    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
