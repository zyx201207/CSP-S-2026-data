#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,mx=0;
bool vis[200005];
void dfs(int t,int sum){
    if(t==m+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(t+1,sum&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
    }else if(m==1){
        ans=a[n];
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        ans=mx;
    }else if(n<=20){
        dfs(1,63);
    }else{
        for(int i=n;i>=n-m;i--){
            ans=(ans&a[i]);
        }
    }
    cout<<ans;
    return 0;
}
