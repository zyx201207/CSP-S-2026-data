#include<bits/stdc++.h>
namespace xcy{
typedef long long ll;
typedef std::pair<ll,ll> sp;
const ll MAXM=500005;
const ll INF=0x3f3f3f3f3f3f3f3f;
#define fi first
#define se second
#define emp emplace
#define emb emplace_back
#define ppb pop_back
#define vc std::vector
ll dis[505][505],w[MAXM],n,m,p,c,d,i,j,k,l,ans;
std::vector<sp>v[MAXM];

inline void fr(ll &X){X=0;ll A=1;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void _fo(const ll X){if(!X)return;_fo(X/10);putchar(X%10+'0');}
inline void fo(ll X,char C=' '){if(!X)putchar('0');if(X<0)putchar('-'),X=-X;_fo(X),putchar(C);}
inline void cmin(ll &A,const ll &B){if(B<A)A=B;}

int mian()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    fr(c),fr(n),fr(m),fr(d),fr(p);
    for(i=1;i<=m;++i)fr(w[i]);for(i=1;i<=n;++i)dis[i][i]=0;
    for(i=1;i<=n;++i)for(fr(j);j;--j)fr(k),fr(l),v[k].emb(i,l);
    for(i=1;i<=m;++i)for(j=0;j<v[i].size();++j)for(k=0;k<j;++k)
        cmin(dis[v[i][j].fi][v[i][k].fi],v[i][j].se+v[i][k].se);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)
        dis[i][j]=std::min(dis[i][j],dis[j][i]);
    for(k=1;k<=n;++k)for(i=1;i<=n;++i)for(j=1;j<=n;++j)
        cmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(p--){fr(i),fr(j),ans=INF;
    for(auto I:v[i])for(auto J:v[j])cmin(ans,dis[I.fi][J.fi]+I.se+J.se);
    fo(ans+w[i]+w[j],'\n');
    }return 0;
}}
int main(){return xcy::mian();}