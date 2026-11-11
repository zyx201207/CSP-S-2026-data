#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000006],n,m,dp[200006],ans[200006],book[200006],s=0;
void dfs(int p,int step){
    if(dp[p]==step){
        ans[p]++;
    }else if(dp[p]>step){
        ans[p]=1;
        dp[p]=step;
    }
    for(int v=1;v<=n;v++){
        if(max(a[v]-a[p],a[p]-a[v])<=m&&book[v]==0){
            book[v]=1;
            dfs(v,step+1);
            book[v]=0;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==1||c==2){
        for(int k=1;k<=t;k++){
        s=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[j]=INT_MAX;
            book[j]=0;
            ans[j]=0;
        }
        book[i]=1;
        dfs(i,0);
        for(int j=1;j<=n;j++)if(ans[j]==2)s++;
        //cout<<i<<" "<<s<<endl;
        }
    cout<<s/2<<endl;
    }
    }else{
        for(int i=1;i<=t;i++)cout<<0<<endl;
    }
    
    return 0;
}
