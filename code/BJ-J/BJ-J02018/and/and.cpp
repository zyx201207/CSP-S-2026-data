#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn],vis[maxn];
int maxx=0;
void dfs(int n,int m,int cnt,int res){
    if(cnt==m){ 
        maxx=max(maxx,res);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(n,i,cnt+1,res&a[i]);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
        cout<<maxx<<'\n';
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx<<'\n';
        return 0;
    }
    if(m==n){
        maxx=a[1];
        for(int i=2;i<=n;i++) maxx=maxx&a[i];
        cout<<maxx<<'\n';
        return 0; 
    }
    for(int i=1;i<=n;i++){
        dfs(n,m,1,a[i]);
    }       
    cout<<maxx<<'\n';
    return 0;
}