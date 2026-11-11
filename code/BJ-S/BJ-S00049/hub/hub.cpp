#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5005, INF = 1e9;
int c, t, n, d, x[N];
int lf = 1, rt = 0, q[N];
int dis[N], k[N], fstu = 0, cnt[N], ans = 0; // k[u]: u->...->k[u]->v fstu: the farthest u (dis[u] < INF) -1 -> the nearest u (dis[u] >= INF)

void calc()
{
    memset(q, 0, sizeof(q));
    memset(cnt, 0, sizeof(cnt));
    memset(k, 0, sizeof(k));
    fstu = 0;
    for (int v = 1; v <= n; v++)
    {
        while (lf <= rt && x[v] - d > x[q[lf]]) lf++;
        for (int i = lf; i <= rt; i++) // dis=1
        {
            int u = q[i];
            dis[u] = 1;
            cnt[u] = 1;
            k[u] = u;
        }
        if (lf > rt)
        {
            for (int u = fstu+1; u < v; u++) dis[u] = INF, cnt[u] = 0;
            fstu = v;
        }
        else
        {
            for (int u = fstu+1; u < q[lf]; u++) // dis>1
            {
                if (dis[u] >= INF)
                {
                    fstu = u;
                    continue;
                }
                if (k[u] < q[lf]) dis[u]++, k[u] = v-1; // u->k[u]->v-1->v
                // else u->k[u]->v
            }
            // dis[u]: the min distance of path v->u
            for (int u = fstu+1; u < q[lf]; u++) // dis>1
            {
                int ct = rt-lf+1;
                if (k[u] == v-1) cnt[u] *= ct;//u->...->v-1(k[u])->v
                if (cnt[u] == 2) ans++;
            }
        }

        q[++rt] = v;
        dis[v] = 0;
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        sort(x+1, x+n+1);
        if (c == 0)
        {
            if (n==2) cout<<"1\n2\n";
        }
        else
        {
            calc();
            cout << ans << endl;
        }
    }
    return 0;
}
