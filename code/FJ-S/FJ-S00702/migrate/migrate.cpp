#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i = (a);i <= (b);++i)
#define REP(i,a,b) for(int i = (a);i >= (b);--i)
#define ve std::vector
#define pb push_back
#define ll long long
static char stkk[200];
template<typename T>inline void output(T x){
    if(!x)return putchar('0'),void();
    if(x<0)x = ~x+1,putchar('-');
    int top = 0;
    for(;x;stkk[++top]=x%10^48,x/=10);
    for(;top;putchar(stkk[top--]));
}
template<typename T>inline void readx(T &x){
    x = 0;int y = 1;char c = getchar();
    for(;c<48||c>57;c = getchar())if(c=='-')y = -1;
    for(;c>=48&&c<=57;c = getchar())x = (x<<1)+(x<<3)+(c^48);
    x*=y;
}
const int N = 2e6+10,M = 23;
static int c,T,n,l[N],r[N];
static int ct[N],to[N],p[M][N];
static ll f[N],g[N];
static bool ok[N];
static ll d,x[N];
inline void get_lr(){
    for(int i = 1,j = 1;i <= n;++i){
        for(;x[i]-x[j]>d;++j);
        l[i] = j;
    }
    for(int i = n,j = n;i >= 1;--i){
        for(;x[j]-x[i]>d;--j);
        r[i] = j;
    }
}
inline void init(){
    FOR(i,1,n)p[0][i] = r[i];
    FOR(k,1,22)FOR(i,1,n)p[k][i] = p[k-1][p[k-1][i]];

    FOR(i,1,n)ct[i] = 0;
    FOR(i,1,n)++ct[l[i]];

    REP(i,n,1){
        if(i==r[i]||l[r[i]]!=i)ok[i] = 0,f[i] = g[i] = 0,to[i] = i;
        else{
            ok[i] = 1;
            to[i] = to[r[i]];
            f[i] = f[r[i]],g[i] = g[r[i]]+ct[i];
            if(ok[r[i]]){
                if(l[r[i]-1]==i)f[i]+=ct[r[i]-1];
            }
        }
    }
}
inline int jump(int i,int j){
    REP(k,22,0)if(p[k][i]<j)i = p[k][i];
    return i;
}
inline int cal(int i){
    if(i==r[i])return 0;
    int x = r[i],ans = 0;
    if(x==r[x])return 0;
    if(ok[x]){
        if(l[x]!=x-1)ans+=ct[x-1];
        ans+=f[x],x = to[x];
        if(x!=r[x]){
            int p = jump(i,x);
            if(l[r[x]]==x-1&&l[x-1]==p)ans+=ct[x-1]+g[r[x]];
        }
    }
    else{
        if(l[r[x]]==x-1)ans+=ct[x-1]+g[r[x]];
    }
    return ans;
}
inline void solve(){
    readx(n),readx(d);
    FOR(i,1,n)readx(x[i]);
    get_lr();
    init();
    ll ans = 0;
    FOR(i,1,n)ans+=cal(i);
    output(ans),putchar(10);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    readx(c);
    for(readx(T);T--;solve());
    return 0;
}