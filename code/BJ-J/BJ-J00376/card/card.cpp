#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int dp[5005][3005];
int ans[3005];
map<int,int> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(!mp.count(a[i])){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i+1][j];
            }
            mp[a[i]]=i;
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[mp[a[i]]+1][j];
            }
        }
        dp[i][a[i]]=1;
        for(int j=1;j<=m;j++){
            ans[j]+=dp[i][j];
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}

