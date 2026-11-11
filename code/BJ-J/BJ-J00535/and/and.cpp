#include <iostream>
#include <cstdio>
using namespace std;
int a[2001],dp[2001][2001];
int main(){
    int n,m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1)dp[i][j]=a[i];
            dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
