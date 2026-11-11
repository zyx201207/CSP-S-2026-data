#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000005];
int f[25][1000005],dep[1000005],n,k,ans=1e9,r[1000005];
bool box[15];
void dfs(int cur,int fa){
    f[0][cur]=fa;
    dep[cur]=dep[fa]+1;
    for(int i=0;i<adj[cur].size();i++){
        int x=adj[cur][i];
        if(x!=fa){
            dfs(x,cur);
        }
    }
}
int get(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[f[i][x]]>=dep[y]){
            x=f[i][x];
        }
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(f[i][x]!=f[i][y]){
            x=f[i][x],y=f[i][y];
        }
    }
    return f[0][x];
}
int dis(int x,int y){
    int lca=get(x,y);
    return dep[x]+dep[y]-2*dep[lca];
}
int find(int x){
    if(x==r[x]) return x;
    return r[x]=find(r[x]);
}
void merge(int x,int y){
    r[find(x)]=find(y);
}
void baoli(int cur,int now){
    if(cur>n){
        if(now!=k) return ;
        for(int i=1;i<=n;i++) r[i]=i;
        for(int i=1;i<=n;i++){
            if(!box[i]) continue;
            for(int j=0;j<adj[i].size();j++){
                int x=adj[i][j];
                if(box[x]) merge(i,x);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(box[i]&&find(i)==i) cnt++;
        }
        if(cnt>2) return ;
        int maxs=0;
        for(int i=1;i<=n;i++){
            int mins=1e9;
            for(int j=1;j<=n;j++){
                if(box[j]){
                    mins=min(mins,dis(i,j));
                }
            }
            maxs=max(maxs,mins);
        }
        ans=min(ans,maxs);
        return ;
    }
    if(now==k){
        baoli(cur+1,now);
    }
    else{
        box[cur]=1;
        baoli(cur+1,now+1);
        box[cur]=0;
        baoli(cur+1,now);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T,u,v;
    cin>>C>>T;
    while(T--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=1;i<n;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=20;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=f[i-1][f[i-1][j]];
            }
        }
        if(C<=3){
            baoli(1,0);
            cout<<ans<<'\n';
            continue;
        }
    }
    return 0;
}
