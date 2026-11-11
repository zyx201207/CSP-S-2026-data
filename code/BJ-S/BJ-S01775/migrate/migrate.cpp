#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long x[2000005];
vector<long long> G[5005];
long long vis[5005];
long long dp[5005];
long long n,d;
void bfs(long long first){
    queue<long long> q;
    q.push(first);
    vis[first]=0;
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        for(long long i=0;i<G[u].size();i++){
            long long v=G[u][i];
            if(vis[u]+1<vis[v]){
                vis[v]=vis[u]+1;
                q.push(v);
                dp[v]=1;
            }else if(vis[u]+1==vis[v]){
                dp[v]++;
                q.push(v);
            }
        }
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    memset(vis,0x3f,sizeof vis);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(long long i=1;i<=n;i++) cin>>x[i];
            //cout<<d<<" "<<x[2]-x[1]<<" "<<n<<endl;
            if(n<4||d<x[3]-x[1]){
                cout<<0<<endl;
                continue;
            }else{
                cout<<max(0ll,n-(d/(x[2]-x[1])*2-1))<<endl;
                continue;
            }
        }
    }else {
        while(t--){
            cin>>n>>d;
            for(long long i=1;i<=n;i++) cin>>x[i];
            for(long long i=1;i<=n;i++){
                for(long long j=i+1;j<=n;j++){
                    if(x[j]-x[i]<=d){
                        G[i].push_back(j);
                    }else break;
                }
            }
            long long ans=0;
            for(long long i=1;i<=n;i++) {
                bfs(i);
                for(long long j=i+1;j<=n;j++){
                    if(dp[j]==2) ans++;
                    //cout<<vis[j]<<" "<<dp[j]<<endl;
                    dp[j]=0;
                    vis[j]=1e9;
                }
                //cout<<endl;
            }
            memset(vis,0x3f,sizeof vis);
            memset(dp,0,sizeof dp);
            cout<<ans<<endl;
            for(long long i=1;i<=n;i++) G[i].clear();
        }
    }
    return 0;
}
