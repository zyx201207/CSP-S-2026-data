#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int to,len;
};
bool operator < (node x,node y){
    return x.len<y.len;
}
int c,n,m,d;
int a[500005];
vector<node>g[600005];
int dis[600005],vis[600005];
int dijk(int s,int e){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<node>q;
    q.push({s,0});
    dis[s]=0;
    while(!q.empty()){
        node x=q.top();
        q.pop();
        if(vis[x.to]) continue;
        vis[x.to]=1;
        if(x.to==e) return x.len;
        for(auto i:g[x.to]){
            if(dis[i.to]>x.len+i.len){
                dis[i.to]=x.len+i.len;
                q.push({i.to,dis[i.to]});
            }
        }
    }
}
signed main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>c>>n>>m>>d;
   int qt;
   cin>>qt;
   for(int i=1;i<=m;i++) cin>>a[i];
   for(int k,i=1;i<=n;i++){
      cin>>k;
      for(int x,t,j=1;j<=k;j++){
        cin>>x>>t;
        g[x].push_back({m+i,t});
        g[m+i].push_back({x,t});
      }
   }
   while(qt--){
    int x,y;
    cin>>x>>y;
    cout<<a[x]+a[y]+dijk(x,y)<<'\n';
   }
   return 0;
}

