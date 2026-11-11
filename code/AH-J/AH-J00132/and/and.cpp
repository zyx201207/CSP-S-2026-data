#include<bits/stdc++.h>
using namespace std;
int dp[2000010],a[2000010],mx=-100;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int g=0;
    for(int i=1;i<=n;i++){
        dp[1]=a[i];
        for(int j=2;j<=n;j++){
            if(i==j){
                continue;
            }
            int t=dp[j-1];
            dp[j]=t&a[j];
            if(dp[j-1]>dp[j]){
               dp[j]=dp[j-1];
            }
            if(dp[j-1]<=dp[j]){
               if(g<m){
                  g++;
               }
            }
        }
        if(g!=m){
            continue;
        }
        mx=max(dp[n],mx);
        memset(dp,0,sizeof(dp));
    }
    cout<<mx<<endl;
    return 0;
}
