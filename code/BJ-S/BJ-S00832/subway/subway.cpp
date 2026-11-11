#include<bits/stdc++.h>
using namespace std;
const int maxk=5e5+5;
int c, n, m, d, q;
int w1[maxk],a[505][maxk],t[505][maxk],k[505];
// struct edge{
//     int v;
//     int b;
// };
// vector<edge>g[505];
// void dfs(int u)
// {
//     for(auto o: g[u])
//     {
//         cnt=cnt+t[o.b][o.v]+t[u.b][o.v];
//     }
// }
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w1[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=k[i]-1;j++)
    //     {
    //         g[a[i][j]].push_back({a[i][j+1],i});
    //         g[a[i][j+1]].push_back({a[i][j],i});
    //     }
    // }
    while(q--)
    {
        int ans=0;
        int x,y;
        cin>>x>>y;
        ans=w1[x]+w1[y];
        int minn=0x3f3f3f3f,minnn=0x3f3f3f3f;
        for(int i=1;i<=n;i++)
        {
            minn=min(minn,t[i][x]);
            minnn=min(minnn,t[i][y]);
        }
        ans=ans+minn+minnn;
        // dfs(x);
        cout<<ans;
    }
    return 0;
}