#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=2e4+5;
const int INF=0x3f3f3f3f3f3f3f3f;
struct node{
    int a,t;
};
vector<node>l[N];
vector<pair<int,int>>g[M*20];
vector<pair<int,int>>h[M];
ll w[M],dis[M*20];
bool vis[M*20];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int c,n,m,d,q,tot;
int xx,yy;
void dij(int st){
    for(int i=1;i<=tot;i++){
        dis[i]=INF;
        vis[i]=0;
    }
    while(!pq.empty()) pq.pop();
    dis[st]=0;
    vis[st]=1;
    pq.push({0,st});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto v:g[u]){
            if(!vis[v.first]&&dis[v.first]>dis[u]+v.second){
                dis[v.first]=dis[u]+v.second;
                vis[v.first]=1;
                pq.push({dis[v.first],v.first});
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
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        h[i].push_back({i,0});
    }
    tot=m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            int u=++tot;
            h[x].push_back({u,y});  
            l[i].push_back({u,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(auto x:l[i]){
            for(auto y:l[i]){
                if(x.a!=y.a) g[x.a].push_back({y.a,0});
            }   
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x:h[i]){
            for(auto y:h[i]){
                if(x.first!=y.first) g[x.first].push_back({y.first,x.second+y.second});
            }
        }
    }
    while(q--){
        int xx,yy;
        cin>>xx>>yy;
        dij(xx);
        // cout<<w[x]+dis[y]+w[y]<<"\n";
        printf("%lld\n",w[xx]+dis[yy]+w[yy]);
    }
    return 0;
}