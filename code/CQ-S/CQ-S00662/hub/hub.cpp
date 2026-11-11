#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define fir first
#define sec second
#define pub push_back
#define pob pop_back
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define repl(i,x,y) for(int i=(x);i<(y);++i)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define FILE(f) freopen(f".in","r",stdin),freopen(f".out","w",stdout)
template<typename T> using vec=vector<T>;
template<typename T> using grheap=priority_queue<T>;
template<typename T> using lrheap=priority_queue<T,vec<T>,greater<T>>;
#define il inline

constexpr int inf=0x3f3f3f3f;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;

constexpr int mod=998244353;
il ll qpow(ll a,ll b){
    ll res=1;
    for(;b;b>>=1){
        if(b&1)res*=a,res%=mod;
        a*=a,a%=mod;
    }return res;
}
struct mint{
    int x;
    mint(ll v=0){x=v%mod,x<0&&(x+=mod);}
    il mint operator+=(mint v){return x+=v.x,x>=mod&&(x-=mod),*this;}
    il mint operator-=(mint v){return x-=v.x,x<0&&(x+=mod),*this;}
    il mint operator*=(mint v){return x=1ll*x*v.x%mod,*this;}
    il mint operator/=(mint v){return x=1ll*x*qpow(v.x,mod-2)%mod,*this;}
    friend il mint operator+(mint a,mint b){return a+=b;}
    friend il mint operator-(mint a,mint b){return a-=b;}
    friend il mint operator*(mint a,mint b){return a*=b;}
    friend il mint operator/(mint a,mint b){return a/=b;}
    friend il bool operator<(mint a,mint b){return a.x<b.x;}
    friend il bool operator==(mint a,mint b){return a.x==b.x;}
};

const int N=4000+5;

int n,k;
int ecnt,hd[N],to[N<<1],ne[N<<1];
il void adde(int x,int y){
    int e=++ecnt;
    ne[e]=hd[x],to[e]=y,hd[x]=e;
}
int dp[N],fa[N],son[N],tp[N];
int dcnt,dfn[N],nfd[N];
void dfs0(int x){
    dp[x]=1;
    for(int e=hd[x];e;e=ne[e]){
        int y=to[e];
        if(y!=fa[x])fa[y]=x,dfs0(y),chmax(dp[x],dp[y]+1),dp[y]>dp[son[x]]&&(son[x]=y);
    }
}
void dfs1(int x,int top){
    nfd[dfn[x]=++dcnt]=x;
    tp[x]=top;
    if(son[x])dfs1(son[x],top);
    for(int e=hd[x];e;e=ne[e]){
        int y=to[e];
        if(y!=fa[x]&&y!=son[x])dfs1(y,y);
    }
}
int f[N][3][2][N],t[3][2][N];
// vec<int> f[N][3][2];
// vec<int> t[3][2];
il bool check(int lim){
    per(I,dcnt,1){
        int X=nfd[I];
        if(tp[X]!=X)continue;
        per(J,I+dp[X]-1,I){
            int x=nfd[J];
            int tdp=1;
            rep(a,0,2)rep(b,0,1)repl(i,0,tdp)f[x][a][b][i]=inf;
            // rep(a,0,2)rep(b,0,1)f[x][a][b].assign(tdp,inf);
            f[x][0][1][0]=0,f[x][1][0][0]=1;
            for(int e=hd[x];e;e=ne[e]){
                int y=to[e];if(y==fa[x])continue;
                int T=max(tdp,dp[y]+1);
                rep(a,0,2)rep(b,0,1)repl(i,0,T)t[a][b][i]=inf;
                // rep(a,0,2)rep(b,0,1)t[a][b].assign(max(tdp,dp[y]+1),inf);
                {//当前关键
                    rep(ax,1,2)rep(ay,0,2){
                        //子树 ALLOK
                        if(ax+ay-1<=2)chmin(t[ax+ay-1][0][0],f[x][ax][0][0]+f[y][ay][0][0]);
                        if(ax+ay<=2)repl(l,1,dp[y])chmin(t[ax+ay][0][0],f[x][ax][0][0]+f[y][ay][0][l]);
                        //子树 no
                        if(ax+ay<=2)repl(l,0,min(lim,dp[y]))chmin(t[ax+ay][0][0],f[x][ax][0][0]+f[y][ay][1][l]);
                    }
                }{//当前不关键
                    //当前 ALLOK
                    rep(ax,1,2)repl(i,1,tdp)rep(ay,0,2){
                        //子树 ALLOK
                        if(ax+ay<=2)repl(j,0,dp[y])chmin(t[ax+ay][0][min(i,j+1)],f[x][ax][0][i]+f[y][ay][0][j]);
                        //子树 no
                        if(ax+ay<=2){
                            repl(j,0,min(lim+1-(i+1),dp[y]))chmin(t[ax+ay][0][i],f[x][ax][0][i]+f[y][ay][1][j]);
                            repl(j,lim+1-(i+1),dp[y])chmin(t[ax+ay][1][j+1],f[x][ax][0][i]+f[y][ay][1][j]);
                        }
                    }
                    //当前 no
                    rep(ax,0,2)repl(i,0,tdp)rep(ay,0,2){
                        //子树 ALLOK
                        if(ax+ay<=2){
                            repl(j,0,min(lim+1-i-1,dp[y]))chmin(t[ax+ay][0][j+1],f[x][ax][1][i]+f[y][ay][0][j]);
                            repl(j,lim+1-(i+1),dp[y])chmin(t[ax+ay][1][i],f[x][ax][1][i]+f[y][ay][0][j]);
                        }
                        //子树 no
                        if(ax+ay<=2)repl(j,0,dp[y])chmin(t[ax+ay][1][max(i,j+1)],f[x][ax][1][i]+f[y][ay][1][j]);
                    }
                }
                chmax(tdp,dp[y]+1);
                rep(a,0,2)rep(b,0,1)repl(i,0,tdp)f[x][a][b][i]=t[a][b][i];
                // rep(a,0,2)rep(b,0,1)f[x][a][b].swap(t[a][b]),vec<int>().swap(f[y][a][b]);
                    // cerr<<"aaa\n";
            }
            // rep(a,0,2)rep(b,0,1)repl(i,0,dp[x])cerr<<x<<" "<<a<<" "<<b<<" "<<i<<" : "<<f[x][a][b][i]<<"\n";
        }
    }
    // cerr<<"end\n";
    rep(a,0,2)repl(i,0,dp[1])if(f[1][a][0][i]<=k)return 1;
    return 0;
}

void MAIN(){
    cin>>n>>k;
    ecnt=0;rep(i,1,n)hd[i]=0;
    rep(i,2,n){int x,y;cin>>x>>y;adde(x,y),adde(y,x);}
    rep(i,1,n)son[i]=0;
    dcnt=0;
    dfs0(1),dfs1(1,1);
    int l=0,r=n;
    while(l<r){
        int m=l+r>>1;
        if(check(m))r=m;
        else l=m+1;
    }
    cout<<l<<"\n";
}
int main(){
    FILE("hub");
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--)MAIN();
    return 0;
}