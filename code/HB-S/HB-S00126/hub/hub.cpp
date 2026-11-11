#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100015,inf = 1e9;
bool vis[N];
int n,k,cnt[N],con[N * 2],c;
struct edge {int u,v;} pl[N];

namespace bf
{
    bool sta[N];
    int dis[N],fa[N];

    int dfs(int x,int f)
    {
        fa[x] = f;
        int ans = sta[x];
        for(int i = cnt[x];i < cnt[x + 1];i++)
        {
            if(con[i] == f) continue;
            ans += dfs(con[i],x) - (sta[con[i]] && sta[x]);
        }
        return ans;
    }

    int dfs2(int x,int f)
    {
        dis[x] = inf;
        int now = x,cntx = 0;
        while(now && !sta[now]) now = fa[now],cntx++;
        if(now) dis[x] = cntx;
        int ans = inf;
        for(int i = cnt[x];i < cnt[x + 1];i++)
        {
            if(con[i] == f) continue;
            ans = min(ans,dfs2(con[i],x));
        }
        dis[x] = min(dis[x],ans + 1);
        return sta[x]?0:ans + 1;
    }

    void main()
    {
        int ans = 1000;
        for(int i = 0;i < 1 << n;i++)
        {
            int cnt = 0;
            for(int w = 0;w < n;w++)
                if(i & 1 << w)
                    sta[w + 1] = true,cnt++;
                else sta[w + 1] = false;
            if(cnt != k) continue;
            if(dfs(1,0) > 2) continue;
            dfs2(1,0);
            int dans = 0;
            for(int j = 1;j <= n;j++)
                dans = max(dis[j],dans);
            ans = min(ans,dans);
        }
        printf("%d\n",ans);
    }
}

namespace k2
{
    bool ind[N];
    int ql[N],l,r,root,fa[N],lson[N],dl[N],dtop,val[N];

    int dfs(int x,int f)
    {
        int len = 0;
        lson[x] = 0;
        for(int i = cnt[x];i < cnt[x + 1];i++)
        {
            if(con[i] == f) continue;
            int tmp = dfs(con[i],x);
            if(tmp > len)
                lson[x] = con[i],len = tmp;
        }
        return len + 1;
    }

    int dfs2(int x,int f)
    {
        int len = 0;
        lson[x] = 0;
        for(int i = cnt[x];i < cnt[x + 1];i++)
        {
            if(con[i] == f || ind[con[i]]) continue;
            int tmp = dfs2(con[i],x);
            if(tmp > len)
                lson[x] = con[i],len = tmp;
        }
        return len + 1;
    }

    void main()
    {
        memset(vis,false,(n + 1) * sizeof(bool));
        memset(ind,false,(n + 1) * sizeof(bool));
        l = 1,r = 0;
        ql[++r] = 1;
        while(l <= r)
        {
            int now = ql[l++];
            for(int i = cnt[now];i < cnt[now + 1];i++)
                if(!vis[con[i]])
                    ql[++r] = con[i],vis[con[i]] = true;
        }
        root = ql[r];
        dfs(root,0);
        int now = root;
        dtop = 0;
        while(now)
        {
            dl[dtop++] = now;
            ind[now] = true;
            now = lson[now];
        }
        int kval = 0;
        for(int i = 0;i < dtop;i++)
        {
            val[i] = dfs2(dl[i],0);
            assert(val[i] <= min(i + 1,dtop - i));
            kval = max(kval,min(i + val[i],dtop - i - 1 + val[i]) / 2);
        }
        printf("%d\n",kval);
    }
}

namespace A_xd
{
    void main()
    {
        if(k == n)
        {
            printf("0\n");
            return;
        }
        if(k >= n / 2)
        {
            printf("1\n");
            return;
        }
        printf("%d\n",(n / 2 - k + 3) / 4 + 1);
    }
}

void solve()
{
    scanf("%d %d\n",&n,&k);
    memset(cnt,0,(n + 2) * sizeof(int));
    for(int i = 0;i < n - 1;i++)
    {
        scanf("%d %d",&pl[i].u,&pl[i].v);
        cnt[pl[i].u]++,cnt[pl[i].v]++;
    }
    for(int i = 1;i <= n + 1;i++) cnt[i] += cnt[i - 1];
    for(int i = 0;i < n - 1;i++)
    {
        con[--cnt[pl[i].u]] = pl[i].v;
        con[--cnt[pl[i].v]] = pl[i].u;
    }
    if(c <= 3) return bf::main();
    if(c == 13 || c == 14) 
        return A_xd::main();
    // if(c == 7 || c == 11 || c == 12) 
        return k2::main();
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int T;
    scanf("%d %d",&c,&T);
    while(T--)
    {
        solve();
    }
    return 0;
}