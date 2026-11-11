#include<bits/stdc++.h>
using namespace std;
#define rep(_1, _2, _3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
typedef long long LL;  typedef unsigned long long ULL;  typedef long double LD; 
const int inf=0x7F7F7F7F, inf2=0x3F3F3F3F; 
const int N=600004, M=0, K=0; 
int n;
struct part { int len; char ch; } a[N]={};

void initialize() {}

bool __main() {
    cin>>n;
    rep(i,1,n) cin>>a[i].len>>a[i].ch;
    LL ans=0;
    for(int i=1, ii=a[1].len, j=n, jj=a[n].len; i<j; ) {
        if(ii<=jj) {
            int len = ii; // The length for jumping
            if(a[i].ch!=a[j].ch) ans+=len; // If the chars are different
            ++i, ii=a[i].len, jj-=len;  if(!jj) --j, jj=a[j].len;
        }
        else {
            int len = jj;
            if(a[i].ch!=a[j].ch) ans+=len;
            --j, jj=a[j].len, ii-=len;  if(!ii) ++i, ii=a[i].len;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
int main() {
    freopen("string.in", "r", stdin), freopen("string.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  initialize(); 
    int _=1; /* cin>>_; */ for(;_>0;--_) if(__main()) return 0; 
    return 0; 
}