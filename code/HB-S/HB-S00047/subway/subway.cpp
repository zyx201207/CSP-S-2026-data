#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
long long w[M];
vector<int> a[N];
vector<long long> t[N];
vector<int> appear[M];
int k[N];
long long dis[M];
struct Edge{
    int v,line;
    long long w;
};
struct Node{
    int to,curLine;
    long long w;
    bool operator < (const Node &p) const {
        return w>p.w;
    }
};
vector<Edge> g[M];
void dijkstra(int s,int e){
    priority_queue<Node> pq;
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    pq.push({s,0,0});
    while(!pq.empty()){
        Node u=pq.top();
        pq.pop();
        if(u.w>dis[u.to]){
            continue;
        }
        for(Edge v:g[u.to]){
            if(v.line==u.curLine){
                if(dis[v.v]>dis[u.to]){
                    dis[v.v]=dis[u.to];
                    pq.push({v.v,v.line,dis[v.v]});
                }
            }else{
                if(u.to==s){
                    if(dis[v.v]>dis[u.to]+t[v.line][u.to]){
                        dis[v.v]=dis[u.to]+t[v.line][u.to];
                        pq.push({v.v,v.line,dis[v.v]});
                    }
                }else if(v.v==e){
                    if(dis[v.v]>dis[u.to]+2LL*t[v.line][u.to]){
                        dis[v.v]=dis[u.to]+2LL*t[v.line][u.to];
                        pq.push({v.v,0,dis[v.v]});
                    }
                }else{
                    if(dis[v.v]>dis[u.to]+t[u.curLine][u.to]+t[v.line][u.to]){
                        dis[v.v]=dis[u.to]+t[u.curLine][u.to]+t[v.line][u.to];
                        pq.push({v.v,v.line,dis[v.v]});
                    }
                }
            }
        }
    }
    cout<<dis[e]+w[s]+w[e]<<'\n';
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].reserve(k[i]+1);
        t[i].reserve(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            appear[a[i][j]].push_back(i);
        }
        for(int j=1;j<k[i];j++){
            g[a[i][j]].push_back({a[i][j+1],i,0});
        }
    }
    //for(int i=1;i<=m;i++){
      //  cout<<"Start point:"<<i<<"'s to:";
        //for(auto it:g[i]){
          //  cout<<it.v<<' ';
        //}
        //cout<<'\n';
    //}
    while(q--){
        int x,y;
        cin>>x>>y;
        dijkstra(x,y);
    }
    return 0;
}
