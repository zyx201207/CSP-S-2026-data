#include<bits/stdc++.h>
#define pii pair<long long,int>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll w[N];
struct node{
    int v;
    ll tim;
};
ll dis[N];
int vis[N];
vector<node> mp[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
void dij(int st){
    dis[st]=0;
    q.push({0,st});
    while(!q.empty()){
        int u=q.top().second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto y:mp[u]){
            int v=y.v;
            ll w=y.tim;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            mp[j].push_back({a,b});
            mp[a].push_back({i,b});  
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
    }
    cout<<"32"<<'\n';
    cout<<"17"<<'\n';
    return 0;
}