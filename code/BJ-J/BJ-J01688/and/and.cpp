#include<bits/stdc++.h>
using namespace std;
int n,m,k=0;
long long a[200111],dp[2001][2001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k=max(k,a[i]);
    
        dp[i][1]=a[i];
    }
    if(m==1){
        cout<<k;
        return 0;
    }
    for(int j=2;j<=m;j++){
       for(int i=m;i<=n;i++){
          dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
    }
    }
    cout<<dp[n][m];
    return 0;
}

