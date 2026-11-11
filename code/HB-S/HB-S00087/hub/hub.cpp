#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=15;
LL n,k,ans=1e9;
int vis[N],col[N],dis[N][N];
vector<int>g[N];

void ds(int u,int st){
    vis[u]=1;
    for(auto v:g[u]){
        if(!vis[v]){
            dis[st][v]=dis[st][u]+1;
            ds(v,st);
        }
    }
}

void dfs(int u,int cl){
    col[u]=cl;
    for(auto v:g[u]){
        if(vis[v] && !col[v]){
            dfs(v,cl);
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,C;
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        ans=1e9;
        memset(dis,0,sizeof dis);
        for(int x=1;x<=n;x++){
            g[x].clear();
        }
        for(int x=1;x<n;x++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int x=1;x<=n;x++){
            memset(vis,0,sizeof vis);
            ds(x,x);
        }
        for(int mask=0;mask<(1<<n);mask++){
            memset(vis,0,sizeof vis);
            int ct=0;
            for(int x=1;x<=n;x++){
                if(mask&(1<<(x-1))){
                    ct++;
                    vis[x]=1;
                }
            }
            if(ct==k){
                int tt=0;
                memset(col,0,sizeof col);
                for(int x=1;x<=n;x++){
                    if(mask&(1<<(x-1)) && !col[x]){
                        dfs(x,x);
                        tt++;
                    }
                }
                if(tt<=2){
                    int cnt=0;
                    for(int x=1;x<=n;x++){
                        if(!vis[x]){
                            int nw=1e9;
                            for(int y=1;y<=n;y++){
                                if(vis[y]){
                                    nw=min(nw,dis[x][y]);
                                }
                            }
                            cnt=max(cnt,nw);
                        }
                    }
                    ans=min(ans,(LL)cnt);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}