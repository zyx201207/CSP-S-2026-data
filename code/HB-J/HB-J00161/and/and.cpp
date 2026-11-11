#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m;
int a[N];
int dp[N][N];
int ans=0;

void dfs(int x,int step,int now){
    if(step==m){
        ans=max(ans,now);
        //cout<<x-1<<" "<<now<<endl;
        return;
    }
    if(x>n){
        return;
    }
    dfs(x+1,step+1,(now&a[x]));
    dfs(x+1,step,now);
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0]=1073741823;
    }
    dp[0][0]=1073741823;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
        }
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}
