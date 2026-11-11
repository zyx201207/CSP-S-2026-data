#include <bits/stdc++.h>
using namespace std;
int n,m;
long long dp[2005][2][2005];
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    dp[0][0][0]=(1<<31)-1;
    long long mx=-1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0][0]=(1<<31)-1;
        dp[i][1][1]=a[i];
        mx=max(mx,(long long)a[i]);
    }
    if(m==n){
        long long ans=(1<<31)-1;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        cout<<mx<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=n;j++){
            if(j!=i) dp[j][0][i]=max({dp[j][0][i],dp[j-1][0][i],dp[j-1][1][i]});
            if(i!=1) dp[j][1][i]=max({dp[j][1][i],dp[j-1][0][i-1]&a[j],dp[j-1][1][i-1]&a[j]});
            //else dp[j][1][i]=max(dp[j][1][i],dp[j-1][0][i-1]);
        }

    }
    cout<<max(dp[n][0][m],dp[n][1][m])<<endl;
    return 0;
}