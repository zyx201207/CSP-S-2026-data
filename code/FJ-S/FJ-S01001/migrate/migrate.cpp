#include<bits/stdc++.h>
namespace xcy{
typedef long long ll;
typedef std::pair<ll,ll> sp;
const ll MAXN=2000005;
#define fi first
#define se second
#define emp emplace
#define emb emplace_back
#define ppb pop_back
#define vc std::vector
ll a[MAXN],b[MAXN],to[MAXN],vs[MAXN],vt[MAXN],t,n,m,i,j,k,l,ans,rs,rt;
std::vector<ll>g[MAXN];

inline void fr(ll &X){X=0;ll A=1;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void _fo(const ll X){if(!X)return;_fo(X/10);putchar(X%10+'0');}
inline void fo(ll X,char C=' '){if(!X)putchar('0');if(X<0)putchar('-'),X=-X;_fo(X),putchar(C);}

int mian()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    fr(i),fr(t);while(t--){fr(n),fr(m);ans=0;
    for(i=1;i<=n;++i)fr(a[i]),g[i].clear();
    for(i=j=n;i;--i){while(a[j]-a[i]>m)--j;
        to[i]=j;if(to[i]!=i)g[to[i]].emb(i);}
    for(i=n;i;--i)if(to[i]==i||to[i]==to[i-1])vt[i]=0;
        else vt[i]=vt[to[i]]+to[i]-to[i-1];
    for(i=1;i<=n;++i){vs[i]=1;for(auto I:g[i])
        if(I==1||to[I-1]<to[I])vs[i]+=vs[I];else ++vs[i];}
    for(i=3;i<=n;++i)if(to[i]!=i&&to[i-1]!=to[i-2])
    {
        rt=rs=0;
        if(to[i]==to[i-1])rt=to[i]-std::max(i,to[i-2])+vt[to[i]];
        else rt=to[i-1]-std::max(i,to[i-2]);
        for(auto I:g[i])if(I>1&&to[I-1]<i-1)rs+=vs[I];else ++rs;
        ans+=rt*rs;
    }
    fo(ans,'\n');
    }return 0;
}}
int main(){return xcy::mian();}