#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1ll){
        long long ans=0;
        for(long long i=1ll;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }else if(m==n){
        long long ans=a[1];
        for(long long i=2ll;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else if(n<=2000ll&&m==2ll){
        long long ans=0;
        for(int i=1ll;i<=n;i++){
            for(int j=i+1ll;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(n<=2000ll){
        for(long long i=1ll;i<=n;i++){
            dp[i][1]=max(dp[i-1][1],a[i]);
            for(long long j=2ll;j<=min(i,m);j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
            }
        }
        cout<<dp[n][m];
    }
    cout<<endl;
    return 0;
}
