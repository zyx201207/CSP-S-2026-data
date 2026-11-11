#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],dp[200001];
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i] = a[i];
        for(int j=2;j<=n-i+1;j++){
            dp[i] = max(dp[i],dp[i]&a[j]);
            dp[i+1] = max(dp[i+1],dp[i]);
        }
    }
    cout<<dp[n];

    return 0;
}
