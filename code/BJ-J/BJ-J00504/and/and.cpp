#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
bool vis[N];
void dfs(int step,int sum){
    if(step==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(step==0){
                dfs(step+1,a[i]);
            }else{
                dfs(step+1,sum&a[i]);
            }
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
    dfs(0,0);
    cout<<ans;
    return 0;
}