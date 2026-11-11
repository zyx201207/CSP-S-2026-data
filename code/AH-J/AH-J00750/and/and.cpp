#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
bool vis[200005];
long long maxn[200005];
void dfs(int step,long long res){
    if(step==m+1){
        return ;
    }
    if(maxn[step]>=res)return ;
    maxn[step]=res;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(step==0){
            vis[i]=1;
            dfs(step+1,a[i]);
            vis[i]=0;
        }
        else {
            vis[i]=1;
            dfs(step+1,res&a[i]);
            vis[i]=0;
        }

    }

}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(vis,0,sizeof(vis));
    memset(maxn,-1,sizeof(maxn));
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            a[1]=a[i]&a[1];
        }
        cout<<a[1];
        return 0;
    }
    dfs(0,0);
    cout<<maxn[m];
}
