#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,m,a[N];
int dp[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=1;j--){
            for(int k=1;k<=j;k++){
                dp[j]=max(dp[j],dp[j-k]&dp[j]);
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
