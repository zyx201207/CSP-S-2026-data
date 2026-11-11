#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int w[500005] = {};
int a[505][505] = {};
int t[505][505] = {};
bool vis[500005] = {};
int p[500005][505] = {};
int x, y;
int c, n, m, d, q;
int ans = 1e9;
queue<int> qu;
int bfs(int cur)
{
    if(qu.empty())return cur;
    if(vis[x]) return cur;
    vis[x] = true;
    for (int i = 1 ; i <= n ;i++)
    {
        if(a[i][qu.front()] != 0)
        {
            if(a[i][qu.front()] > 1)
            {
                qu.push(a[i][p[i][qu.front()] - 1]);
            }
            if (a[i][qu.front()] < n)
            {
                qu.push(a[i][p[i][qu.front()] + 1]);
            }
        }
        int c = qu.front();
        qu.pop();
        for (int i = 1 ; i <= n ; i++)
        {
            if(t[i][p[i][c]] != 0)
            {
                cur += t[i][p[i][c]];
                cur = min(cur,bfs(cur));
            }

        }
    }
    return cur;
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   //cout << "OK" ;
     cout.flush();
    cin >> c >> n >> m >> d >> q;

    for (int i = 1 ; i <= m ; i++)
    {
        cin >> w[i];
    }
   for (int i = 1  ; i <= n ; i++)
    {
        int k;
        cin >> k;
        for (int j = 1 ; j <= k ; j++)
        {
           int ax, tx;
            cin >> ax >> tx;
            a[i][j] = ax;
            t[i][j] = tx;
            p[ax][i] = j;

        }
    }
    //cout << "start";
    while(q--)
    {
        cin >> x >> y;
        for (int i = 1 ; i <= n ; i++)
        {
            if(p[x][i])
            {
                qu.push(a[i][p[x][i] - 1]);
                qu.push(a[i][p[x][i] + 1]);
            }
        }
        cout << bfs(w[x]) + w[y] << endl;
    }

    fcloseall();

    return 0;
}
