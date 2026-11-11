#include <bits/stdc++.h>
using namespace std;
int n,a[200010],m,ans=0,vis[200010],sum=(1<<30)-1,b[200010];
void dfs(int u){
    if(u==m+1){
        for(int i=1;i<=m;i++){
             if(i==1) sum=b[i];
             else sum=(sum&b[i]);
        }
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            b[u]=a[i];
        }
        else continue;
        dfs(u+1);
        vis[i]=0;
        b[u]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
