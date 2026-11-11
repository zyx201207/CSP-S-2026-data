#include<bits/stdc++.h>
using namespace std;
int c,t,n;
vector<int> g[1000001];
bool vis[1000001],vis2[1000001];
int dis[1000001];
void dfs(int u){
    vis2[u]=true;
    for(auto v:g[u]){
        if(vis[v]&&!vis2[v]){
            dfs(v);
        }
    }
}
void dfs1(int u){
    for(auto v:g[u]){
        if(dis[v]<0){
            dis[v]=dis[u]+1;
            dfs1(v);
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c<=3){
        while(t--){
            cin>>n;
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            int ans=(1<<30);
            for(int i=0;i<(1<<n);i++){
                for(int j=0;j<n;j++){
                    if(i&(1<<j)){
                        vis[j+1]=true;
                    }else{
                        vis[j+1]=false;
                    }
                    vis2[j+1]=false;
                }
                int cnt=0;
                for(int j=1;j<=n;j++){
                    if(vis[j]&&!vis2[j]){
                        dfs(j);
                        cnt++;
                    }
                }
                int mx=0;
                if(cnt<=2){
                    for(int j=1;j<=n;j++){
                        for(int k=1;k<=n;k++){
                            dis[k]=0;
                        }
                        dis[j]=1;
                        dfs1(j);
                        int d=(1<<30);
                        for(int k=1;k<=n;k++){
                            if(vis[k]){
                                d=min(d,dis[k]-1);
                            }
                        }
                        mx=max(mx,d);
                    }
                    ans=min(ans,mx);
                }
            }
            cout<<ans<<endl;
        }
    }
}
