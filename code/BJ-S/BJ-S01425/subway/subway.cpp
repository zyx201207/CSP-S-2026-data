#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int id,lz;
};
int w[505];
ll dis[1505][1505];
int mn[505][505];
vector<node> v1[1505],v2[500005];
inline void bfs(int st){
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    dis[st][st]=0;
    while(pq.size()){
        int id=pq.top().second;
        pq.pop();
        for(auto i:v1[id]){
            if(dis[st][i.id]>dis[st][id]+i.lz){
                dis[st][i.id]=dis[st][id]+i.lz;
                pq.push({-dis[st][i.id],i.id});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(m>1000){
        memset(mn,0x3f,sizeof(mn));
        memset(dis,0x3f,sizeof(dis));
        int k,a,t;
        for(int i=1;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a>>t;
                v2[a].push_back({i,t});
            }
        }
        // for(int i=1;i<=m;i++){
        //     for(auto j:v2[i]){
        //         cout<<j.id<<" "<<j.lz<<'\n';
        //     }
        // }
        // cout<<'\n';
        node kk,jj;
        for(int i=1;i<=m;i++){
            for(int j=0;j<v2[i].size()-1;j++){
                jj=v2[i][j];
                for(int k=j+1;k<v2[i].size();k++){
                    kk=v2[i][k];
                    mn[jj.id][kk.id]=mn[kk.id][jj.id]=min(mn[jj.id][kk.id],jj.lz+kk.lz);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // cout<<mn[i][j]<<" ";
                v1[i].push_back({j,mn[i][j]});
            }
            // cout<<'\n';
        }
        // cout<<'\n';
        for(int i=1;i<=n;i++){
            bfs(i);
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        int xx,yy;
        ll ans=0;
        while(q--){
            ans=1e18;
            cin>>xx>>yy;
            for(auto i:v2[xx]){
                for(auto j:v2[yy]){
                    ans=min(ans,i.lz+j.lz+dis[i.id][j.id]);
                }
            }
            cout<<ans+w[xx]+w[yy]<<'\n';
        }
        return 0;
    }
    if(n<=500&&m<=1000){
        int k;
        for(int i=1;i<=n;i++){
            cin>>k;
            int a,t;
            for(int j=1;j<=k;j++){
                cin>>a>>t;
                v1[i+m].push_back({a,t});
                v1[a].push_back({i+m,t});
            }
        }
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=m;i++){
            bfs(i);
        }
        int xx,yy;
        for(int i=1;i<=q;i++){
            cin>>xx>>yy;
            cout<<dis[xx][yy]+w[xx]+w[yy]<<'\n';
        }
        return 0;
    }
    return 0;
}