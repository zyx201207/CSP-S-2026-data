#include<bits/stdc++.h>
using namespace std;
#define rep(_1, _2, _3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
#define reb(_1, _2, _3) for(int _1=(_2), __##_1##__=(_3); _1>=__##_1##__; --_1)
typedef long long LL;  typedef unsigned long long ULL;  typedef long double LD; 
const int inf=0x7F7F7F7F, inf2=0x3F3F3F3F; 
const int N=500004, M=300004, K=0; 
int n, m, a[N], lst[N], go[N];
int sum[N], ct[N], ad[N];
void PB(vector<int>&_1, int _2) {// factor === 1.5 (ceil)
    if(_1.size()==_1.capacity() && _1.size()>1) _1.reserve((_1.size()<<1)-(_1.size()>>1));
    _1.push_back(_2);
}

void initialize() {}

bool __main() {
    cin>>n>>m;
    rep(i,1,n) { cin>>a[i];  go[lst[a[i]]]=i, lst[a[i]]=i, ct[i]=1; }
    go[0]=0; // Don't forget to reset @go[0]
    reb(i,n,1) if(go[go[i]]) go[i]=go[go[i]];
    rep(i,1,n) if(!go[i]) ad[i]=a[i], go[i]=i+1;
    rep(i,1,n) ct[go[i]]+=ct[i];
    rep(i,1,n) sum[ad[i]]+=ct[i];
    rep(i,1,m) cout<<sum[i]<<' ';
    return 0;
}
int main() {
    freopen("card.in", "r", stdin), freopen("card.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  initialize(); 
    int _=1; /* cin>>_; */ for(;_>0;--_) if(__main()) return 0; 
    return 0; 
}
