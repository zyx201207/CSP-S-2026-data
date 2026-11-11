#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int to,len;
};
bool operator < (node x,node y){
    return x.len<y.len;
}
int n,d;
int a[500005],ct[500005];
vector<node>g[600005];
int dis[600005],vis[600005];
int dijk(int s){
    memset(dis,0x7f,sizeof dis);
    memset(vis,0,sizeof vis);
    memset(ct,0,sizeof ct);
    priority_queue<node>q;
    q.push({s,0});
    dis[s]=0;
    ct[s]=1;
    while(!q.empty()){
        node x=q.top();
        q.pop();
        if(vis[x.to]) continue;
        vis[x.to]=1;
        for(auto i:g[x.to]){
            if(dis[i.to]>x.len+i.len){
                dis[i.to]=x.len+i.len;
                ct[i.to]=ct[x.to];
                q.push({i.to,dis[i.to]});
            }
            else if(dis[i.to]==x.len+i.len) ct[i.to]+=ct[x.to];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(ct[i]==2) cnt++;
    return cnt;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
        if(a[j]-a[i]<=d) g[i].push_back({j,1});
        else break;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dijk(i);
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int c,t;
   cin>>c>>t;
   while(t--) solve();
   return 0;
}

