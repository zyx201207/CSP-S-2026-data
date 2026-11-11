//T1:100pts
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10 , M = 1e4 + 10;
long long n,m,sum,head=1,ans=1,a[N];
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;++i){
        sum=sum+(i-head)*(a[i]-a[i-1]);
        // cout<<i-head+1<<' '<<sum<<' ';
        while(sum>m) sum=sum-(a[i]-a[head++]);
        ans=max(ans,i-head+1);
        // cout<<i-head+1<<' '<<sum<<' '<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}