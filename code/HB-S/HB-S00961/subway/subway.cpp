#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int maxn=5e5+10;
const int inf=1e18;
int cid,n,m,mxd,q,w[maxn],k,x,y;
vector<pii> v[maxn],occ[maxn];
int dis[510][510];
inline void cmin(int &a,int b){a=min(a,b);}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')f=-f;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cid=read();n=read();m=read();mxd=read();q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++)
    {
        k=read();
        for(int j=0;j<k;j++)
        {
            x=read();y=read();
            v[i].push_back(make_pair(x,y));occ[x].push_back(make_pair(i,j));
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=((i==j)?0:inf);
    for(int id1=1;id1<=n;id1++)
    {
        for(auto mid:v[id1])
        {
            int y=mid.fi,z=mid.se;
            for(auto nw2:occ[y])
            {
                int id2=nw2.fi;
                cmin(dis[id1][id2],z+v[id2][nw2.se].se);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            for(int j=1;j<=n;j++)cmin(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--)
    {
        x=read();y=read();int ans=inf;
        for(auto nw1:occ[x])
        {
            for(auto nw2:occ[y])
            {
                int id1=nw1.fi,id2=nw2.fi;
                cmin(ans,w[x]+w[y]+v[id1][nw1.se].se+v[id2][nw2.se].se+dis[id1][id2]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
