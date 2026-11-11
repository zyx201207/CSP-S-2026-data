#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
void dfs(int d,int x){
    if(d==m){
        ans=max(ans,x);
        return;
    }
    if(x<=ans)return;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(d+1,x&a[i]);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(m==1){
        int maxx=0;
        for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
        cout<<maxx;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(1,a[i]);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}
