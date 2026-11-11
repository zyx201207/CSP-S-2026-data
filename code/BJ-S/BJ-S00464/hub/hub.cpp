#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,d[1000001],fans;
bool choosed[1000001],vis[1000001];
vector <int> e[1000001];
void gd (int nn)
{
    vis[nn]=true;
    for (auto i:e[nn])
    {
        if (choosed[i]&&(!vis[i]))
        {
            gd(i);
        }
    }
}
void calc (int nn)
{
    d[nn]=0x3f3f3f3f;
    vis[nn]=true;
    if (choosed[nn])
    {
        d[nn]=0;
        return;
    }
    for (auto i:e[nn])
    {
        if (!vis[i])
        {
            calc(i);
            d[nn]=min(d[nn],d[i]+1);
        }
    }
}
void dfs (int cs)
{
    if (cs==n)
    {
        memset(vis,false,sizeof(vis));
        int res=0,ans=0;
        for (int i=1;i<=n;i++)
        {
            if (choosed[i])
            {
                res++;
            }
        }
        if (res!=k)
        {
            return;
        }
        res=0;
        for (int i=1;i<=n;i++)
        {
            if (choosed[i]&&(!vis[i]))
            {
                res++;
                gd(i);
            }
        }
        if (res<=2)
        {
            for (int i=1;i<=n;i++)
            {
                if (!choosed[i])
                {
                    memset(vis,false,sizeof(vis));
                    calc(i);
                    ans=max(ans,d[i]);
                }
            }
            fans=min(fans,ans);
        }
        return;
    }
    choosed[cs]=false;
    dfs(cs+1);
    choosed[cs]=true;
    dfs(cs+1);
    choosed[cs]=false;
}
int main ()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        fans=1e9;
        cin >> n >> k;
        for (int i=1;i<n;i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(0);
        if (fans==1e9)
        {
            fans=1;
        }
        cout << fans << endl;
    }
    return 0;
}
