#include<iostream>
using namespace std;
int n,m,a[200010],vis[200010],ans=-0x3f3f3f3f;
void dfs(int cur,int l){
    if(l==0){
        ans=max(ans,cur);
        return;
    }
    if(cur<=ans) return;

    for(int i=1;i<=n;i++) if(vis[i]==0&&a[i]>ans) vis[i]=1,dfs(cur&a[i],l-1),vis[i]=0;
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) vis[i]=1,dfs(a[i],m-1),vis[i]=0;

    cout<<ans<<endl;

    return 0;
}