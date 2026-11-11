#include<bits/stdc++.h>
using namespace std;
long long w[500010],a[500010],t[500010];
vector< pair<long long,long long> > g[500010];
priority_queue< pair<long long,long long>,vector< pair<long long,long long> >,greater< pair<long long,long long> > > q;
long long dis[500010];
bool vis[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long c,n,m,d,qt;
    cin>>c>>n>>m>>d>>qt;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(long long j=1;j<=k;j++){
            for(long long u=1;u<=k;u++){
                if(j==u){
                    continue;
                }
                g[a[j]].push_back({a[u],t[j]+t[u]});
                g[a[u]].push_back({a[j],t[j]+t[u]});
            }
        }
    }
    while(qt--){
        long long s,y;
        cin>>s>>y;
        while(!q.empty()){
            q.pop();
        }
        for(long long i=1;i<=m;i++){
            dis[i]=1e18;
            vis[i]=false;
        }
        dis[s]=0;
        q.push({0,s});
        while(!q.empty()){
            long long x=q.top().second;
            q.pop();
            if(vis[x]){
                continue;
            }
            vis[x]=true;
            for(long long i=0;i<g[x].size();i++){
                if(!vis[g[x][i].first]&&dis[x]+g[x][i].second<dis[g[x][i].first]){
                    dis[g[x][i].first]=dis[x]+g[x][i].second;
                    q.push({dis[g[x][i].first],g[x][i].first});
                }
            }
        }
        cout<<dis[y]+w[s]+w[y]<<"\n";
    }
    return 0;
}
