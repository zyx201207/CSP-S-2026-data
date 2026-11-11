#include <bits/stdc++.h>
using namespace std;
int n,m,a[200002],ma=-1;
bool vis[200002];
void dfs(int u,int vl){
    if(u+1==m){
        ma=max(vl,ma);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=true;
        dfs(u+1,vl&a[i]);
        vis[i]=false;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vis[i]=true;
        dfs(0,a[i]);
        vis[i]=false;
    }
    cout << ma;
}
