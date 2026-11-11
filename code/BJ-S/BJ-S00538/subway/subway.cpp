#include<bits/stdc++.h>
using namespace std;
int a[500005],dis[500005],vis[500005];//,mp[505][500005],t[505][500005];
const int inf = 0xfffff;
int m;
struct node{
    int v,w;
};
vector<node>G[505];
vector<node>stop[500005];
void dijkstra(int st){
    memset(dis,inf,m+1);
    //memset(vis,0,m+1);
    dis[st] = 0;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int u = q.front();
        for(int i = 1;i<=G[u].size();i++){
            int v = G[u][i].v,w = G[u][i].w;
            //cout<<G[u][i].w<<endl;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                //cout<<dis[v]<<" "<<v<<endl;
                q.push(G[u][i].v);
            }
        }
        q.pop();
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>a[i];
    }
    //cout<<1<<endl;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++){
            int s,time;
            cin>>s>>time;
            stop[s].push_back({i,time});
            //cout<<s<<" "<<time<<endl;
        }
    }
    //cout<<2<<endl;
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=stop[i].size();j++){
            for(int k = j+1;k<=stop[i].size();k++){
                //for(int l = 1;l<=G[stop[i][j].v]){
                //    if
                //}
                G[stop[i][j].v].push_back({stop[i][k].v,stop[i][j].w+stop[i][k].w});
                G[stop[i][k].v].push_back({stop[i][j].v,stop[i][j].w+stop[i][k].w});
                //cout<<stop[i][j].w<<" "<<stop[i][k].w<<endl;
            }
        }
    }
    //cout<<3<<endl;
    for(int i = 1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        //cout<<4<<endl;
        int ans = inf;
        for(int j = 1;j<=stop[x].size();j++){
            dijkstra(stop[x][j].v);
            //cout<<5<<endl;
            for(int k = 1;k<=stop[y].size();k++){
                if(ans > a[x]+a[y]+dis[stop[y][k].v]+stop[x][j].w+stop[y][k].w){
                    ans = a[x]+a[y]+dis[stop[y][k].v]+stop[x][j].w+stop[y][k].w;
                    //cout<<dis[stop[y][k].v]<<" "<<i<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
