#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   long long n,m,a[1000000],dp[1000000],ma=-1;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]>ma){
        ma=a[i];
    }
   }
 for(int i=1;i<=n;i++){
    dp[2]=max(dp[i-1],a[i]&ma);
 }
   for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1]&a[i],dp[i-1]);
    }
   cout<<dp[m];
return 0;
}
