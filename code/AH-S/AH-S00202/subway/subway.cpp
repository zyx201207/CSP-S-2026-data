#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=520;
int c,n,m,d,q;
int ww[M];
struct node{
    int v,w;
};
struct st{
    int now,line,dis;
};
vector<node> station[M];
vector<node> train[M];
bool vis[N];
int diss[M];
void bfs(int s,int e){
    memset(diss,0x3f,sizeof(diss));
    memset(vis,0,sizeof(vis));
    queue<st> q;
    for(int i=0;i<station[s].size();i++){
        q.push({s,station[s][i].v,station[s][i].w});
    }
    while(!q.empty()){
        int now=q.front().now,line=q.front().line,dis=q.front().dis;
        q.pop();
        if(vis[line])continue;
        vis[line]=1;
        for(int i=0;i<train[line].size();i++){
            if(train[line][i].v==e){
                diss[e]=min(diss[e],dis+train[line][i].w);
                continue;
            }int v=train[line][i].v;
            if(station[v].size()>1){
                for(int j=0;j<station[v].size();j++){
                    if(station[v][i].v!=line){
                        q.push({v,station[v][i].v,dis+station[v][line].w+train[station[v][i].v][v].w});
                    }
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>ww[i];
    }for(int i=1,k,v,w;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>v>>w;
            station[v].push_back({i,w});
            train[i].push_back({v,w});
        }
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        bfs(x,y);
        cout<<diss[y]+ww[x]+ww[y]<<"\n";
    }
    return 0;
}
