#include <bits/stdc++.h>
using namespace std;
#define p pair<pair<int,int>,long long>
struct node{
    int to;
    long long w;
};
int n,m,c,d,T;
long long w[500005];
vector<int> a[505];
int k[505];
long long t[500005][25];
vector<node> road[500005];
long long dis[500005];
long long dijistra(int start,int fin){
    dis[start]=0;
    priority_queue<p> q;
    for(int i=0;i<road[start].size();i++){
        q.push({{start,road[start][i].to},-1*road[start][i].w});
    }
    while(!q.empty()){
        auto r=q.top();
        q.pop();
        if(dis[r.first.second]>dis[r.first.first]-r.second){
            dis[r.first.second]=dis[r.first.first]-r.second;
            for(int i=0;i<road[r.first.second].size();i++){
                q.push({{r.first.second,road[r.first.second][i].to},-1*road[r.first.second][i].w});
            }
        }
    }
    return dis[fin];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>T;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int u;
            cin>>u;
            a[i].push_back(u);
            cin>>t[u][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            for(int q=0;q<a[i].size();q++){
                if(a[i][j]!=a[i][q]){
                    road[a[i][j]].push_back({a[i][q],t[a[i][j]][i]+t[a[i][q]][i]});
                    road[a[i][q]].push_back({a[i][j],t[a[i][q]][i]+t[a[i][j]][i]});
                }
            }
        }
    }
    while(T--){
        int u,v;
        cin>>u>>v;
        long long ans=0;
        ans+=w[u]+w[v];
        memset(dis,0x3f,sizeof dis);
        ans+=dijistra(u,v);
        cout<<ans<<endl;
    }
    return 0;
}


