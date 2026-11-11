#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int c,t,n,d,x[2000005],dp[2000005],vis[2000005];
bool inq[2000005];
vector<int>gp[2000005];
struct node{
    int nw,stp;
};
void bfs(int st){
    for(int i=1;i<=n;i++)dp[i]=0,vis[i]=inf;
    queue<node>q;
    q.push((node){st,0});
    dp[st]=1;
    vis[st]=0;
    while(!q.empty()){
        auto qf=q.front();
        q.pop();
        inq[qf.nw]=0;
        for(auto it:gp[qf.nw]){
            if(qf.stp+1>vis[it])continue;
            dp[it]+=dp[qf.nw];
            if(inq[it])continue;
            inq[it]=1;
            q.push((node){it,qf.stp+1});
            vis[it]=qf.stp+1;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[j]-x[i])>d)continue;
                // cerr<<i<<" "<<j<<endl;
                gp[i].push_back(j);
                gp[j].push_back(i);
            }
        }
        int ans=0;
        // bfs(1);
        // for(int i=1;i<=n;i++)cerr<<dp[i]<<" ";
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                if(dp[j]==2){
                    // cerr<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        for(int i=1;i<=n;i++)gp[i].clear();
        cout<<ans/2<<endl;
    }
    return 0;
}