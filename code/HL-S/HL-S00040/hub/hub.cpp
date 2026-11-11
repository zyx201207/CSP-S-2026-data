#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
vector<vector<int>>edge;
vector<int>vis,ishub,dis;
void dfs1(int p){
    vis[p]=1;
    for(auto i:edge[p]){
        if(!vis[i]&&ishub[i]){
            dfs1(i);
        }
    }
}
void dfs2(int p,int f=0,int d=0){
    dis[p]=min(d,dis[p]);
    for(auto i:edge[p]){
        if(i!=f){
            dfs2(i,p,d+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k,cnt=0,ans=1e+9,now;
        cin>>n>>k;
        edge.assign(n+1,{});
        int u,v;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)!=k){
                continue;
            }
            cnt=now=0;
            vis.assign(n+1,0);
            ishub.assign(n+1,0);
            dis.assign(n+1,1e+9);
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ishub[j+1]=1;
                }
                else{
                    ishub[j+1]=0;
                }
            }
            for(int j=1;j<=n;j++){
                if(ishub[j]&&!vis[j]){
                    dfs1(j);
                    cnt++;
                }
            }
            if(cnt>2){
                continue;
            }
            for(int j=1;j<=n;j++){
                if(ishub[j]){
                    dfs2(j);
                }
            }
            for(int j=1;j<=n;j++){
                now=max(now,dis[j]);
            }
            ans=min(ans,now);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
