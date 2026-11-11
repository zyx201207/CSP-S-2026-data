#include<bits/stdc++.h>
using namespace std;
const int mxn=200005;
int n,m;
int a[mxn],dp[mxn];
int main(){
    freopen("and3.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j]==0){

                dp[j]=a[i];
            }
            else{
          //      cout<<endl<<i<<' '<<j<<' '<<dp[j]<<' '<<(dp[j]&a[i])<<endl;
//                dp[j]=dp[j]&a[i];
            }
  //          cout<<i<<' '<<j<<' '<<dp[j]<<'|';
        }
    //    cout<<endl;
    }
    int ans=-94942;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}