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
const int N = 5e5+10,M = 5e2+10;
const ll lnf = 1e18+10;
static int c,n,m,d,q,w[N];
static ll f[M][M];
struct node{
    int id,t;
};
static ve<node> p[N];
inline void ckmin(ll &x,ll y){
    x>y&&(x=y);
}
inline void get_f(){
    //init_f
    //get_f
    //dp
    FOR(i,1,n)FOR(j,1,n)if(i!=j)f[i][j] = lnf;
    FOR(i,1,m){
        for(auto &t0:p[i])
            for(auto &t1:p[i])
                ckmin(f[t0.id][t1.id],0ll+t0.t+t1.t);
    }
    FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)ckmin(f[i][j],f[i][k]+f[k][j]);
}
inline ll qy(int x,int y){
    ll ans = lnf;
    for(auto &t0:p[x])for(auto &t1:p[y])ckmin(ans,t0.t+t1.t+f[t0.id][t1.id]);
    if(ans==lnf)fprintf(stderr,"qy_err\n"),exit(0);
    return ans+w[x]+w[y];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //rd
    //get_f
    //get_qy
    int len,x,t;
    readx(c),readx(n),readx(m),readx(d),readx(q);
    FOR(i,1,m)readx(w[i]);
    FOR(i,1,n){
        readx(len);
        FOR(j,1,len)readx(x),readx(t),p[x].pb((node){i,t});
    }
    get_f();
    FOR(i,1,q){
        readx(x),readx(t);
        output(qy(x,t)),putchar(10);
    }
    return 0;
}