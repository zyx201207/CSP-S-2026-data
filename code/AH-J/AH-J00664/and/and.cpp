#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],mx,dp[2005][2005];
bool flag;
signed main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
int x=1;
for(int i=1;i<=n;i++){
    cin>>a[i];
    x&=a[i];
    mx=max(mx,a[i]);
    if(a[i]!=i-1) flag=1;
}
if(m==1){
    cout<<mx;
    return 0;
}else if(n==m){
    cout<<x;
    return 0;
}else if(flag==0){
    int ans=1;
    for(int i=n;i>=n-m+1;i--){
        ans&=a[i];
    }
    cout<<ans;
}else if(n<=2000){
    for(int i=1;i<=n;i++) dp[i][1]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=2;j<=min(i,m);j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m];
}else{
    int ans=1;
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m+1;i--) ans&=a[i];
    cout<<ans;
}
return 0;
}
