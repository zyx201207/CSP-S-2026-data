#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005],minx[5005][5005],cnt[5005][5005],vis[5005][5005],box[5005],d,k;
void dfs(int t,int n){
    if(t>n){
        int f=1;
        for(int i=2;i<=n;i++){
            if(x[box[i]]-x[box[i-1]]>d||box[i-1]>=box[i]) f=0;
        }
        if(f){
            vis[box[1]][box[n]]=min(vis[box[1]][box[n]],n);
            if(vis[box[1]][box[n]]==n) cnt[box[1]][box[n]]++;
        }
        return;
    }
    for(int i=1;i<=k;i++){
        box[t]=i;
        dfs(t+1,n);
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(vis,0x3f,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        int n,ans=0;
        cin>>n>>d;
        k=n;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=2;i<=n;i++) dfs(1,i);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
