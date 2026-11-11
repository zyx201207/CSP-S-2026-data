#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define ull unsigned long long
#define N 505
#define M 500005
using namespace std;

int rd(){char c=getchar();int f=1,x=0;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}return f*x;}
struct Node { int x; ll w; };
bool operator < (Node x, Node y) { return x.w > y.w; }

int C, n, m, d, Q, W[M], vis[N+M], nn;
ll dis[N+M], dd[N][N];
vector<Node> v[N+M];

void add(int x, int y, int w) { v[x].push_back({y,w}); }
ll dij(int ss, int tt)
{
    priority_queue<Node> q;
    for (int i = 0; i <= nn; i++) dis[i] = 1e18, vis[i] = 0;
    dis[ss] = 0, q.push({ss, 0});
    while (q.size())
    {
        Node tt = q.top(); q.pop();
        int x = tt.x; ll d = tt.w;
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i].x, ww = v[x][i].w;
            if (dis[y] > dis[x] + ww)
            {
                dis[y] = dis[x] + ww;
                if (!vis[y]) q.push({y, dis[y]});
            }
        }
    }
    // printf("--------------%d\n", ss);
    // for (int i = 1; i <= d*(m+1); i++) printf("dis[%d]=%lld\n", i, dis[i]);
    return dis[tt];
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    C = rd(), n = rd(), nn = m = rd(), d = rd(), Q = rd();
    for (int i = 1; i <= m; i++) W[i] = rd();
    for (int ii = 1, k, lst; ii <= n; ii++)
    {
        k = rd(), nn++;
        for (int i = 1; i <= k; i++)
        {
            // int p = rd(), now = p+(++ct[p])*m, t = rd();
            // num[p][ct[p]] = ii;
            // if (i > 1) add(now,lst,0), add(lst,now,0);
            // lst = now;
            // // cout << now << " ";
            // add(p,now,t), add(now,p,t);
            int p = rd(), t = rd();
            add(nn, p, t), add(p, nn, t);
        }
        // cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        dij(m+i, 1);
        for (int j = 1; j <= n; j++) dd[i][j] = dis[j+m];
    }
    while (Q--)
    {
        int x = rd(), y = rd();
        // cout << "\n___________________\n";
        ll minn = 1e18;
        for (int i = 0; i < v[x].size(); i++)
            for (int j = 0; j < v[y].size(); j++)
            {
                // cout << v[x][i].x << " " << v[y][i].x << " " << dd[v[x][i].x-m][v[y][i].x-m] << '\n';
                minn = min(minn, dd[v[x][i].x-m][v[y][j].x-m]+v[x][i].w+v[y][j].w);
            }
        cout << minn + W[x] + W[y] << '\n';
    }
    // while (Q--)
    // {
    //     int x = rd(), y = rd();
    //     cout << dij(x, y) + W[x] + W[y] << '\n';
    // }
    return 0;
}
/*
g++ subway.cpp -std=c++14 -O2 -o subway && time ./subway
*/