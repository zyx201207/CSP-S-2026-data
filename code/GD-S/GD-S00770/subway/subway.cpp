#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cr,n,m,d,q;
ll dis[505][505],w[500005];
vector<ll> a[505],t[505];
vector<pair<ll,ll>> inr[500005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>cr>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)dis[i][j]=(i==j?0:3e18);
    for(ll i=1;i<=n;i++)
    {
        ll c;
        cin>>c;
        for(ll j=1;j<=c;j++)
        {
            ll tmp1,tmp2;
            cin>>tmp1>>tmp2;
            a[i].push_back(tmp1),t[i].push_back(tmp2);
            for(auto [v,tmp3]:inr[tmp1])dis[v][i]=dis[i][v]=min(dis[v][i],tmp2+tmp3);
            inr[tmp1].push_back({i,tmp2});
        }
    }
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // for(ll i=1;i<=n;i++)
    // {
    //     for(ll j=1;j<=n;j++)cout<<dis[i][j]<<' ';
    //     cout<<'\n';
    // }
    while(q--)
    {
        ll xg,yg,ans=3e18;
        cin>>xg>>yg;
        for(auto [u,tmp1]:inr[xg])
        {
            for(auto [v,tmp2]:inr[yg])
            {
                ans=min(ans,tmp1+tmp2+w[xg]+w[yg]+dis[u][v]);
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}