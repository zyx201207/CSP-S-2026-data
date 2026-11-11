#include<bits/stdc++.h>
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define inf 0x3f3f3f3f
#define Inf (1ll<<60)
#define eps 1e-6
#define ls (i<<1)
#define rs (i<<1|1)
#define Debug(format,...) fprintf(stderr,format,##__VA_ARGS__)
#define ep emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll> pii;
char *p1,*p2,buf[1<<20];
#define gc() (p1==p2 ? (p2=buf+fread(p1=buf,1,1<<20,stdin),p1==p2 ? EOF : *p1++) : *p1++)
inline int read(){
    int x=0,f=1;
    char c=gc();
    while(c<'0' || c>'9') f=(c=='-' ? -1 : 1),c=gc();
    while('0'<=c && c<='9') x=(x<<3)+(x<<1)+(c&15),c=gc();
    return x*f;
}
inline int max(int x,int y){return x>y ? x : y;}
inline ll max(ll x,ll y){return x>y ? x : y;}
inline int min(int x,int y){return x<y ? x : y;}
inline ll min(ll x,ll y){return x<y ? x : y;}
inline void ckmx(int &x,int y){x=(x<y ?  y : x);}
inline void ckmx(ll &x,ll y){x=(x<y ? y : x);}
inline void ckmn(int &x,int y){x=(x>y ? y : x);}
inline void ckmn(ll &x,ll y){x=(x>y ? y : x);}
const int N=505,M=5e5+50;
int Tid,n,m,d,q;
ll a[M],dis[N][N];
vector<pii> S[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Tid=read(),n=read(),m=read(),d=read(),q=read();
    For(i,1,m) a[i]=read();
    For(i,1,n){
        int len=read(),x,v;
        For(j,1,len) x=read(),v=read(),S[x].ep(i,v);
    }
    memset(dis,inf,sizeof(dis));
    For(i,1,n) dis[i][i]=0;
    // int cnt=0;
    For(u,1,m)
        for(auto [d1,v1] : S[u])
            for(auto [d2,v2] : S[u])
                ckmn(dis[d1][d2],v1+v2);
    // Debug("%d\n",cnt);
    For(k,1,n)
        For(i,1,n)
            For(j,1,n)
                ckmn(dis[i][j],dis[i][k]+dis[k][j]);
    int u,v;
    For(i,1,q){
        u=read(),v=read();
        ll ans=Inf;
        for(auto [d1,v1] : S[u])
            for(auto [d2,v2] : S[v])
                ckmn(ans,v1+dis[d1][d2]+v2);
        printf("%lld\n",a[u]+a[v]+ans);
    }
    return 0;
}