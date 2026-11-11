#include <bits/stdc++.h>

using namespace std;

long long c, t, n, k, ans=INT_MAX;
bool vis[1000010], active[1000010];

struct Node
{
    vector<int> lines;
} nodes[1000010];

inline void tt();
inline void gg(int idd);
inline void ff(int idd);
inline void check();

inline void tt()
{
    scanf("%d%d", &n, &k);
    for(int i=1,u,v;i<=n;i++)
    {
        scanf("%d%d", &u, &v);
        nodes[u].lines.push_back(v);
        nodes[v].lines.push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    memset(active, 0, sizeof(active));
    ans=INT_MAX;
    gg(0);
    printf("%lld\n", ans);
}

inline void gg(int idd)
{
    active[idd]=1;
    for(int i=idd; i<=n;i++)
    {
        if(idd>0)check();
        gg(i);
    }
    active[idd]=0;
}

inline void ff(int idd)
{
    if (vis[idd]||!active[idd]) return;
    vis[idd]=1;
    for(int iddd: nodes[idd].lines)
    {
        ff(iddd);
    }
}

inline void check()
{
    int block=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        ff(i);
        block++;
    }
    if(block!=2) return;
    for(int i=1; i<=n;i++)
    {
        vector<pair<int,int>> sstack;
        int curr=-1;
        memset(vis, 0, sizeof(vis));
        sstack.push_back(make_pair(i, 0));
        vis[i]=1;
        while(++curr<sstack.size())
        {
            if(vis[sstack[curr].first]) continue;
            if (active[sstack[curr].first]&&ans>sstack[curr].second)
            for(int iddd: nodes[sstack[curr].first].lines)
            {
                sstack.push_back(make_pair(iddd, sstack[curr].second));
            }
        }
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    scanf("%d%d", &c, &t);

    while(t--) tt();

    return 0;
}