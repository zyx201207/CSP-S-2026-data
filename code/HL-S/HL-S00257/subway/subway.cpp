#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
set<int>h[500005]={};
map<int,int>xz[505];
bool vis[505]={};
int hc[505][505]={},hd[505][505];
int dfs(int l,int lx,int y){
    if(h[y].count(l)){
        return xz[l][hd[l][lx]]+xz[l][y];
    }
    int sum=INT_MAX;
    for(int i=1;i<=n;i++){
        if((!vis[i])&&(hc[l][i]!=INT_MAX)){
            vis[i]=1;
            sum=min(sum,dfs(n,l,y)+hc[l][i]);
        }
    }
    return sum;
}
int main(){
    freopen("subway.out","w",stdout);
    freopen("subway.in","r",stdin);
    cin>>c>>n>>m>>d>>q;
    int w[500005]={};
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            xz[i][a]=t;
            h[a].insert(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t=INT_MAX;
            if(i==j){
                hc[i][j]=t;
            }
            for(auto x:xz[i]){
                if(xz[j][x.first]!=0&&xz[i][x.first]+xz[j][x.first]<t){
                    t=xz[i][x.first]+xz[j][x.first];
                    hd[i][j]=x.first;
                }
            }
            hc[i][j]=t;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        int ans=INT_MAX;
        for(auto i:h[x]){
            if(h[y].count(i)){
                ans=xz[i][x]+xz[i][y];
                break;
            }
            ans=min(ans,dfs(i,(i+1)%h[x].size(),y)+xz[i][x]+xz[i][y]);
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
}

