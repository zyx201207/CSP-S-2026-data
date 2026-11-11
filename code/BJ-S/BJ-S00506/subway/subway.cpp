#include <bits/stdc++.h>
using namespace std;
const long long inf=1e17;
long long w[500005];
long long k[1005],t[1005];
long long gg[1005][1005];
vector<pair<long long,long long> > g[1005];
long long sv[100005];
long long dist[1005],vis[1005],c,n,m,d,q;
struct qst{
    long long x,y,id,ans;
}qs[100005];
bool my_cmp(qst x,qst y){
    return x.x<y.x;
}
bool id_cmp(qst x,qst y){
    return x.id<y.id;
}
void dijkstra(int s){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<> > q;
    for(int i=1;i<=m;i++){
        vis[i]=0;
        dist[i]=inf;
    }
    dist[s]=0;
    q.push({0,s});
    while(!q.empty()){
        long long x=q.top().second;
        //cout<<q.top().first<<" "<<x<<"\n";
        q.pop();
        if(vis[x]==1) continue;
        vis[x]=1;
        for(int i=0;i<g[x].size();i++){
            long long l=g[x][i].first,ww=g[x][i].second;
            if(vis[l]==0){
                dist[l]=min(dist[l],dist[x]+ww);
                q.push({dist[x]+ww,l});
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        for(int j=1;j<=m;j++){
            gg[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        for(int j=1;j<=x;j++){
            cin>>k[j]>>t[j];
        }
        for(int j=1;j<=x;j++){
            for(int y=j+1;y<=x;y++){
                long long u=k[j],v=k[y];
                if(u>v) swap(u,v);
                gg[u][v]=min(gg[u][v],t[j]+t[y]);
                gg[v][u]=gg[u][v];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(gg[i][j]!=inf){
                g[i].push_back({j,gg[i][j]});
                //cout<<i<<" "<<j<<" "<<gg[i][j]<<"\n";
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>qs[i].x>>qs[i].y;
        qs[i].id=i;
        sv[qs[i].x]=1;
    }
    sort(qs+1,qs+q+1,my_cmp);
    //cout<<1<<"\n";
    long long pt=1;
    for(int i=1;i<=m;i++){
        if(sv[i]==1){
            dijkstra(i);
            for(;pt<=q;pt++){
                long long x=qs[pt].x,y=qs[pt].y;
                if(x!=i) break;
                qs[pt].ans=dist[y]+w[x]+w[y];
            }
        }
        //cout<<1<<"\n";
    }
    sort(qs+1,qs+q+1,id_cmp);
    for(int i=1;i<=q;i++){
        cout<<qs[i].ans<<"\n";
    }
    return 0;
}
