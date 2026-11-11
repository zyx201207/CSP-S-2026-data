#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int maxn=1e6+10,inf=1e17;
int c,t,n,k,dis[maxn];
bool vis[maxn];
vector<int>g[maxn];
void dfs(int x,int fa){
    dis[x]=dis[fa]+1;
    for(int y:g[x]){
        if(y!=fa){
            dfs(y,x);
        }
    }
}
int v[maxn];
void dfs2(int x,int fa){
    v[x]=1;
    for(int y:g[x]){
        if(y!=fa){
            if(vis[y])dfs2(y,x);
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dis[0]=-1;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=inf;
        for(int s=0;s<(1<<n);s++){
            int cnt=0;
            for(int i=0;i<n;i++){
                v[i+1]=vis[i+1]=dis[i+1]=0;
                if((s>>i)&1)cnt++,vis[i+1]=1;
            }
            if(cnt!=k)continue;
            cnt=0;
            for(int i=1;i<=n;i++){
                if(vis[i]==1&&v[i]==0){
                    dfs2(i,0);
                    cnt++;
                }
            }
            if(cnt>2)continue;
            int mx=0;
            for(int i=1;i<=n;i++){
                if(vis[i]==0){
                    dfs(i,0);
                    int mn=inf;
                    for(int j=1;j<=n;j++){
                        if(vis[j]==1)mn=min(mn,dis[j]);
                    }
                    mx=max(mx,mn);
                }
            }
            // if(mx==1&&t==0){
            //     for(int i=1;i<=n;i++){
            //         if(vis[i])cout<<i<<" ";
            //     }
            //     cout<<"\n";
            // }
            ans=min(ans,mx);
        }
        cout<<ans<<'\n';
        // cout<<"---------------------------------\n";
    }
}