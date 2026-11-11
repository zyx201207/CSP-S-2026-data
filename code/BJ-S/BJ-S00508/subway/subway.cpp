#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair <int, int> pii;

const int N = 510;
const int M = 2e4 + 10;
const int NM = 3e4 + 10;

int c, n, m, d, q;
int sub[M];
vector <pii> edge[2 * NM];
int dis[NM];

int Dijkstra(int s, int t)
{
    priority_queue <pii, vector <pii>, greater <pii> > que;

    for(int i = 0; i <= n + m; i++)
    {
        dis[i] = 0x3f3f3f3f;
    }

    que.push({0, s});

    dis[s] = 0;

    while(!que.empty())
    {
        pii head = que.top();

        que.pop();

        for(pii to : edge[head.second])
        {
            if(dis[to.first] > head.first + to.second)
            {
                dis[to.first] = head.first + to.second;

                que.push({dis[to.first], to.first});
            }
        }
    }

    return dis[t];
}

signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1; i <= m; i++)
    {
        cin >> sub[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int k;

        cin >> k;

        for(int j = 1; j <= k; j++)
        {
            int v, w;

            cin >> v >> w;

            edge[i].push_back({v + n, w});
            edge[v + n].push_back({i, w});
        }
    }

    while(q--)
    {
        int x, y;

        cin >> x >> y;

        int res = sub[x] + sub[y];

        res += Dijkstra(x + n, y + n);

        cout << res << '\n';
    }

    return 0;
}