#include<bits/stdc++.h>
#define pb emplace_back
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 5000010;
int n, k;
int vis[N], dep[N], md[N], fa[N];
int p[N], m;
vector<int>e[N];
void dfsz(int now, int fat)
{
    fa[now] = fat;
    md[now] = 0;
    for(int to : e[now])
        if(to != fat && !vis[to])
        {
            dep[to] = dep[now] + 1;
            dfsz(to, now);
            md[now] = max(md[now], md[to] + 1);
        }
}
int sm;
int f[N], q[N], h[N];
void dfsd(int now, int fat)
{
    f[now] = 0;
    for(int to : e[now])
    if(to != fat && !vis[to])
    {
        dfsd(to, now);
        f[now] += f[to];
    }
    f[now] += (md[now] >= sm || !fat);
}
int tot = 0;
int maxn = 0;
int pre[N], nex[N], sl[N], sr[N], sv[N];
int sta[N], gd[N], top = 0;
pa id[N];
int mkne(int npre, int nnex, int nsl, int nsr, int nsv)
{
    ++tot;
    pre[tot] = npre;
    nex[tot] = nnex;
    sl[tot] = nsl;
    sr[tot] = nsr;
    sv[tot] = nsv;
    return tot;
}
void clear(pa &x, int nm)
{
    while(x.fi && sr[x.se] > nm)
    {
        if(sl[x.se] <= nm)
        {
            sr[x.se] = nm;
            return;
        }
        else
        {
            x.se = pre[x.se];
            if(!x.se)
            {
                x.fi = 0;
                return;
            }
            nex[x.se] = 0;
        }
    }
}
int chf(int u, int rr)
{
    if(sr[u] == rr)return u;
    ++tot;
    sl[tot] = sl[u];
    sr[tot] = rr;
    sl[u] = rr + 1;
    sv[tot] = sv[u];
    int pr = pre[u], ne = nex[u];
    nex[pr] = tot;
    pre[tot] = pr;
    nex[tot] = u;
    pre[u] = tot;
    nex[u] = ne;
    pre[ne] = u;
    return tot;
}
int merge(int u, int v)
{
    if(!u || !v)return u + v;
    int minn = min(sr[u], sr[v]);
    u = chf(u, minn);
    v = chf(v, minn);
    sv[u] = min(sv[u], sv[v]);
    int ne = merge(nex[u], nex[v]);
    nex[u] = ne;
    pre[ne] = u;
    return u;
}
pa merge(pa u, pa v)
{
    if(!u.fi)return v;
    if(!v.fi)return u;
    if(sr[u.se] < sr[v.se])swap(u, v);
    int bg = merge(u.fi, v.fi);
    if(sr[u.se] > sr[v.se])return {bg, u.se};
    int nn = bg;
    while(nex[nn])nn = nex[nn];
    return {bg, nn};
}
void dfs2(int now, int fat)
{
    sta[++top] = now;
    if(gd[now] > top)gd[now] = 1e9;
    int m1 = 0, m2 = 0;
    for(int to : e[now])
    if(to != fat && !vis[to])
    {
        if(md[to] + 1 > m1)m2 = m1, m1 = md[to] + 1;
        else m2 = max(m2, md[to] + 1);
    }
    id[now] = {0, 0};
    for(int to : e[now])
        if(to != fat && !vis[to])
        {
            gd[to] = gd[now];
            int len = m1;
            if(md[to] + 1 == m1)len = m2;
            gd[to] = max(gd[to], dep[now] + len - sm + 1);
            dfs2(to, now);
            clear(id[to], dep[now] + (sm - len));
            id[now] = merge(id[now], id[to]);
        }
    int kv = max(f[now], 1);
    int nr = dep[now];
    while(id[now].fi && kv <= sv[id[now].fi])
    {
        nr = sr[id[now].fi];
        id[now].fi = nex[id[now].fi];
        pre[id[now].fi] = 0;
    }
    if(!id[now].fi)id[now].se = 0;
    mkne(0, id[now].fi, dep[now], nr, kv);
    pre[id[now].fi] = tot;
    id[now].fi = tot;
    if(!id[now].se)id[now].se = tot;
    if(gd[now] == 1)
        maxn = max(maxn, f[sta[gd[now]]] - 1 - sv[id[now].se]);
    else if(gd[now] <= top && fat)
        maxn = max(maxn, f[sta[gd[now]]] - sv[id[now].se]);
    top--;
}
bool check()
{
    int ml = sm + 1, mr = m - sm;
    int sum = 0;
    for(int i = ml; i <= mr; i++)
    {
        dfsd(p[i], 0);
        sum += f[p[i]];
    }
    memset(q, 0x3f, sizeof q);
    memset(h, 0x3f, sizeof h);
    int gt = ml, ss = 0;
    for(int i = ml; i < mr; i++)
    {
        gt = max(gt, i);
        while(gt < m && gt + 1 - i + md[p[gt + 1]] <= sm)gt++;
        ss += f[p[i]];
        q[gt] = min(q[gt], ss);
    }
    gt = mr;
    ss = 0;
    for(int i = mr; i > ml; i--)
    {
        gt = min(gt, i);
        while(gt > 1 && i - gt + 1 + md[p[gt - 1]] <= sm)gt--;
        ss += f[p[i]];
        h[gt] = min(h[gt], ss);
    }
    for(int i = m - 1; i; i--)q[i] = min(q[i], q[i + 1]);
    for(int i = 2; i <= m; i++)
    {
        h[i] = min(h[i], h[i - 1]);
        if(q[i - 1] + h[i] <= k)return 1;
    }
    tot = 0;
    maxn = 0;
    for(int i = 1; i <= m; i++)
    {
        gd[p[i]] = 1;
        dfs2(p[i], 0);
    }
    return sum - maxn <= k;
}
void slove()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)e[i].clear(), vis[i] = 0;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].pb(v);
        e[v].pb(u);
    }
    int x = 1, y = 1;
    dep[1] = 1;
    dfsz(1, 0);
    for(int i = 1; i <= n; i++)
        if(dep[i] > dep[x])
            x = i;
    dep[x] = 1;
    dfsz(x, 0);
    for(int i = 1; i <= n; i++)
        if(dep[i] > dep[y])
            y = i;
    p[m = 1] = y;
    while(p[m] != x)
    {
        int nex = fa[p[m]];
        p[++m] = nex;
    }
    for(int i = 1; i <= m; i++)vis[p[i]] = 1;
    for(int i = 1; i <= m; i++)
    {
        dep[p[i]] = 1;
        dfsz(p[i], 0);
    }
    int ml = 0, mr = (m - 1) / 2;
    while(ml < mr)
    {
        int mid = (ml + mr) / 2;
        sm = mid;
        if(check())mr = mid;
        else ml = mid + 1;
    }
    printf("%d\n", ml);
}
int main()
{
    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--)slove();
    return 0;
}
