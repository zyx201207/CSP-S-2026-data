#include<bits/stdc++.h>
// #define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define us(n) (1ll<<(n))
#define si(V) (int)(V).size()
#define I(i,l,r) for(auto i=(l);i<(r);++i)
#define O(i,l,r) for(auto i=(l);i<=(r);++i)
#define U(i,r,l) for(auto i=(r);i>=(l);--i)
#define For(e,V) for(const auto &e:(V))

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;

template<typename T> T& omax(T &a,T b) { return a=max(a,b); }
template<typename T> T& omin(T &a,T b) { return a=min(a,b); }

bool bgM;

char gc() {
    static char buf[us(20)],*p1,*p2;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,us(20),stdin),p1==p2)?EOF:*p1++;
}
ll ri() {
    ll x=0; char c; bool f=0;
    while(c=gc(),!isdigit(c)) if(c=='-') f=1;
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
    return f?-x:x;
}
char rc() { char c; while(c=gc(),isspace(c)); return c; }

const int M=998244353;
struct mint {
    int x;
    constexpr mint():x(0) {}
    constexpr mint(ll v):x(0) { x=v%M; if(x<0) x+=M; }
    constexpr mint& operator+=(mint a) { if((x+=a.x)>=M) x-=M; return *this; }
    constexpr mint& operator-=(mint a) { if((x-=a.x)<0) x+=M; return *this; }
    constexpr mint& operator*=(mint a) { x=(ll)x*a.x%M; return *this; }
    constexpr friend mint operator+(mint a,mint b) { return a+=b; }
    constexpr friend mint operator-(mint a,mint b) { return a-=b; }
    constexpr friend mint operator*(mint a,mint b) { return a*=b; }
    constexpr friend mint Pow(mint a,ll b) { mint x=1; for(;b;b>>=1,a*=a) if(b&1) x*=a; return x; }
    constexpr friend mint Inv(mint a) { return Pow(a,M-2); }
    friend ostream& operator<<(ostream &o,mint a) { return o<<a.x; }
} ;

const int inf=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3f;

namespace _ {
int n; ll m;
const int Mn=5e5+10;
ll a[Mn];
ll sm[Mn];
bool chk(int L) {
    O(i,1,n-L+1) {
        int p=i+L-1;
        if(a[p]*(p-i)-(sm[p-1]-sm[i-1])<=m) {
            return 1;
        }
    }
    return 0;
}

void _() {
    n=ri(); m=ri();
    O(i,1,n) a[i]=ri();
    sort(a+1,a+n+1);
    O(i,1,n) sm[i]=sm[i-1]+a[i];
    int res=0;
    for(int l=1,r=n,mid;l<=r;) {
        mid=l+r>>1; 
        (chk(mid))?(l=mid+1,res=mid):(r=mid-1);
    }
    cout<<res<<endl;
}

void _start() {

}

}

bool edM;

signed main() {
    // freopen("in.txt","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    // cerr<<"Memory: "<<fabs(&bgM-&edM)/1024/1024<<"MB"<<endl;
    int T=1;
    _::_start();
    O(i,1,T) {
        _::_();
    }
    // cerr<<"Time: "<<(double)clock()<<"ms"<<endl;
    return 0;
}

/*
g++ crystal.cpp -o a -std=c++14 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC "-Wl,--stack=1000000000" -Wall -Wextra && a <in.txt >out.txt 2>err.txt
g++ crystal.cpp -o a -std=c++14 -O2 -Wall -Wextra "-Wl,--stack=1000000000" && a <in.txt >out.txt 2>err.txt
*/