#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,vis[200005],sum,cnt=1;
void dfs(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++){
            if(vis[i]){
                sum++;
            }
        }
        if(sum!=m){
            sum=0;
            return;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                cnt=cnt&a[i];
            }
        }
        ans=max(ans,cnt);
        cnt=1;
        return;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
