#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 5e5 + 5;

struct node
{
    int to, cost;
};

struct edge
{
    int to, cost, sub;
    bool operator < (const edge &nxt) const
    {
        return cost > nxt.cost;
    }
};

int c, n, m, d, q, W[M], K[N], st, ed;
vector<vector<node> > subway(M);
vector<vector<node> > stat(N);
priority_queue<edge> que;
int floyd[N][N];
bool vis_sub[M];
int sum[N];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;++ i)
    {
        cin >> W[i];
    }

    for(int i = 1;i <= n;++ i)
    {
        cin >> K[i];
        for(int j = 1, u, w;j <= K[i];++ j)
        {
            cin >> u >> w;
            stat[u].push_back(node{i, w});
            subway[i].push_back(node{u, w});
        }
    }

    for(int k = 1;k <= n;++ k)
    {
        for(int i = 1;i <= m;++ i) vis_sub[i] = false;
        while(que.size()) que.pop();
        int len = stat[k].size();
        for(int i = 0;i < len;++ i)
        {
            que.push(edge{k, stat[k][i].cost, stat[k][i].to});
        }
        while(que.size())
        {
            edge now = que.top();
            que.pop();
            if(floyd[k][now.to] == 0)
            {
                floyd[k][now.to] = now.cost + W[k] + W[now.to];
                floyd[now.to][k] = now.cost + W[k] + W[now.to];
                sum[k] += 1;
                sum[now.to] += 1;
            }
            if(sum[k] == n - 1)
            {
                break;
            }
            if(!vis_sub[now.sub])
            {
                vis_sub[now.sub] = true;
                int sub_len = K[now.sub];
                for(int i = 0;i < sub_len;++ i)
                {
                    int v = subway[now.sub][i].to, w = subway[now.sub][i].cost;
                    que.push(edge{v, now.cost + w, now.sub});
                }
            }else
            {
                int v = now.to, stat_len = stat[v].size();
                for(int i = 0;i < stat_len;++ i)
                {
                    int nxt_sub = stat[v][i].to, nxt_w = stat[v][i].cost;
                    if(!vis_sub[nxt_sub])
                    {
                        que.push(edge{v, now.cost + nxt_w, nxt_sub});
                    }
                }
            }
        }
    }

    while(q --)
    {
        cin >> st >> ed;
        cout << floyd[st][ed] << endl;
    }

    return 0;
}
