#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[0]|=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j;j--){
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
