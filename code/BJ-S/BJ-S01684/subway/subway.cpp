#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll c,n,m,d,q,ans,t;
ll a[N],blen,vis[N];
ll dis[410][410];
ll zdis[510][510];
struct bnode{
    ll pos,val;
}b[N];
struct edge{
    ll to,v;
};
vector<edge> f[N];
vector<ll> z[N];
void dfs(ll x,ll v,ll zd)
{
    if(x==zd)
    {
        ans=min(ans,v);
        return ;
    }
    for(ll i=0;i<f[x].size();i++)
    {
        edge k=f[x][i];
        if(vis[k.to]==1)
        {
            vis[k.to]=0;
            dfs(k.to,v+k.v,zd);
            vis[k.to]=1;
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=405;i++)
    {
        for(ll j=1;j<=405;j++)
        {
            dis[i][j]=INT_MAX;
            if(i==j)
            {
                dis[i][j]=0;
            }
        }
    }
    for(ll i=1;i<=505;i++)
    {
        for(ll j=1;j<=505;j++)
        {
            zdis[i][j]=INT_MAX;
            if(i==j)
            {
                zdis[i][j]=0;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>blen;
        for(ll j=1;j<=blen;j++)
        {
            cin>>b[j].pos>>b[j].val;
            t=b[j].val;
        }
        if(c>=12&&c<=19)
        {
            for(ll j=1;j<=blen;j++)
            {
                z[b[j].pos].push_back(i);
            }
        }
        for(ll j=1;j<=blen;j++)
        {
            for(ll k=1;k<=blen;k++)
            {
                if(j!=k)
                {
                    if(c>=4&&c<=6)
                    {
                        dis[b[j].pos][b[k].pos]=min(dis[b[j].pos][b[k].pos],b[k].val+b[j].val);
                    }
                    f[b[j].pos].push_back({b[k].pos,b[k].val+b[j].val});
                }
            }
        }
    }
    if(c>=12&&c<=19)
    {
        for(ll i=1;i<=m;i++)
        {
            for(ll j1=0;j1<z[i].size();j1++)
            {
                for(ll j2=j1+1;j2<z[i].size();j2++)
                {
                    zdis[z[i][j1]][z[i][j2]]=zdis[z[i][j2]][z[i][j1]]=1;
                }
            }
        }
        for(ll k=1;k<=n;k++)
        {
            for(ll i=1;i<=n;i++)
            {
                for(ll j=1;j<=n;j++)
                {
                    if(i!=j&&i!=k&&j!=k)
                    {
                        zdis[i][j]=min(zdis[i][j],zdis[i][k]+zdis[k][j]);
                    }
                }
            }
        }
    }
    if(c>=4&&c<=6)
    {
        for(ll k=1;k<=m;k++)
        {
            for(ll i=1;i<=m;i++)
            {
                for(ll j=1;j<=m;j++)
                {
                    if(i!=j&&i!=k&&j!=k)
                    {
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
    }
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        if(c>=4&&c<=6)
        {
            cout<<dis[l][r]+a[l]+a[r]<<"\n";
            continue;
        }
        if(c>=12&&c<=19)
        {
            ll minn=INT_MAX;
            for(ll i=0;i<z[l].size();i++)
            {
                for(ll j=0;j<z[r].size();j++)
                {
                    minn=min(minn,zdis[z[l][i]][z[r][j]]);
                }
            }
            cout<<(minn+1)*2*t+a[l]+a[r]<<"\n";
            continue;
        }
        ans=INT_MAX;
        for(ll i=1;i<=m;i++)
        {
            vis[i]=1;
        }
        vis[l]=0;
        dfs(l,0,r);
        cout<<ans+a[l]+a[r]<<"\n";
    }
    return 0;
}

