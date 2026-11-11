#include<bits/stdc++.h>
using namespace std;
int a[2000005],dp[2000005],f[2000005];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=INT_MAX;
    }
    dp[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]>m){
                break;
            }
            else if(dp[i]+1<dp[j])f[j]=1,dp[j]=dp[i]+1;
            else if(dp[i]+1==dp[j])f[j]++;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i]==2)cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
