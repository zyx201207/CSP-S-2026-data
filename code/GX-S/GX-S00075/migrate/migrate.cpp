#include<bits/stdc++.h>
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define inf 0x3f3f3f3f
#define Inf (1ll<<60)
#define eps 1e-6
#define ls (i<<1)
#define rs (i<<1|1)
#define Debug(format,...) fprintf(stderr,format,##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
char *p1,*p2,buf[1<<20];
#define gc() (p1==p2 ? (p2=buf+fread(p1=buf,1,1<<20,stdin),p1==p2 ? EOF : *p1++) : *p1++)
inline ll read(){
    ll x=0,f=1;
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
const int N=2e6+50;
int Tid,n,r[N],l[N];
ll a[N],f[N],g[N],D;
bool ban[N],tag[N];
void solve(){
    n=read(),D=read();
    For(i,1,n) a[i]=read(),f[i]=g[i]=0;
    int nw=n;
    Down(i,n,1){
        while(nw>i && a[i]+D<a[nw]) --nw;  
        r[i]=nw;
    }
    nw=1;
    For(i,1,n){
        while(nw<i && a[nw]+D<a[i]) ++nw;
        l[i]=nw;
    }
    ll ans=0;
    if(Tid<=10){
        For(i,1,n){
            if(r[i]==i) continue;
            int cnt=0,lst=r[i];
            For(j,r[i]+1,n){
                int nw=cnt+(r[lst-1]>=j)+(r[lst-2]>=j);
                // Debug("%d %d %d %d %d\n",i,lst,j,cnt,nw);
                if(nw==1) ++ans;
                if(r[lst]==j) cnt+=(r[lst-1]==j)+(r[lst-2]==j),lst=j;
                if(r[j]==j) break;
            }
        }
    }
    else if(Tid<=12){
        ll d=a[2]-a[1],k=D/d;
        if(k>=2) ans=max(n-(2*k-1),0ll);
    }
    else if(Tid<=14){
        int x=0;
        For(i,1,n)
            if(abs(a[i]-a[1])<=D && abs(a[i]-a[n])<=D){
                x=i;
                break;
            }
        int c0=0,c1=0,c2=0,c3=0;
        For(i,1,x-1)
            if(r[i]==x)
                ++c0;
            else if(r[i]==x+1)
                ++c1;
        For(i,x+1,n)
            if(l[i]==x-1)
                ++c2;
            else if(l[i]==x)
                ++c3;
        ans=1ll*c0*c2+1ll*c1*c3;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    Tid=read();
    int T=read();
    while(T--) solve();
    return 0;
}