#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
vector<int> g[15];
int n,k,as[15],vis[15];
int dist[15][15];
int minn=inf;
void trdfs(int x,int f){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int l=g[x][i];
        if(vis[l]==1) continue;
        if(l==f) continue;
        if(as[l]==0) continue;
        trdfs(l,x);
    }
}
bool check(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    int ltk=0;
    for(int i=1;i<=n;i++){
        if(as[i]==1&&vis[i]==0){
            trdfs(i,0);
            ltk++;
        }
        if(ltk==2) break;
    }
    for(int i=1;i<=n;i++){
        if(as[i]==1&&vis[i]==0){
            return false;
        }
    }
    return true;
}
void dt(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}
void dfs(int x,int ct){
    if(x>=n+1){
        if(ct!=k) return ;
        if(check()==false) return ;
        int tas=0;
        for(int i=1;i<=n;i++){
            if(as[i]==0){
                int tm=inf;
                for(int j=1;j<=n;j++){
                    if(as[j]==1){
                        tm=min(tm,dist[i][j]);
                    }
                }
                tas=max(tas,tm);
            }
        }
        minn=min(minn,tas);
        return ;
    }
    as[x]=0;
    dfs(x+1,ct);
    if(ct!=k){
        as[x]=1;
        dfs(x+1,ct+1);
        as[x]=0;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=inf;
            }
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            dist[u][v]=1;
            dist[v][u]=1;
        }
        minn=inf;
        dt();
        dfs(1,0);
        cout<<minn<<"\n";
    }
    return 0;
}

