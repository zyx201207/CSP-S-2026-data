#include<bits/stdc++.h>
using namespace std;using LL=long long;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;LL m;cin>>n>>m;
    vector<LL>a(n);for(LL &x:a)cin>>x;
    sort(a.begin(),a.end());
    vector<LL>sum{0};for(LL x:a)sum.emplace_back(sum.back()+x);
    int ans=0;
    fu(i,0,n){
        auto check=[&](int k){
            return LL(a[i+k-1])*k-(sum[i+k]-sum[i])<=m;
        };
        int l=1,r=n-i;while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid))l=mid;
            else r=mid-1;
        }
        ans=max(ans,l);
    }
    cout<<ans<<endl;
}
//14:49