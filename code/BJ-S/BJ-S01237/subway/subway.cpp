#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
struct nd{
    int y,t;
};
int c,n,m,d,q,w[500005];
long long dis[605][605],l[500505],t1[500005],t2[500005];
vector<int> g[500505];
queue<int> q1;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    if (n == 1)
    {
        int k;
        cin >> k;
        for (int i = 1;i <= k;i++)
        {
            int a,t;
            cin >> a >> t;
            t1[a] = t;
        }
        while (q--)
        {
            int x,y;
            cin >> x >> y;
            cout << w[x] + t1[x] + t1[y] + w[y] << endl;
        }
        return 0;
    }
    if (n == 2)
    {
        int k1,k2;
        long long tm = inf;
        cin >> k1;
        for (int i = 1;i <= k1;i++)
        {
            int a,t;
            cin >> a >> t;
            t1[a] = t;
        }
        cin >> k2;
        for (int i = 1;i <= k2;i++)
        {
            int a,t;
            cin >> a >> t;
            t2[a] = t;
            if (t1[a]) tm = min(tm,t1[a] + t2[a]);
        }
        while (q--)
        {
            int x,y;
            cin >> x >> y;
            long long ans = inf;
            if (t1[x] && t1[y]) ans = min(ans,t1[x] + w[x] + w[y] + t1[y]);
            if (t2[x] && t2[y]) ans = min(ans,t2[x] + w[x] + w[y] + t2[y]);
            if ((t1[x] && t2[y]) || (t2[x] && t1[y])) ans = min(ans,w[x] + t1[x] + tm + t2[y] + w[y]);
            cout << ans << endl;
        }
        return 0;
    }
    if (12 <= c && c <= 19)
    {
        int T;
        for (int i = 1;i <= n;i++)
        {
            int k;
            cin >> k;
            for (int j = 1;j <= k;j++)
            {
                int a,t;
                cin >> a >> t;
                T = t;
                g[a].push_back(i + m);
                g[i + m].push_back(a);
            }
        }
        while (q--)
        {
            int x,y;
            cin >> x >> y;
            queue<int> q1;
            q1.push(x);
            memset(l,0x3f,sizeof(l));
            l[x] = 0;
            while (!q1.empty())
            {
                int r = q1.front();
                q1.pop();
                for (auto t:g[r])
                {
                    if (l[t] != inf) continue;
                    q1.push(t);
                    l[t] = l[r] + T;
                }
            }
            cout << l[y] + w[x] + w[y] << endl;
        }
        return 0;
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for (int j = 1;j <= k;j++)
        {
            int a,t;
            cin >> a >> t;
            dis[a][m + i] = t;
            dis[m + i][a] = t;
        }
    }
    for (int i = 1;i <= m + n;i++)
    {
        for (int j = 1;j <= m + n;j++)
        {
            for (int k = 1;k <= m + n;k++)
            {
                dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);
            }
        }
    }
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        cout << dis[x][y] + w[x] + w[y] << endl;
    }
    return 0;
}
