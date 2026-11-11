#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,dp[222222][222222];
vector<int> v;
int dfs(int x,int idx,int ans){
    if(x==m) return ans;
    if(dp[x][idx]) return dp[x][idx];
    else dp[x][idx]=max(dfs(x,idx+1,ans),dfs(x+1,idx+1,ans=ans&&v[idx]));
    return dp[x][idx];
}
signed main(){
    v.push_back(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<dfs(0,1,1);
    return 0;
}
