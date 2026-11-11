#include <bits/stdc++.h>
using namespace std;
const int mx=2E5+10;
int a[mx],dp[mx],n,m,ans=0;
void pp(){
    for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
    cout<<'\n';
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],dp[i]=a[i];
    int k;
    for(k=2;k<=m;k*=2)
        for(int j=1;j<=n-k+1;j++){
            int ans=dp[j+1]&dp[j];
            for(int i=j+2;i<=n;i++){
                if(i!=j)
                    ans=max(ans,dp[i]&dp[j]);
            }
            dp[j]=ans;
        }
    k=k/2+1;
    for(;k<=m;k++)
        for(int j=1;j<=n-k+1;j++){
            int ans=dp[j+1]&a[j];
            for(int i=j+2;i<=n;i++){
                if(i!=j)
                    ans=max(ans,dp[i]&a[j]);
            }
            dp[j]=ans;
    }
    for(int i=1;i<=n-m+1;i++) ans=max(ans,dp[i]);
    cout<<ans;
	return 0;
}
