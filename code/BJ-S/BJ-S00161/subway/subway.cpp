#include<bits/stdc++.h>
using namespace std;
long long c,r,n,m,d;
bool vis[1000005];
struct node{
long long id,dist;
bool operator<(const node &a) const{
return dist>a.dist;
}
};
int w1[1000005];
vector <long long> e[1000005];
long long dis[1000005];
long long a[1000005];
long long b[1000005];
long long w[1000005];
priority_queue <node> q;
void dij(long long x){
    memset(vis,0,sizeof(vis));
    for(long long i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
    dis[x]=0;
    q.push({x,0});
    while(q.size()){
        long long u=q.top().id;
        long long d=q.top().dist;
        q.pop();
        if(d!=dis[u] || vis[u]) continue;
        vis[u]=1;
        for(long long i=0;i<e[u].size();i++){
            long long v=e[u][i];
            long long c1=w1[u];
            long long c2=w1[v];
            if(dis[v]>dis[u]+c1+c2){
                dis[v]=dis[u]+c1+c2;
                q.push({v,dis[v]});
            }
        }
    }

}
int main(){
   freopen("subway.in","w",stdin);
   freopen("subway.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>m>>n>>d>>r;
    for(long long i=1;i<=n;i++) cin>>w[i];
    for(long long i=1;i<=m;i++){
            long long k;
            cin>>k;
        for(long long j=1;j<=k;j++){
                long long b;
            cin>>a[j]>>w1[i];
            e[a[j-1]].push_back(a[j]);
           // e[a[j]].push_back(a[j-1]);
        }
    }
for(long long i=1;i<=r;i++){
        memset(dis,0,sizeof(dis));
        long long u,v;
        cin>>u>>v;
        dij(u);
        cout<<(dis[v]+w[u]+w[v])-1<<endl;
}

return 0;
}
