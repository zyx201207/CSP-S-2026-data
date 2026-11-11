#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[5010],dis[5010][5010],res,ans=0,vis[5010];
void dfs1(int y,int s,int e,int cnt){
    if(cnt>dis[s][e])return;
    if(y==e){
        dis[s][e]=min(dis[s][e],cnt);
        return;
    }
    for(int i=y+1;i<=e;i++){
        if(abs(x[i]-x[y])>d)break;
        if(vis[i])continue;
        vis[i]=true;
        dfs1(i,s,e,cnt+1);
        vis[i]=false;
    }
}
void dfs2(int y,int s,int e,int cnt){
    if(y==e){
        res+=(cnt==dis[s][e]);
        return;
    }
    for(int i=y+1;i<=e;i++){
        if(abs(x[i]-x[y])>d)break;
        if(vis[i])continue;
        vis[i]=true;
        dfs2(i,s,e,cnt+1);
        vis[i]=false;
    }
}
inline void solve(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dfs1(i,i,j,0);
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            memset(vis,0,sizeof(vis));
            res=0;
            vis[i]=true;
            dfs2(i,i,j,0);
            ans+=(res==2);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
