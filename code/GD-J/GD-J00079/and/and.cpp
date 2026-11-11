#include<bits/stdc++.h>
using namespace std;
#define rep(_1, _2, _3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
typedef long long LL;  typedef unsigned long long ULL;  typedef long double LD; 
const int inf=0x7F7F7F7F, inf2=0x3F3F3F3F; 
const int N=200004, M=0, K=0; 
int n, m, a[N], i;
bool cmp(int x, int y) { if((x&i)!=(y&i)) return y&i;
    else return x<y; }

void initialize() {}

bool __main() {
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    int l=1, ans=0;
    for(i=536870912; i&&n+1-l>=m; i>>=1) { // 536870912 === 2ö29
        sort(a+l, a+n+1, cmp);
        int mid=lower_bound(a+l, a+n+1, ans|i, cmp)-a;
        if(n+1-mid>=m) ans|=i, l=mid; // If we can protect current highest bit
    }
    cout<<ans<<'\n';
    return 0;
}
int main() {
    freopen("and.in", "r", stdin), freopen("and.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  initialize(); 
    int _=1; /* cin>>_; */ for(;_>0;--_) if(__main()) return 0; 
    return 0; 
}