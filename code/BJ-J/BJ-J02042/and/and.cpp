#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010],dp[2010][2010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dp[i][1]=max(a[i],dp[i-1][1]);
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1]&a[i],a[i]&dp[i-1][j-1]));
        }
    }
    cout<<dp[n][m];
    return 0;
}
