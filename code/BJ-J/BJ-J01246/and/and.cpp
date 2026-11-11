#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int n,m;
int ans;
void dfs(int cur,int y){
    if(cur>m){
        ans=max(ans,y);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=true;
        if(cur==1)dfs(cur+1,a[i]);
        else dfs(cur+1,y&a[i]);
        vis[i]=false;
    }
}
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    if(n<=12){
        dfs(1,0);
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    ans=a[n];
    for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
    cout<<ans;
    return 0;
}