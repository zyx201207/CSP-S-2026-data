#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
int c,st,li,lim,q,n[maxn],pass[501][maxn],to[maxn * 2],head[maxn],nxt[maxn * 2],tot;
int w[maxn],t[501][maxn];
ll d[maxn],e[maxn * 2];
void add(int u,int v,ll ww)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    e[tot] = ww;
}
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
void dij(int s)
{
    for (int i = 1;i <= st;i++) d[i] = 1e18;
    d[s] = 0;
    pq.push(make_pair(0,s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        ll du = pq.top().first;pq.pop();
        if (du > d[u]) continue;
        for (int i = head[u];i;i = nxt[i])
        {
            int v = to[i];
            ll nd = du + e[i];
            if (nd < d[v]) d[v] = nd,pq.push(make_pair(nd,v));
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> li >> st >> lim >> q;
    for (int i = 1;i <= st;i++) cin >> w[i];
    for (int i = 1;i <= li;i++)
    {
        cin >> n[i];
        for (int j = 1;j <= n[i];j++)
        {
            int t1,t2;
            cin >> t1 >> t2;
            t[i][t1] = t2;
            pass[i][j] = t1;
        }
    }
    for (int i = 1;i <= li;i++)
        if (t[i][i]) for (int j = 1;j <= n[i];j++) add(pass[i][j],i,(ll)t[i][i] + t[i][pass[i][j]]),add(i,(ll)pass[i][j],t[i][i] + t[i][pass[i][j]]);
    int xr,yr;
    for (int i = 1;i <= q;i++)
    {
        cin >> xr >> yr;
        dij(xr);
        cout << d[yr] + w[xr] + w[yr] << '\n';
    }
    return 0;
}
