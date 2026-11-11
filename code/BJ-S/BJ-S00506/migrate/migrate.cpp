#include <bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long vis[5005],dist[5005],cnt[5005],a[5005];
long long n,m;
vector<int> g[5005];
void dijkstra(int s){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<> > q;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dist[i]=inf;
        cnt[i]=0;
    }
    dist[s]=0;
    cnt[s]=1;
    q.push({0,s});
    while(!q.empty()){
        long long x=q.top().second;
        //cout<<q.top().first<<" "<<x<<"\n";
        q.pop();
        if(vis[x]==1) continue;
        vis[x]=1;
        for(int i=0;i<g[x].size();i++){
            long long l=g[x][i],ww=1;
            if(vis[l]==0){
                if(dist[x]+ww<dist[l]){
                    dist[l]=dist[x]+ww;
                    cnt[l]=cnt[x];
                }else if(dist[x]+ww==dist[l]){
                    cnt[l]+=cnt[x];
                }
                q.push({dist[x]+ww,l});
            }
        }
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]>a[i]+m) break;
                g[i].push_back(j);
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            dijkstra(i);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                    //cout<<i<<" "<<j<<"\n";
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
