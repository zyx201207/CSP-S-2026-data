#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,l=1;
long long a[10086];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<long long>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<long long>dp(n+1,0);
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1]+a[i];
    }
    l=1;
    for(int r=1;r<=n;++r){
        long long res=(r-l+1)*a[r]-(dp[r]-dp[l-1]);
        while(res>m){
            l++;
            res=(r-l+1)*a[r]-(dp[r]-dp[l-1]);
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
