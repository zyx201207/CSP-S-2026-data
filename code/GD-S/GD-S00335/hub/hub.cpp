#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int N=100,inf=1e18;
int c,t,n,k,dis[N],dep[N],mdep[N];
vector<int> g[N];
bitset<N> vis,flag,cv[1005];
void bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        For(i,0,(int)(g[u].size()-1)){
            int v=g[u][i];
            if(vis[v]||!flag[v]) continue;
            vis[v]=1;
            q.push(v);
        }
    }
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1,mdep[u]=dep[u];
    For(i,0,(int)(g[u].size()-1)){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        mdep[u]=max(mdep[u],mdep[v]);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==7){
        while(t--){
            cin>>n>>k;
            For(i,1,n) g[i].clear();
            For(i,1,n-1){
                int u,v;
                cin>>u>>v;
                cv[u].set(v);
                cv[v].set(u);
                g[u].push_back(v);
                g[v].push_back(u);
            }
            dfs(1,0);
            int ans=inf;
            For(i,1,n){
                For(j,i+1,n){
                    if(cv[i].test(j)) continue;
                    int d=min(dep[i]-1,dep[j]-1);
                    d=max(d,max(mdep[i]-dep[i],mdep[j]-dep[j]));
                    ans=min(ans,d);
                }
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(t--){
        int ans=inf;
        cin>>n>>k;
        For(i,1,n) g[i].clear();
        For(i,1,n-1){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        For(mask,0,(1<<n)-1){
            vis.reset();
            flag.reset();
            if(__builtin_popcount(mask)!=k) continue;
            vector<int> vec;
            For(i,0,n-1){
                if(mask&(1<<i)) vec.push_back(i+1),flag[i+1]=1;
            }
            int cnt=0;
            For(i,0,(int)(vec.size()-1)){
                int x=vec[i];
                if(!vis[x]) bfs(x),cnt++;
            }
            if(cnt!=2) continue;
            int d=0;
            For(i,1,n){
                if(flag[i]) continue;
                For(j,1,n) dis[j]=inf;
                dis[i]=0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    bool f=0;
                    int u=q.front();
                    q.pop();
                    For(j,0,(int)(g[u].size()-1)){
                        int v=g[u][j];
                        if(dis[u]+1>dis[v]) continue;
                        dis[v]=dis[u]+1;
                        if(flag[v]){
                            d=max(d,dis[v]),f=1;
                            break;
                        }
                        q.push(v);
                    }
                    if(f) break;
                }
            }
            ans=min(ans,d);
        }
        cout<<ans<<'\n';
    }
    return 0;
}