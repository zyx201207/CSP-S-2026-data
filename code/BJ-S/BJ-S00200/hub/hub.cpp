#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, dis[100][100], f[100];
vector<int> e[100];

int find(int x)
{ return x==f[x]?x:f[x]=find(f[x]); }

int cnt2(int x)
{
    int res = 0;
    while(x)
    {
        res += (x&1);
        x >>=1;
    }
    return res;
}

void calc()
{
    cin >>n >>k;
    memset(dis, 0x3f, sizeof dis);
    for(int i=1; i<=n; i++)
    {
        dis[i][i]=0;
        e[i].clear();
    }
    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin >>u >>v;
        e[u].push_back(v);
        e[v].push_back(u);
        dis[u][v] = dis[v][u] = 1;
    }
    for(int t=1; t<=n; t++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dis[i][j] = min(dis[i][j], dis[i][t]+dis[t][j]);
    int ans = 1e18;
    for(int t=1; t<(1<<n); t++)
    {
        if(cnt2(t)!=k) continue;
        for(int i=1; i<=n; i++)
            f[i] = i;
        for(int i=1; i<=n; i++)
            if(t&(1<<i-1))
                for(int j=0; j<e[i].size(); j++)
                    if(t&(1<<e[i][j]-1))
                        f[find(i)] = find(e[i][j]);
        int cnt = 0;
        for(int i=1; i<=n; i++)
            if(t&(1<<i-1) && f[i] == i) cnt++;
        if(cnt > 2) continue;
        int maxn = 0;
        for(int i=1; i<=n; i++)
        {
            if(t&(1<<i-1)) continue;
            int minn = 1e18;
            for(int j=1; j<=n; j++)
                if(t&(1<<j-1)) minn = min(minn, dis[i][j]);
            maxn = max(maxn, minn);
        }
        ans = min(ans, maxn);
    }
    cout <<ans <<'\n';
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >>c>>t;
    while(t--)
    {
        calc();
    }
    return 0;
}