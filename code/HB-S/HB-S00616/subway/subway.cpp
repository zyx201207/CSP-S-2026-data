#include <bits/stdc++.h>
using namespace std;
#define int long long
struct S
{
    int w, id;
};
vector <S> v[500005];
bool vis[500005];
int dif[500005];
void dij(int s)
{
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    memset(dif, 0x3f, sizeof(dif));
    memset(vis, 0, sizeof(vis));
    dif[s] = 0;
    while(!q.empty())
    {
        auto y = q.top();
        q.pop();
        if(vis[y.second]) continue;
        vis[y.second] = 1;
        for(auto z : v[y.second])
        {
            if(dif[z.id] > dif[y.second] + z.w)
            {
                dif[z.id] = dif[y.second] + z.w;
                q.push({dif[z.id], z.id});
            }
        }
    }
}
signed main()
{
    //zhe shi lca mo ban ti, dan wo bu hui lca !!!!!!!!
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin>>c>>n>>m>>d>>q;
    int cur = 0;
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin>>x;
        cur++;
        v[cur].push_back({x, cur + 1});
        v[cur + 1].push_back({x, cur});
        cur++;
    }
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin>>k;
        int lx;
        for(int j = 1; j <= k; j++)
        {
            int x, y;
            cin>>x>>y;
            cur++;
            v[cur].push_back({y, 2 * x});
            v[2 * x].push_back({y, cur});
            if(j != 1)
            {
                v[lx].push_back({0, cur});
                v[cur].push_back({0, lx});
            }
            lx = cur;
        }
    }
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        x = 2 * x - 1;
        y = 2 * y - 1;
        dij(x);
        cout<<dif[y]<<endl;
    }
}