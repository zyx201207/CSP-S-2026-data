#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,INF=0x3f3f3f3f3f3f3f;
ll w[500100];
ll dist[600][600];
struct edge{
    ll u,w;
};
vector<edge> v[500100];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;//c,road,station,
    for(ll i=1 ; i<=m ; i++) cin >> w[i];
    for(ll i=1 ; i<=n ; i++)
    {
        for(ll j=1 ; j<=n ; j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(ll i=1 ; i<=n ; i++)
    {
        ll k;
        cin >> k;
        for(ll j=0 ; j<k ; j++)
        {
            ll a,b;
            cin >> a >> b;
            v[a].push_back( edge{i,b} );
        }
    }
    for(ll i=1 ; i<=m ; i++)
    {
        for(ll j=0 ; j<v[i].size() ; j++)
        {
            for(ll k=j+1 ; k<v[i].size() ; k++)
            {
                dist[v[i][j].u][v[i][k].u] = min(dist[v[i][j].u][v[i][k].u],v[i][j].w+v[i][k].w);
                dist[v[i][k].u][v[i][j].u] = dist[v[i][j].u][v[i][k].u];
            }
        }
    }

    for(ll k=1 ; k<=n ; k++)
    {
        for(ll i=1 ; i<=n ; i++)
        {
            for(ll j=1 ; j<=n ; j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--)
    {
        ll xr,yr;
        cin >> xr >> yr;
        ll ans=INF;
        bool g=false;
        for(ll i=0 ; i<v[xr].size() ; i++)
        {
            edge x=v[xr][i];
            for(ll j=0 ; j<v[yr].size() ; j++)
            {
                edge y=v[yr][j];
                if(x.u == y.u)
                {
                    g=true;
                    ans=x.w+y.w+w[xr]+w[yr];
                    break;
                }
                ll tmp=dist[x.u][y.u]+x.w+y.w+w[xr]+w[yr];
                ans=min(ans,tmp);
            }
            if(g) break;
        }
        cout << ans << endl;
    }
    return 0;
}

