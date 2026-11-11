#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,qq;
int w[500005];
int k[505],a[505][500005],t[505][500005];
struct node{
    long long num, w;
    bool operator<(const node &o)const{
        return w>o.w;
    }
};
long long dp[500505];
bool vis[500505];

vector <node> g[500505];
priority_queue<node> q;

void dij(int start,int des){
    dp[start]=0;
    q.push({start,0});
    while(!q.empty()){
        node x=q.top();
        q.pop();
        if(vis[x.num]) continue;
        if(x.num==des) return;
        vis[x.num]=1;
        for(node nx:g[x.num]){
            if(dp[nx.num]>dp[x.num]+nx.w){
                dp[nx.num]=dp[x.num]+nx.w;
                q.push({nx.num,dp[nx.num]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back({m+i,t[i][j]});
            g[m+i].push_back({a[i][j],t[i][j]});
        }
    }
    //for(int i=1;i<=n+m;i++){
     //       cout<<i<<":";
     //   for(int j=0;j<g[i].size();j++){
     //       cout<<g[i][j].num<<"is"<<g[i][j].w<<" ";
      //  }
     //   cout<<endl;
    //}
    while(qq--){
        int x,y;
        cin>>x>>y;
        memset(dp,0x3f,sizeof dp);
        memset(vis,0,sizeof vis);
        dij(x,y);
        //for(int i=1;i<=n+m;i++){
        //    cout<<i<<":"<<dp[i]<<endl;
        //}
        cout<<dp[y]+w[x]+w[y]<<endl;
    }
    return 0;
}