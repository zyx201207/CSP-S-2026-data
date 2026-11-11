#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int a[N],dp[N][N],ans;
int n,m;
/*
void dfs(int t,int k,int cnt){
    if(k>n-m) return;
    if(cnt==m){
        ans=max(ans,t);
        return;
    }
    for(int i=k;i<=n;i++){
        dfs(t&a[i],i,cnt+1);
    }
    return;
}
*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //dfs(a[i],i,0);
    }
    dp[1][1]=a[1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dp[max(i,j)][2]=max(dp[max(i,j)][2],a[i]&a[j]);
        }
        dp[i][i]=dp[i-1][i-1]&a[i];
    }
    for(int j=3;j<=m;j++){
        for(int i=2;i<=n;i++){
            dp[i][j]=max(dp[i-1][j-1]&a[i],max(dp[i-1][j],dp[i][j]));
        }
    }
    cout<<dp[n][m];
    return 0;
}
