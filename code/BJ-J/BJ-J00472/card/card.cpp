#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<long long>dp(n+1);
    vector<long long>a(n+1),b(n+1);
    dp[1]=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b[i]++;
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=m;j++){
            long long k=i-1;
            dp[j]=max(dp[j],b[a[i]]+dp[i]);
            dp[i]=max(dp[i],dp[j]);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
