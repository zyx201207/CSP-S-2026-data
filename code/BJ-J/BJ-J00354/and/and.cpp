#include<bits/stdc++.h>
using namespace std;
int dp[200005],a[200005],n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1023;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            dp[i]=max(dp[i-1]&a[j],dp[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
