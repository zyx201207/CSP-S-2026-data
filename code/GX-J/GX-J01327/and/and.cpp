#include<bits/stdc++.h>
using namespace std;
int n,m,a[(int)2e5+1],maxv=-1;
bool vis[(int)2e5+1];
void dfs(int sel,int val){
    if(sel==m){
        maxv=max(maxv,val);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(sel+1,val&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,(1<<31)-1);
    cout<<maxv;
    return 0;
}

