#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void dfs(int c,int p,long long cnt){
    if(n-p<m-c+1){
            return;
    }
    if(c==m+1){
        ans=max(ans,cnt);
        return;
    }
    for(int i=p+1;i<=n;i++){
        if(c==1) dfs(c+1,i,a[i]);
        else dfs(c+1,i,cnt&a[i]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
