#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int c,n,m,d,q,x,dis[500005];
bool vis[500005];
struct Edge{
    int v,time;
    bool operator<(Edge a){
        return time<a.time;
    }
    bool operator>(Edge a){
        return time>a.time;
    }
};
vector<int> ans;
vector<Edge> E[500505];
vector<int> N;
void addEdge(int u,int v,int time){
    E[u].push_back((Edge){v,time});
    E[v].push_back((Edge){u,time});
}
struct dui{
    vector<Edge> N;
    dui(){
        N.push_back((Edge){0,0});
    }
    void push(Edge n){
        int p=N.size();
        N.push_back(n);
        while(N[p/2]<N[p]&&p!=1){
            swap(N[p/2],N[p]);
            p/=2;
        }
    }
    Edge top(){
        return N[1];
    }
    void pop(){
        swap(N[1],N[N.size()-1]);
        N.pop_back();
        int p=1;
        while(p*2<N.size()){
            if(p*2+1<N.size())
                if(N[p*2]>N[p*2+1]&&N[p]>N[p*2+1]){
                    swap(N[p],N[p*2+1]);
                    p=p*2+1;
                }
                else if(N[p]>N[p*2]){
                    swap(N[p],N[p*2]);
                    p*=2;
                }
            if(N[p]>N[p*2]){
                swap(N[p],N[p*2]);
                p*=2;
            }
        }
    }
    bool empty(){
        return !(N.size()-1);
    }
};
void dij(int start,int end){
    memset(dis,0x7f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dui q;
    for(Edge i:E[start])
        q.push(i);
    vis[start]=1;
    dis[start]=0;
    while(!q.empty()){
        int now=q.top().v;
        for(Edge i:E[now]){
            if(!vis[i.v]){
                vis[i.v]=1;
                dis[i.v]=dis[now]+i.time;
                if(i.v==end) return;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>x;
        N.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int num,v,t;
        for(int i=1;i<=num;i++){
            cin>>v>>t;
            addEdge(i+m,v,t);
        }
    }
    for(int i=1;i<n;i++){
        addEdge(i+m,i+m+1,0);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        dij(u,v);
        cout<<N[u]+dis[v]+N[v]<<"\n";
    }
    return 0;
}