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

const int N=505,M=5e5+5,D=25;

int n,m,d,q;
ll w[M];
int k[N];
int dg[M];
int to[M][D];ll tv[M][D];
ll dis[N][N];

void MAIN(){
    cin>>n>>m>>d>>q;
    rep(i,1,m)cin>>w[i];
    rep(i,1,n){
        cin>>k[i];
        rep(I,1,k[i]){
            int a,t;cin>>a>>t;
            ++dg[a];
            to[a][dg[a]]=i,tv[a][dg[a]]=t;
        }
    }
    rep(i,1,n)rep(j,1,n)dis[i][j]=INF;
    rep(i,1,n)dis[i][i]=0;
    rep(i,1,m){
        rep(x,1,dg[i])rep(y,x+1,dg[i])
            chmin(dis[to[i][x]][to[i][y]],tv[i][x]+tv[i][y]),
            chmin(dis[to[i][y]][to[i][x]],tv[i][x]+tv[i][y]);
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)chmin(dis[i][j],dis[i][k]+dis[k][j]);
    rep(i,1,q){
        int x,y;cin>>x>>y;
        ll ans=INF;
        rep(a,1,dg[x])rep(b,1,dg[y])chmin(ans,dis[to[x][a]][to[y][b]]+tv[x][a]+tv[y][b]);
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
int main(){
    FILE("subway");
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c;cin>>c;
    MAIN();
    return 0;
}