#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k,x,y,nans,nw[500005];
int dis[505][505];
vector<int> v[500005],w[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i++) cin>>nw[i];
    for(int i = 1; i <= n; i++)
    {
        cin>>k;
        for(int j = 1; j <= k; j++)
        {
            cin>>x>>y;
            v[x].push_back(i);
            w[x].push_back(y);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i==j) continue;
            dis[i][j]=1e18;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int nsz=v[i].size();
        for(int ja = 0; ja < nsz; ja++)
        {
            for(int jb = 0; jb < nsz; jb++)
            {
                dis[v[i][ja]][v[i][jb]]=min(dis[v[i][ja]][v[i][jb]],w[i][ja]+w[i][jb]);
            }
        }
    }
    for(int nk = 1; nk <= n; nk++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][nk]+dis[nk][j]);
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--)
    {
        nans=1e18;
        cin>>x>>y;
        for(int i = 0; i < v[x].size(); i++)
        {
            for(int j = 0; j < v[y].size(); j++)
            {
                // cout<<nw[x]<<' '<<nw[y]<<' '<<w[x][i]<<' '<<w[y][j]<<' '<<v[x][i]<<' '<<v[y][j]<<'\n';
                nans=min(nans,nw[x]+nw[y]+w[x][i]+w[y][j]+dis[v[x][i]][v[y][j]]);
            }
        }
        cout<<nans<<'\n';
    }
    return 0;
}