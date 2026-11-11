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

const int N=2e6+5;

int n;ll d;
ll x[N];
int to[N];
ll f[N],g[N],h[N];

void MAIN(){
    cin>>n>>d;
    rep(i,1,n)cin>>x[i];
    for(int i=n-1,j=to[n]=n;i>=1;--i){
        while(x[j]-x[i]>d)--j;
        to[i]=j;
    }
    per(i,n,2){
        if(to[i]==i){f[i]=g[i]=h[i]=0;continue;}
        g[i]=to[i]-max(to[i-1],i);if(to[i-1]<to[i])g[i]+=g[to[i]];
        h[i]=to[i-1]==to[i]?0:to[i-1]==to[i]-1?h[to[i]]:f[to[i]];
        if(i>2&&to[i-2]>i){
            f[i]=to[i-1]-to[i-2];
            if(to[i-2]==to[i])continue;
            f[i]+=(to[i-1]==to[i]?g[to[i]]:to[i-1]==to[i]-1?h[to[i]]:f[to[i]]);
            // f[i]+=(to[i-1]<to[i]?f[to[i]]:g[to[i]]);
        }else{
            f[i]=max(i,to[i-1])-i;
            // if(i==5)cerr<<f[i]<<" ff\n";
            f[i]+=(to[i-1]==to[i]?g[to[i]]:to[i-1]==to[i]-1?h[to[i]]:f[to[i]]);
        }
    }
    // rep(i,1,n){cerr<<i<<" ::: ";rep(j,1,n)cerr<<(~dis(i,j)?dis(i,j):0)<<" ";cerr<<"\n";}
    // rep(i,1,n)cerr<<i<<" : "<<f[i]<<" "<<g[i]<<" "<<h[i]<<"\n";
    ll ans=0;
    repl(i,1,n)if(to[i]>i)ans+=f[to[i]];
    cout<<ans<<"\n";
}
int main(){
    FILE("migrate");
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--)MAIN();
    return 0;
}