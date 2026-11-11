#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,dis[5000005];
vector<pair<int,int>>e[5000005];
void dij(int s)
{
    memset(dis,0x3f,sizeof(dis));
    queue<pair<int,int>>q;
    q.push({s,0});
    dis[s] = 0;
    while(!q.empty())
    {
        auto[x,disw] = q.front();
        q.pop();
        if(dis[x]<disw)
        {
            continue;
        }
        for(auto [y,w]:e[x])
        {
            if(dis[y]>dis[x]+w)
            {
                dis[y] = dis[x]+w;
                q.push({y,dis[y]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int u = 1;u<=m;u++)
    {
        int w;
        cin >> w;
        e[u].push_back({u+m,w});
        e[u+m].push_back({u,w});
    }
    for(int i = 1;i<=n;i++)
    {
        int k,last = 0;
        cin >> k;
        for(int u = 1;u<=k;u++)
        {
            int v,w;
            cin >> v >> w;
            e[v+m].push_back({v+(i+1)*m,w});
            e[v+(i+1)*m].push_back({v+m,w});
            if(last!=0)
            {
                e[v+(i+1)*m].push_back({last,0});
                e[last].push_back({v+(i+1)*m,0});
            }
            last = v+(i+1)*m;
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        dij(x);
        cout << dis[y] << endl;
    }
    return 0;
}