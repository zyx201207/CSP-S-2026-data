#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
// binary_search
// dp hard to write
// so give up
namespace shizuru_nakatsu{
    int n,k;
    vector<int>ed[1000005];
    // int dp[1005][1005][3][2];
    int dep[1005],fa[1005];
    void init(int x,int f){
        fa[x]=f;dep[x]=dep[f]+1;
        for(auto v:ed[x]){
            if(v==f)continue;
            init(v,x);
        }
    }
    void init(){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            ed[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        // memset(dp,0x3f,sizeof(dp));
        init(1,1);
    }
    int d=0;
    int dis(int x,int y){
        int res=0;
        // printf("%d %d ",x,y);
        while(x!=y){
            
            while(dep[x]>=dep[y]&&x!=y){
                x=fa[x];res++;
            }
            while(dep[y]>=dep[x]&&x!=y){
                y=fa[y];res++;
            }
        }
        // printf("%d\n",res);
        return res;
    }    
    int vis[1005],ans,q[1005];
    int count(int x,int f){
        int res=0;
        if(vis[f]==0&&vis[x]==1){
            res++;
        }
        for(auto v:ed[x]){
            if(v==f)continue;
            res+=count(v,x);
        }
        return res;
    }
    void dfs(int x){
        if(x==k+1){
            if(count(1,0)>2)return;
            int res=0;
            for(int p=1;p<=n;p++){
                int ces=1e9;
                for(int j=1;j<=k;j++){
                    ces=min(ces,dis(p,q[j]));
                }
                res=max(res,ces);
            }
            ans=min(ans,res);
            return;
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            q[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
        // for(auto v:ed[x]){
        //     if(v==f)continue;
        //     dfs(v,x);
            
        // }
    }
    void my_love(){
        ans=1e9;
        dfs(1);
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int C,T=1;
    cin>>C>>T;//T=1;
    while(T--){
        shizuru_nakatsu::init();
        shizuru_nakatsu::my_love();
    }
    return 0;
}