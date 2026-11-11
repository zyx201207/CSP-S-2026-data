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
const int N=5e5+50;
int n,m;
ll a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    For(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    For(i,1,n) d[i]=d[i-1]+a[i];
    int ans=0;
    For(i,1,n){
        int L=1,R=i,mid,res=0;
        while(L<=R){
            mid=L+R>>1;
            if(a[i]*mid-(d[i]-d[i-mid])<=m)
                res=mid,L=mid+1;
            else
                R=mid-1;
        }
        ckmx(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}