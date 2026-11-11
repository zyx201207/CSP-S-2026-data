#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,m;
int arr[200005];
int a[200005];
bool vis[200005];
void dfs(int x,int c){
    if(c==m+1){
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=m;i++){
            if(!vis[a[i]]) vis[a[i]]=true;
            else return;
        }
        long long sum=a[1];
        for(int i=2;i<=m;i++) sum&=a[i];
        ans=max(ans,sum);
        return;
    }
    for(int i=x;i<=n;i++){
        a[x]=arr[i];
        dfs(x+1,c+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}
