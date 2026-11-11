#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
const int NR = 6e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;

int idt, n, m, d, nq;
int k[505];
//int a[505][NR], t[505][NR];
int w[NR];
vector<pair<ll, int> > g[NR];
inline void addeage(int u, int v, int w){g[u].push_back({w, v});}
pair<pair<int, int>, int> q[NR];

int ans[NR];

int dis[NR], vis[NR];
void Dij(int s)
{
    for(int i = 0; i <= n + m + 10; i++) dis[i] = inf, vis[i] = 0;
    priority_queue<pair<long long, int> > pq;

    dis[s] = 0;
    pq.push({0, s});
    while(!pq.empty())
    {
        int x = pq.top().se; pq.pop();
        if(vis[x]) continue;
        vis[x] = true;
//cout << x << endl;
        for(auto y : g[x])
            if(dis[y.se] > dis[x] + y.fi)
            {
//cout << dis[y.se] << ">?" << dis[x] << "+" << y.fi << endl;
                dis[y.se] = dis[x] + y.fi;
                if(!vis[y.se]) pq.push({-dis[y.se], y.se});
            }
    }
/*
cout << "Dij " << s << endl;
for(int i = 1; i <= n + m; i++)printf("(%d, %d) = %lld, ", s, i, dis[i]);cout << endl;
*/

}

signed main()
{
    //freopen("/home/rdfz/桌面/BJ-S01474/subway/subway7.in", "r", stdin);
    //freopen("/home/rdfz/桌面/BJ-S01474/subway/subway7.out", "w", stdout);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> idt >> n >> m >> d >> nq;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            int a, t;
            cin >> a >> t;
            addeage(a, m+i, t);
            addeage(m+i, a, t);
        }
    }

    for(int i = 1; i <= nq; i++)
    {
        q[i].se = i;
        cin >> q[i].fi.fi >> q[i].fi.se;
        if(q[i].fi.fi > q[i].fi.se) swap(q[i].fi.fi, q[i].fi.se);
    }
    sort(q + 1, q + nq + 1);

    int now = 0;
    for(int i = 1; i <= nq; i++)
    {
        int x = q[i].fi.fi, y = q[i].fi.se, id = q[i].se;
        if(x != now) now = x, Dij(x);
        ans[id] = dis[y] + w[x] + w[y];
    }

    for(int i = 1; i <= nq; i++) cout << ans[i] << endl;
    return 0;
}
