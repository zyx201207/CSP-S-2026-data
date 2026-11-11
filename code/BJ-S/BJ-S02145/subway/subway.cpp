#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node
{
    int v, w;
};
int c, n, m, d, q, w[20010], k[510], a[510][20010], t[510][20010], dist[1010][1010];
vector<node> ve[510];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for(int i=1;i<=n;i++)
    {
        for(int ui=1;ui<=k[i];ui++)
        {
            for(int vi=ui+1;vi<=k[i];vi++)
            {
                int u=a[i][ui], v=a[i][vi];
                dist[u][v]=min(dist[u][v], t[i][ui]+t[i][vi]);
                dist[v][u]=min(dist[v][u], t[i][ui]+t[i][vi]);
                // cout<<i<<' '<<u<<' '<<v<<' '<<t[i][ui]+t[i][vi]<<endl;
            }
        }
    }
    for(int g=1;g<=m;g++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // if(g==2&&i==1&&j==3)
                //     cout<<dist[i][j]<<endl;
                dist[i][j]=min(dist[i][j], dist[i][g]+dist[g][j]);
                // if(g==2&&i==1&&j==3)
                //     cout<<dist[i][g]<<' '<<dist[g][j]<<endl;
            }
        }
    }
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        cout<<w[l]+dist[l][r]+w[r]<<endl;
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/