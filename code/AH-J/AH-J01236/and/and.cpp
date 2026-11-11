#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long maxx;
bool vis[200005];
void dfs(int k,long long cnt){
    if(k==m){
        maxx=max(maxx,cnt);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(k+1,(cnt&a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0xffffffff);
    cout<<maxx;
    return 0;
}
