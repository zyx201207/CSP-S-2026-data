#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,cnt,ans,dis[1111][1111];
bool b[1111111],vis[1111111];
vector<long long> e[1111111];
void dfss(long long x){
    vis[x]=1;
    for(int i=0;i<e[x].size();i++) if(vis[e[x][i]]==0&&b[e[x][i]]) dfss(e[x][i]);
    return;
}
void dfs(long long x){
    if(cnt==k){
        long long sum=0,maxn=0;
        for(int i=1;i<=n;i++){
            if(b[i]&&vis[i]==0){
                dfss(i);
                sum++;
            }
        }for(int i=1;i<=n;i++) vis[i]=0;
        if(sum>2) return;
        for(int i=1;i<=n;i++){
            if(!b[i]){
                long long minn=9e18;
                for(int j=1;j<=n;j++) if(b[j]) minn=min(minn,dis[i][j]);
                maxn=max(maxn,minn);
            }
        }ans=min(ans,maxn);
        return;
    }if(x>n) return;
    b[x]=1,cnt++;
    dfs(x+1);
    b[x]=0,cnt--;
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        ans=9e18,cnt=0;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=1e18;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            dis[u][v]=dis[v][u]=1;
            e[u].push_back(v);
            e[v].push_back(u);
        }for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[i][j]=min(dis[i][k]+dis[j][k],dis[i][j]);
        dfs(1);
        cout<<ans<<'\n';
    }return 0;
}
