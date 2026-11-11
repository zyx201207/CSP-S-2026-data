#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[510][500005];
int t[510][500005];
int f[510][500005];
bool vis[510][500005];
int x,r;
struct node{
    int v,id;
};
struct node2{
    int v,id,step;
};
vector<node> g[500005];
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            f[i][a[i][j]]=j;
            if(j!=1){
                g[a[i][j]].push_back({a[i][j-1],i});
                g[a[i][j-1]].push_back({a[i][j],i});
            }
        }
    }
    for(int i=0;i<q;i++){
        cin>>x>>r;
        int ans=0x7fffffff;
        queue<node2> q;
        for(int i=1;i<=n;i++){
            if(f[i][x]){
                q.push({x,i,w[x]+t[i][f[i][x]]});
                vis[i][x]=1;
            }
        }
        while(!q.empty()){
            node2 now=q.front();
            q.pop();
            if(now.v==r){
                ans=min(ans,now.step+t[now.id][f[now.id][now.v]]+w[r]);
                continue;
            }
            for(int i=0;i<g[now.v].size();i++){
                if(vis[now.id][g[now.v][i].v]==1) continue;
                if(g[now.v][i].id==now.id){
                    q.push({g[now.v][i].v,now.id,now.step});
                    vis[now.id][g[now.v][i].v]=1;
                }else{
                    q.push({g[now.v][i].v,g[now.v][i].id,now.step+t[now.id][f[now.id][now.v]]+t[g[now.v][i].id][f[g[now.v][i].id][g[now.v][i].v]]});
                    vis[now.id][g[now.v][i].v]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
