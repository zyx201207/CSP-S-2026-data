#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,l,u,v,i,a,t,mp[505][505],w[500005],ans;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct _
{
    ll v,w;
};
vector<_>g[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i = 1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(ll i = 1;i<=n;i++)
    {
        for(ll j = 1;j<=n;j++)
        {
            mp[i][j] = inf;
        }
    }
    for(ll i = 1;i<=n;i++)mp[i][i] = 0;
    for(ll i = 1;i<=n;i++)
    {
        cin>>l;
        for(ll j = 1;j<=l;j++)
        {
            cin>>a>>t;
            for(_ e:g[a])
            {
                mp[i][e.v] = mp[e.v][i] = min(mp[i][e.v],e.w+t);
            }
            g[a].push_back({i,t});
        }
    }
    for(ll k = 1;k<=n;k++)
    {
        for(ll i = 1;i<=n;i++)
        {
            for(ll j = 1;j<=n;j++)
            {
                mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    while(q--)
    {
        cin>>u>>v;
        ans = inf;
        for(_ e:g[u])
        {
            for(_ f:g[v])
            {
                ans = min(ans,e.w+f.w+mp[e.v][f.v]);
            }
        }
        cout<<w[u]+w[v]+ans<<'\n';
    }
}