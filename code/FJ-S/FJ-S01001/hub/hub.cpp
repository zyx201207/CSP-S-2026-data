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
ll f[105][105],mnd[105][105],siz[MAXN],dep[MAXN],mxd[MAXN],head[MAXN],is[15],cnt,t,n,m,i,j,k,l,ans,res;
std::vector<ll>g[105];std::bitset<105>vis;struct Ed{ll pre,to;}ed[MAXN<<1];

inline void fr(ll &X){X=0;ll A=1;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void _fo(const ll X){if(!X)return;_fo(X/10);putchar(X%10+'0');}
inline void fo(ll X,char C=' '){if(!X)putchar('0');if(X<0)putchar('-'),X=-X;_fo(X),putchar(C);}
inline void add(ll F,ll T){ed[++cnt].to=T;ed[cnt].pre=head[F];head[F]=cnt;}
inline void dfs1(ll N,ll Fa)
{
    for(ll I=head[N],J;I;I=ed[I].pre)
        if(!is[J=ed[I].to]&&J!=Fa)
            dep[J]=std::min(dep[J],dep[N]+1),dfs1(J,N);
}
inline void dfs2(ll N)
{
    vis[N]=1;for(ll I=head[N],J;I;I=ed[I].pre)
        if(is[J=ed[I].to]&&!vis[J])dfs2(J);
}

int mian()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    fr(t),fr(t);while(t--){fr(n),fr(m);cnt=0,ans=n;
    memset(head,0,sizeof(head));
    for(i=1;i<n;++i)fr(j),fr(k),add(j,k),add(k,j);
    for(l=1;l<1<<n;++l)
    {
        j=0;for(i=1;i<=n;++i)if((l>>i-1)&1)is[i]=1,++j;else is[i]=0;
        if(j!=m)continue;
        for(i=1;i<=n;++i)vis[i]=0,dep[i]=n;
        for(i=1;i<=n;++i)if(is[i])dep[i]=0,dfs1(i,0);
        res=0;for(i=1;i<=n;++i)res=std::max(res,dep[i]);
        j=0;for(i=1;i<=n;++i)if(is[i]&&!vis[i])++j,dfs2(i);
        if(j<=2)ans=std::min(ans,res);
    }
    fo(ans,'\n');
    }return 0;
}}
int main(){return xcy::mian();}