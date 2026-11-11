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
#define X(x) (cerr<<__LINE__<<": "<<#x<<" = "<<x<<endl)

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
int testid;
int n; ll d;
const int Mn=2e6+10;
ll a[Mn];
int L[Mn],R[Mn];
ll pre[Mn],suf[Mn];
int cl[Mn],cr[Mn];

void _() {
    n=ri(); d=ri();
    O(i,1,n) a[i]=ri();
    O(i,1,n) L[i]=R[i]=0,pre[i]=suf[i]=0,cl[i]=cr[i]=0;
    {
        int j=1; O(i,1,n) { for(;a[i]-a[j]>d;j++); L[i]=j; }
    }
    {
        int j=n; U(i,n,1) { for(;a[j]-a[i]>d;j--); R[i]=j; }
    }
    O(i,1,n) {
        if(R[i]>i) {
            if(L[R[i]]==i) {
                pre[R[i]]+=pre[i]+1;
            } else {
                pre[R[i]]+=1;
            }
        }
    }
    U(i,n,1) {
        if(L[i]<i) {
            if(R[L[i]]==i) {
                suf[L[i]]+=suf[i]+1;
            } else {
                suf[L[i]]+=1;
            }
        }
    }
    ll ans=0;
    O(i,1,n) {
        if(R[i]>i&&R[R[i]]>R[i]) {
            int x=i,y=R[i],z=R[y];
            if(L[z]!=y&&L[z]==y-1) {
                if(L[L[z]]==x) {
                    ans+=(ll)(pre[x]+1)*(suf[z]+1);
                } else {
                    ans+=suf[z]+1;
                }
            }
        }
    }
    O(i,1,n) {
        if(L[i]<i&&L[L[i]]<L[i]) {
            int x=i,y=L[i],z=L[y];
            if(R[z]!=y&&R[z]==y+1) {
                if(R[R[z]]!=x) {
                    ans+=pre[z]+1;
                }
            }
        }
    }
    // O(i,1,n) O(j,i+1,n) {
    //     if(R[i]>i&&R[R[i]]>R[i]&&L[j]<j&&L[L[j]]<L[j]&&R[i]==L[j]+1&&R[R[i]]>j&&L[L[j]]<i&&R[i]<j&&L[j]>i) {
    //         ans++;
    //     }
    // }
    O(i,1,n) if(L[i]<i) cl[L[i]]++;
    O(i,1,n) if(R[i]>i) cr[R[i]]++;
    O(i,1,n-1) {
        int a=L[i],b=i,c=i+1,d=R[i+1];
        if(a<b&&b<c&&c<d) {
            ans+=(ll)(cr[c]-(R[a]==c)-(R[b]==c))*(cl[b]-(L[d]==b)-(L[c]==b));
        }
    }
    cout<<ans<<endl;
}

void _start() {

}

}

bool edM;

signed main() {
    // freopen("in.txt","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    // cerr<<"Memory: "<<fabs(&bgM-&edM)/1024/1024<<"MB"<<endl;
    _::testid=ri();
    int T=ri();
    _::_start();
    O(i,1,T) {
        _::_();
    }
    // cerr<<"Time: "<<(double)clock()<<"ms"<<endl;
    return 0;
}

/*
g++ migrate.cpp -o a -std=c++14 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC "-Wl,--stack=1000000000" -Wall -Wextra && a <in.txt >out.txt 2>err.txt
g++ migrate.cpp -o a -std=c++14 -O2 -Wall -Wextra "-Wl,--stack=1000000000" && a <in.txt >out.txt 2>err.txt
*/