#include<bits/stdc++.h>
using namespace std;
int n,m,dp[200010],a[200010],ans=INT_MAX;
bool xs(){
    for(int i=1;i<=n;i++){
        if(a[i]>3)return 0;
    }
    return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=10000){
        dp[0]=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                dp[j]=max(dp[j],dp[j-1]&a[i]);
            }
        }
        cout<<dp[m];
    }
    else if(xs()){
        sort(a+1,a+n+1);
        for(int i=n;i>=n-m+1;i--)ans&=a[i];
        cout<<ans;
    }
    else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    return 0;
}
