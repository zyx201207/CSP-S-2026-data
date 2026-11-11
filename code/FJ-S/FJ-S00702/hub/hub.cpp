#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i = (a);i <= (b);++i)
#define REP(i,a,b) for(int i = (a);i >= (b);--i)
#define GO(x) for(int i = h[x],y = e[i];i;y = e[i=ne[i]])
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
const int N = 1e3+10,nf = 1e9+10;
static int c,T,n,k,e[N<<1],ne[N<<1],h[N],tot,dis[N][N];
static bool in[N];
inline void add(int x,int y){
    e[++tot] = y,ne[tot] = h[x],h[x] = tot;
}
void dfs(int x,int fr,int *d){
    GO(x)if(y^fr)d[y] = d[x]+1,dfs(y,x,d);
}
inline void ckmax(int &x,int y){
    x<y&&(x=y);
}
inline void ckmin(int &x,int y){
    x>y&&(x=y);
}
inline void get_dis(){
    FOR(i,1,n)dfs(i,0,dis[i]);
}
inline int cal(int S){
    int ctp,cte,ans,tmp;
    if((ctp=__builtin_popcount(S))>k)return nf;
    FOR(i,1,n)in[i] = (S>>i-1)&1;
    cte = 0;
    FOR(x,1,n)if(in[x]){GO(x)cte+=in[y];}
    cte/=2;
    if(ctp-cte>2)return nf;
    ans = 0;
    FOR(x,1,n){
        tmp = nf;
        FOR(i,1,n)if(in[i])ckmin(tmp,dis[x][i]);
        ckmax(ans,tmp);
    }
    return ans;
}
inline void solve(){
    int tx,ty,ans = nf;
    readx(n),readx(k);
    FOR(i,2,n)readx(tx),readx(ty),add(tx,ty),add(ty,tx);
    get_dis();
    FOR(s,0,(1<<n)-1)ckmin(ans,cal(s));
    output(ans),putchar(10);

    FOR(i,1,n)h[i] = 0;tot = 0;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    readx(c);
    for(readx(T);T--;solve());
    return 0;
}