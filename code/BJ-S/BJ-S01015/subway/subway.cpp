#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a,t,x,y,las=0,dis[500005];
bool vis[500005];
long long xxx=0;
vector<pair<long long,long long>> e[505][1005];
void dij(long long st){
    for(int i=0;i<=m;i++){
        dis[i]=1e18;
        vis[i]=0;
    }
    dis[500001]=1e18;
    vis[500001]=0;
    dis[st]=0;
    priority_queue <pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>> pq;
    pq.push({0,{st,0}});
    bool fl=1;
    //xxx=0;
    while(!pq.empty()){
        long long d=pq.top().first,u=pq.top().second.first,oo=pq.top().second.second;
        pq.pop();
        if(u==500001)continue;
        if(dis[u]!=d)continue;
        if(oo==0){
            for(int i=1;i<=n;i++){
                for(auto o:e[i][u]){
                    long long v=o.first,w=o.second;
                    if(fl&&v!=x)continue;
                    if(v==500001&&u!=y)continue;
                    if(dis[u]+d<dis[v]){
                        dis[v]=dis[u]+w;
                        //xxx++;
                        pq.push({dis[v],{v,i}});
                    }
                }
            }
            dis[0]=1e18;
            fl=0;
        }
        else{
            for(auto o:e[oo][u]){
                long long v=o.first,w=o.second;
                if(fl&&v!=x)continue;
                if(v==500001&&u!=y)continue;
                if(dis[u]+d<dis[v]){
                    dis[v]=dis[u]+w;
                    if(v!=0)pq.push({dis[v],{v,oo}});
                    else pq.push({dis[v],{v,0}});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            if(j>1){
                e[i][las].push_back({a,0});
                e[i][a].push_back({las,0});
            }
            las=a;
            e[i][0].push_back({a,t});
            e[i][a].push_back({0,t});
            e[i][a].push_back({500001,t});
        }
    }
    while(q--){
        cin>>x>>y;
        long long ans=w[x]+w[y];
        dij(0);
        cout<<ans+dis[500001]<<'\n';
    }
    return 0;
}