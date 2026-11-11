#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
long long ans=-1;
bool vis[200005];
long long road[200005];

void dfs(long long pos,int p,int spe){
    if(pos>=m+1){
        long long t=road[1];
        for(int i=2;i<=m;i++){
            t=t&road[i];
        }
        ans=max(ans,t);
        return;
    }
    if(pos==1){
        vis[spe]=true;
        road[pos]=a[spe];
        dfs(pos+1,spe,spe);
        vis[spe]=false;
    }
    else{
        for(int i=p+1;i<=n;i++){
            if(!vis[i]){
                vis[i]=true;
                road[pos]=a[i];
                dfs(pos+1,i,spe);
                vis[i]=false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        dfs(1,i,i);
    }
    cout <<ans<<endl;
    return 0;
}
