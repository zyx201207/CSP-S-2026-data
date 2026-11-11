#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,o,q,minn,b[500005],l[500005],a[505][20005];
struct p
{
    ll x,y;
};
vector<ll> v[505],d[500005];
void f(ll x,ll y,ll s,ll t)
{
    if(x==y)
    {
        minn=min(minn,s+a[t][x]);
        cout<<minn<<endl;
        return;
    }
    if(l[t]==1) return;
    for(ll i=0;i<v[t].size();i++)//xian lu
    {
        if(v[t][i]==y)
        {
            minn=min(minn,s+a[t][y]);
            return;
        }
        for(ll j=0;j<d[v[t][i]].size();j++)
        {
            ll g=d[v[t][i]][j];
            if(g==t) continue;
            l[t]=1;
            f(v[t][i],y,s+a[t][v[t][i]]+a[g][v[t][i]],g);
            l[t]=0;
        }
    }

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>o>>q;
    for(ll i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    for(ll i=1;i<=n;i++)
    {
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            a[i][x]=y;
            d[x].push_back(i);
            v[i].push_back(x);
        }
    }
    while(q--)
    {
        minn=1e17;
        ll x,y;
        cin>>x>>y;
        for(ll i=0;i<d[x].size();i++)
            f(x,y,b[x]+b[y]+a[d[x][i]][x],d[x][i]);
        cout<<minn<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
