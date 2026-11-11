#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=pow(2,55);
ll c,n,m,d,q;
ll w[500010],k[500010];
ll a,t,x,y,ans;
vector<pair<ll,ll>> v[500010];
ll ti[510][510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                ti[i][j]=MAXN;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%lld%lld",&a,&t);
            v[a].push_back({t,i});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto j:v[i])
        {
            for(auto k:v[i])
            {
                if(j.second!=k.second)
                {
                    ti[j.second][k.second]=min(ti[j.second][k.second],j.first+k.first);
                    ti[k.second][j.second]=min(ti[k.second][j.second],j.first+k.first);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                ti[j][k]=min(ti[j][k],ti[j][i]+ti[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%lld%lld",&x,&y);
        ans=MAXN;
        for(auto j:v[x])
        {
            for(auto k:v[y])
            {
                ans=min(ans,ti[j.second][k.second]+j.first+k.first);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
