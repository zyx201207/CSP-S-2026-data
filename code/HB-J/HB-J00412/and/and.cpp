#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans,maxa;
int a[N];
void dfs(int now,int mans,int cnt){
    if(cnt==m){
        ans=max(ans,mans);
        return;
    }
    for(int i=now+1;i<=n;i++) dfs(i,mans&a[i],cnt+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxa=max(maxa,a[i]);
    }
    if(m==1){
        cout << maxa;
        return 0;
    }
    //int dp[m+5]={a[1]};
    //sort(a+1,a+1+n,greater<int>());
    //int ans=a[1];
    //for(int i=2;i<=m;i++) ans&=a[i];
    //cout << ans;
    //for(int i=1;i<=n;i++){
    //    for(int j=m;j>=1;j--) dp[j]=max(dp[j],dp[j-1]&a[i]);
    //}
    //cout << dp[m];
    if(m==2) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
    else if(m==3) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) ans=max(ans,a[i]&a[j]&a[k]);
    else if(m==4) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int ii=k+1;ii<=n;ii++) ans=max(ans,a[i]&a[j]&a[k]&a[ii]);
    else if(m<=10) for(int i=1;i<=n;i++) dfs(i,a[i],1);
    cout << ans;
    return 0;
}
