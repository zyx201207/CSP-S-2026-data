#include<bits/stdc++.h>
using namespace std;  typedef long long LL; 
#define rep(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
#define reb(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1>=__##_1##__; --_1)
const int N=500004, M=0, K=0; 
int n;  LL m, a[N], ps[N];
int Search(int x) {
    int l=x, r=n;
    while(l<r) { // Current range: (@l, @r] ([@l+1, @r])
        int mid=(l+1+r)>>1;
        if((mid-x)*a[mid]-ps[mid-1]+ps[x-1]<=m) l=mid;
        else r=mid-1;
    }
    return l;
}

bool __main() {
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1, a+n+1), ps[1]=a[1];
    rep(i,2,n) ps[i]=a[i]+ps[i-1];
    int ans=0;
    rep(i,1,n) {
        // Find the biggest int @#j in range [@i, @n] satisfied: ·(@#•=@i, @#j-1, @a[@#j]-@a[@#•])²@m   \
           ·(@#•=@i, @#j-1, @a[@#j]-@a[@#•]) === (@#j-@i)*@a[@#j] - ·(@#•=@i, @#j-1, @a[@#•]) === (@#j-@i)*@a[@#j] - @ps[@#j-1] + @ps[@i-1]   \
           So we find the biggest int @#j satisfied (@#j-@i)*@a[@#j] - @ps[@#j-1] + @ps[@i-1]²@m
        int j=Search(i);
        ans=max(ans, j-i+1);
    }
    cout<<ans<<'\n';
    return 0;
}

int main() {
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
    int _=1; /* cin>>_; */ for(; _>0; --_) if(__main()) return 0;
    return 0;
}