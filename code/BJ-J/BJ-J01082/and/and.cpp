#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[1000001],l[200001],r[200001],hd=1,ta;
bool vis[200001];
int dp[2001][2001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        dp[i][0]=2147483647;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
