#include<bits/stdc++.h>
using namespace std;
long long m,n,a[20005],maxn,vis[20005];
int dfs(long long u,long long l){
    if(l==m){
        maxn=max(maxn,u);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(l==0){
                vis[i]=1;
                dfs(a[i],1);
                vis[i]=0;
            }else{
                vis[i]=1;
                dfs(a[i]&u,l+1);
                vis[i]=0;
            }
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
    cout<<maxn;
    return 0;
}
