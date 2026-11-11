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

const int N=5e5+5;

int n;ll m;
ll a[N],s[N];

void MAIN(){
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n)s[i]=s[i-1]+a[i];
    int ans=0;
    int j=1;
    rep(i,1,n){
        while(a[i]*(i-j+1)-(s[i]-s[j-1])>m)++j;
        chmax(ans,i-j+1);
    }
    cout<<ans<<"\n";
}
int main(){
    FILE("crystal");
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    MAIN();
    return 0;
}