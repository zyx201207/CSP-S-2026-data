#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int> > dist;
bool vis[1000005];
int ans=0;
void dfs(int idx,int len){
    if (len==k){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dist[i][j]!=-1);
                ans=max(ans,dist[i][j]);
            }
        }
        return;
    }
    if (idx>n) return;
    for (int i=idx;i<=n;i++){
        if (!vis[i]){
            vis[i]=true;
            dfs(i+1,len+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--){
        cin>>n>>k;
        dist.resize(n+1,vector<int>(n+1,-1));
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            dist[u][v]=1;
            dist[v][u]=1;
        }
        for (int i=1;i<=n;i++){
            dist[i][i]=0;
        }
        for(int s=1;s<=n;s++){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    if (dist[i][s]!=-1 && dist[s][j]!=-1){
                        dist[i][j]=min(dist[i][j],dist[i][s]+dist[s][j]);
                    }
                }
            }
        }
        int res=1e9;
        for (int i=1;i<=n;i++){
            ans=0;
            for (int j=1;j<=n;j++){
                vis[j]=false;
            }
            dfs(i,1);
            res=min(res,ans);
        }
        cout<<res<<'\n';
    }
    return 0;
}