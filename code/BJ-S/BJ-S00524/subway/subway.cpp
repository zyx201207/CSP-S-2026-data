#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
#define ll long long
ll c,n,m,d,q,k[N],a,t,ans,x,y;
ll dis[N][N],w[M];
struct node{
    ll to,val;
};
vector<node> gg[N+M],g[N];
vector<int> G[N+M];
struct Node{
    ll to,val;
    bool operator < (const Node &p)const{
        return p.val<val;
    }
};
void dijkstra(int s){
    priority_queue<Node> q;
    memset(dis[s],0x3f,sizeof(dis[s]));
    q.push({s,0});dis[s][s]=0;
    while(!q.empty()){
        Node u=q.top();
        q.pop();
        if(u.val!=dis[s][u.to]) continue;
        for(node v:g[u.to]){
            if(dis[s][v.to]>v.val+dis[s][u.to]){
                dis[s][v.to]=v.val+dis[s][u.to];
                q.push({v.to,dis[s][v.to]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            gg[a+n].push_back({i,t});
            gg[i].push_back({a+n,t});
            G[a].push_back(i);
        }
    }
    for(int i=n+1;i<=n+m;i++){
        for(int j=0;j<gg[i].size();j++){
            for(int k=0;k<gg[i].size();k++){
                if(j!=k){
                    g[gg[i][j].to].push_back({gg[i][k].to,gg[i][j].val+gg[i][k].val});
                    g[gg[i][k].to].push_back({gg[i][j].to,gg[i][j].val+gg[i][k].val});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
        //for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
        //cout<<'\n';
    }
    while(q--){
        cin>>x>>y;ans=1e18;
        for(int i=0;i<gg[x+n].size();i++)
            for(int j=0;j<gg[y+n].size();j++)
                ans=min(ans,dis[gg[x+n][i].to][gg[y+n][j].to]+gg[x+n][i].val+gg[y+n][j].val);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
//思路：先对于每个地铁线路跑最短路，记录i路到j路最短耗时，然后询问时大力求即可
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
