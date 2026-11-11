#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q,w[M],len[N];
const ll inf=1e16;
vector<pair<int,int> >way[M];
struct ed{
    int v,c;
};
vector<ed>g[N];
ll dis[N][N];
bool vis[N];
void dij(int s){
    for(int i=1;i<=n;i++)vis[i]=0,dis[s][i]=inf;
    priority_queue<pair<ll,int> >q;
    q.push({0,s});
    dis[s][s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto i:g[u]){
            int v=i.v;
            if(dis[s][v]>dis[s][u]+i.c){
                dis[s][v]=dis[s][u]+i.c;
                q.push({-dis[s][v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>len[i];
        for(int j=1;j<=len[i];j++){
            int x,y;cin>>x>>y;
            way[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:way[i]){
            for(auto k:way[i]){
                if(j==k)continue;
                g[j.first].push_back({k.first,j.second+k.second});
                g[k.first].push_back({j.first,j.second+k.second});
            }
        }
    }
    for(int i=1;i<=n;i++)dij(i);
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        ll ans=inf*10;
        for(auto j:way[x]){
            for(auto k:way[y]){
                ans=min(ans,1ll*w[x]+w[y]+j.second+k.second+dis[j.first][k.first]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}