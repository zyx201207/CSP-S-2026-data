#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w,k,t,u,x,y;
vector<pair<long long,long long>>a[501];
priority_queue<pair<long long,long long>>q;
bool vis[5000001];
long long dp[501][501];
void diji(long long x,long long y){
    memset(vis,0,sizeof(vis));
    memset(dp,0x3f,sizeof(dp));
    q.push(a[0][x]);
    dp[0][x]=a[0][x].second;
    while(!q.empty()){
        auto [un,v]=q.top();
        //cout<<un<<" "<<v<<" ";
        q.pop();
        if(!vis[un]){
        for(auto[w,z]:a[un]){
            if(dp[w][x]>dp[un][x]+v){
                dp[w][x]=dp[x][x]+v;
                vis[w]=1;
                q.push({w,z});
            }
        }}
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>p;
    for(long long i=1;i<=m;i++){
        cin>>w;
        a[i].push_back({0,w});
    }for(int i=1;i<=n;i++){
        cin>>k;
        long long last=0;
        for(int j=1;j<=k;j++){
            cin>>u>>t;
            a[u].push_back({last,u});
            last=u;
        }
    }for(int i=1;i<=p;i++){
        cin>>x>>y;
        diji(x,y);
        cout<<dp[x][y]<<endl;
    }
    return 0;
}
