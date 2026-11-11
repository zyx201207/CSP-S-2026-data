#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],maxn;
void dfs(int sum,int cnt){
    if(cnt==m) maxn=max(maxn,sum);
    if(cnt<m){
        for(int i=1;i<=n;i++){
            vis[i]++;
            if(vis[i]<=1) dfs(sum&a[i],cnt+1);
            vis[i]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    maxn=0;
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(a[i],1);
        memset(vis,0,sizeof(vis));
    }
    cout<<maxn;
    return 0;
}
