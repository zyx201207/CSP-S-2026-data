#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
//#define int long long
int w[500001];
int k[500001];
int a[1001][1001],t[1001][1001];
bool vis[500001];
int ans=1e9+1;
void dfs(int x,int y,int now,int cnt){
    if(now==y){
        ans=min(ans,cnt);
        return;
    }
    for(int i=1;i<=k[now];i++){
        if(!vis[a[now][i]]){
            vis[a[now][i]]=1;
            if(a[now][i]!=y)dfs(x,y,a[now][i],cnt+t[now][a[now][i]]+t[a[now][i]][a[now][i]]);
            else dfs(x,y,a[now][i],cnt+t[now][i]);
            vis[a[now][i]]=0;
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
       cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        int x,y;
        cin>>x>>y;
        ans=1e9+1;
        dfs(x,y,x,w[x]+w[y]);
        cout<<ans<<endl;
    }

    return 0;
}
