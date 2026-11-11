#include<bits/stdc++.h>
using namespace std;
long long o,n,m,d,q,w[500010],x,y,op,dis[2000][2000];
struct point{
    int v,w;
    bool operator <(point _)const{
        return w>_.w;
    }
};
vector<point> adj[500510],adj1[510];
priority_queue<point> pq;
int main(){
    freopen("subway.in","r",stdin);//***********************************************************
    freopen("subway.out","w",stdout);
    cin>>o>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>op;
        while(op--){
            cin>>x>>y;
            adj[x].push_back({i+m,y});
            adj[i+m].push_back({x,y});
        }
    }

    if(o<20){
        //long long dis[2000][2000];
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=m;i++){
            pq.push({i,0});
            dis[i][i]=0;
            while(!pq.empty()){
                int u=pq.top().v;pq.pop();
                for(int j=0;j<adj[u].size();j++){
                    int v=adj[u][j].v,w=adj[u][j].w;
                    if(dis[i][v]>dis[i][u]+w){
                        dis[i][v]=dis[i][u]+w;
                        pq.push({v,dis[i][v]});
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            cout<<w[x]+w[y]+dis[x][y]<<'\n';
        }
        return 0;
    }
    if(1){
        //cout<<1<<endl;
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=m;i++){
            if(adj[i].size()==2){
                long long w=adj[i][0].w+adj[i][1].w;
                //cout<<adj[i][0].v<<" "<<adj[i][1].v<<" "<<w<<endl;
                adj1[adj[i][0].v-m].push_back({adj[i][1].v-m,w});
                adj1[adj[i][1].v-m].push_back({adj[i][0].v-m,w});
            }
        }
        //cout<<1<<endl;
        for(int i=1;i<=n;i++){
            pq.push({i,0});
            dis[i][i]=0;
            while(!pq.empty()){
                int u=pq.top().v;pq.pop();
                for(int j=0;j<adj1[u].size();j++){
                    long long v=adj1[u][j].v,w=adj1[u][j].w;
                    if(dis[i][v]>dis[i][u]+w){
                        dis[i][v]=dis[i][u]+w;
                        pq.push({v,dis[i][v]});
                    }
                }
            }
        }
        //cout<<1<<endl;
        //cout<<dis[6][7]<<endl;
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            long long ans=1e18;
            for(int j=0;j<adj[x].size();j++){
                for(int k=0;k<adj[y].size();k++){
                    //cout<<adj[x][j].w<<" "<<adj[y][k].w<<" "<<dis[adj[x][j].v][adj[y][k].v]<<endl;
                    ans=min(ans,1ll*(adj[x][j].w+adj[y][k].w+dis[adj[x][j].v-m][adj[y][k].v-m]));
                }
            }
            cout<<ans+w[x]+w[y]<<'\n';
        }
    }
    return 0;
}
