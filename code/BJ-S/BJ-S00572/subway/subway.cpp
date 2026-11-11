#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using pi=pair<int,ll>;
#define pb push_back
#define fi first
#define se second
vl w;
vector<vector<pair<int,ll>>>aa;
ll dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q,i,j;
    cin>>c>>n>>m>>d>>q;
    w.resize(m+1);
    aa.resize(m+1);
    for(i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(j=1;j<=k;j++)
        {
            ll v,t;
            cin>>v>>t;
            aa[v].pb({i,t});
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                dis[i][j]=0;
            }
            else
            {
                dis[i][j]=1e18;
            }
        }
    }
    // for(i=1;i<=m;i++)
    // {
    //     cout<<aa[i].size()<<'\n';
    // }
    for(i=1;i<=m;i++)
    {
        for(j=0;j<aa[i].size();j++)
        {
            for(int k=j+1;k<aa[i].size();k++)
            {
                dis[aa[i][j].fi][aa[i][k].fi]=min(dis[aa[i][j].fi][aa[i][k].fi],aa[i][j].se+aa[i][k].se);
                dis[aa[i][k].fi][aa[i][j].fi]=min(dis[aa[i][k].fi][aa[i][j].fi],aa[i][j].se+aa[i][k].se);
            }
        }
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
                
            }
        }
    }
    // for(i=1;i<=n;i++)
    // {
    //     for(j=1;j<=n;j++)
    //     {
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--)
    {
        int v,u;
        cin>>v>>u;
        ll ans=1e18;
        for(pair<int,ll> xx:aa[v])
        {
            for(pair<int,ll> yy:aa[u])
            {
                ans=min(ans,dis[xx.fi][yy.fi]+xx.se+yy.se);
            }
        }
        cout<<ans+w[v]+w[u]<<'\n';
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