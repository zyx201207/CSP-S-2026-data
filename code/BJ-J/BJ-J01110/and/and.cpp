#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=INT_MIN;
long long dp[200010];
long long a[200010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+1+n,cmp);
    for(int k=1;k<=n;k++){
        memset(dp,0,sizeof dp);
        dp[0]=a[k];
        for(long long i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                dp[j]=max(dp[j],dp[j-1]&a[i]);
            }
        }ans=max(ans,dp[m]);
    }
    cout<<ans;
    return 0;
}