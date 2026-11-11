#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[20010];
int maxx=-1;
void dfs(int xh,int sl,int cur){
    if(sl==m){
        maxx=max(maxx,cur);
        return ;
    }
    for(int i=xh+1;i<=n-m+sl+1;i++){
        dfs(i,sl+1,cur&a[i]);
    }
}
signed main(){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        dfs(i,1,a[i]);
    }
    cout<<maxx;
    return 0;
}
