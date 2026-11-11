#include<bits/stdc++.h>
using namespace std;
const int N=12;
int n,q,c,k,f[N][N],x,y,ans=0,vis[N],v[N],ct;
vector<int> g[N],a;
void ck(int d){
    vis[d]=ct;
    for(int i=0;i<(int)g[d].size();i++){
        if(v[g[d][i]] and !vis[g[d][i]]){
            ck(g[d][i]);
        }
    }
}
void fun(){
    ct=1;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<(int)a.size();i++){
        if(!vis[a[i]]){
            ck(a[i]);ct++;
        }
    }
    if(ct>3){
        return;
    }
    int mi=1e9,mx=-1e9;
    for(int i=1;i<=n;i++){
        mi=1e9;
        for(int j=0;j<(int)a.size();j++){
            mi=min(mi,f[i][a[j]]);
        }
        mx=max(mx,mi);
    }
    ans=min(ans,mx);
}
void dfs(int d){
    while(d>n){
        fun();return;
    }
    if((int)a.size()<k){
        v[d]=1;
        a.push_back(d);dfs(d+1);a.pop_back();v[d]=0;
    }
    dfs(d+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>q;
    while(q--){
        cin>>n>>k;ans=1e9;a.clear();
        for(int i=1;i<=n;i++){
            g[i].clear();
            for(int j=1;j<=n;j++){
                f[i][j]=1e9;
            }
            f[i][i]=0;
        }
        for(int i=1;i<n;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            f[x][y]=f[y][x]=1;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(f[i][k]+f[k][j]<f[i][j]){
                        f[i][j]=f[i][k]+f[k][j];
                    }
                }
            }
        }
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}
