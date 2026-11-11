#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
ll c,n,m,d,q;
struct node
{
    ll sub,sta,di;
};
struct nod
{
    ll x,d,op;//op=0 station;op=1 subway
};
vector<node> g[505],gg[505];
ll w[500005],ans[1005][1005],mind[505];
void bfs(ll st)
{
    memset(mind,0x7f,sizeof(mind));
    queue<nod> q;
    q.push({st,0,0});
    while (!q.empty())
    {
        ll x = q.front().x,d = q.front().d,op = q.front().op;
        q.pop();
        if (op == 0)
        {
            for (auto nw:gg[x])
            {
                ll nsub = nw.sub,nd = d+nw.di;
                if (mind[nsub] > nd)
                {
                    mind[nsub] = nd;
                    q.push({nsub,nd,1});
                }
            }
        }
        else
        {
            for (auto nw:g[x])
            {
                ll nsta = nw.sta,nd = d+nw.di;
                if (ans[st][nsta] > nd)
                {
                    ans[st][nsta] = nd;
                    q.push({nsta,nd,0});
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    memset(ans,0x7f,sizeof(ans));
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++)
    {
        ll x;
        cin >> x;
        while (x--)
        {
            ll j,k;
            cin >> j >> k;
            g[i].push_back({i,j,k});
            gg[j].push_back({i,j,k});
        }
    }
    for (int i = 1;i <= m;i++)
    {
        bfs(i);
    }
    while (q--)
    {
        ll x,y;
        cin >> x >> y;
        ll anss = ans[x][y] + w[x] + w[y];
        cout << anss << "\n";
    }
    return 0;
}
