#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=5005;
int n,m,ans;
int a[N];
int dp[M][M],pre[N],suf[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1]) f=0;
    }
    if(f){
        cout<<a[1];
        return 0;
    }
    if(m==n-1){
        pre[0]=suf[n+1]=(1ll<<31)-1;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]&a[i];
        }
        for(int i=n;i>=1;i--){
            suf[i]=suf[i+1]&a[i];
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,pre[i-1]&suf[i+1]);
        }
        cout<<ans;
        return 0;
    }
    dp[0][0]=(1ll<<31)-1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=1) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
