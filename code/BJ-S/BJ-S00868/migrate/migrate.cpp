#include<bits/stdc++.h>
#define ll long long
#define it128 __int128
using namespace std;
int c,t;
int n,d;
ll x[5100];
vector<pair<int,it128>> edge[5100];
ll dis[5100];
int cnt[5100];
bool vis[5100];
priority_queue<pair<it128,int>,vector<pair<it128,int>>,greater<pair<it128,int>>> pq;
void dij(int st,int ed){
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    pq.push({0LL,st});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto son:edge[u]){//if birds connot fly to the next
            int v=son.first;
            ll w=son.second;
            if(dis[v]>dis[u]+w&&w<=d){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
                cnt[v]=cnt[u]+1;
            }else if(dis[v]==dis[u]+w&&w<=d){
                cnt[v]+=cnt[u];
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                edge[i].push_back({j,x[j]-x[i]});
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dij(i,j);
                if(cnt[j]==2+d)ans++;
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++){
            edge[i].clear();
        }
    }
}
//jiu_jiu_wo_ba qwq,bu_yao_gao_wa,duo_duo_AC
