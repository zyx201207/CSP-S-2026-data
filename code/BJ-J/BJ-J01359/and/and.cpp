#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[200010];
void dfs(int x,int y,int z) {
    if(z==m) {
        ans=max(ans,y);
        return ;
    }
    if(y<=ans&&y!=-1) {
        return ;
    }
    if(x>n) {
        return ;
    }
    if(y==-1) {
        dfs(x+1,a[x],z+1);
    }
    else {
        dfs(x+1,y&a[x],z+1);
    }
    dfs(x+1,y,z);
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dfs(1,-1,0);
    cout<<ans;
    return 0;
}
