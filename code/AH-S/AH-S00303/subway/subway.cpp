/*
*/
#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=5e2+5;
struct node{
    int next,w;
    bool operator >(const node &b) const{
        return w>b.w;
    }
};
int c,n,m,D,q;
int a[N],t[N];
int w[M];
vector<node> g[2*M];
long long dis[2*M];
bool vis[2*M];
struct subway{
    unordered_map<int,long long> w;
};
void dijkstra(int st){
    for(int i=m+1;i<=m*2;i++) dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
    priority_queue<node,vector<node>,greater<node> > q;
    dis[st]=0,q.push({st,0});
    while(!q.empty()){
        node u=q.top();
        //cout<<u.next<<"\n";
        q.pop();
        if(vis[u.next]) continue;
        vis[u.next]=1;
        for(int i=0;i<g[u.next].size();i++){
            node e=g[u.next][i];
            if(dis[e.next]>dis[u.next]+e.w){
                dis[e.next]=dis[u.next]+e.w;
                q.push({e.next,dis[e.next]});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>D>>q;
    subway dist[2*m+5];
    for(int i=1;i<=m;i++){
        cin>>w[i];
        //i<->i+m w[i]
    }
    //口编号:1~m
    //厅编号:m+1~2m
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];//第i条线路经过a厅 a厅到台时间为t
            //转化:这里每两个站台之间时间为t[i]
        }
        for(int j=1;j<=k;j++){
            for(int d=j+1;d<=k;d++){
                //i经过a[j] 也经过a[d]
                //到达时间为:t[i]+t[d]
                g[a[j]+m].push_back({a[d]+m,t[j]+t[d]});
                g[a[d]+m].push_back({a[j]+m,t[j]+t[d]});
                //cout<<a[j]+m<<" "<<a[d]+m<<"\n";
            }
        }
    }
    //q<=1e5
    for(int i=1;i<=m;i++){
        dijkstra(i+m);
        for(int j=1;j<=m;j++) dist[i+m].w[j+m]=dis[j+m];
    }
    while(q--){
        int x,y;
        cin>>x>>y;//地铁口x->地铁口y
        //x口 -> x厅 -> y厅 -> y口
        //转化为w[x]+w[y]+(a[j]+m和a[d]+m之间的最短距离)
        //多源最短路径
        cout<<w[x]+w[y]+dist[x+m].w[y+m]<<"\n";
    }
    return 0;
}
/*
44分
x口 <-> x厅 通过第i条路线<-> x台
*/
