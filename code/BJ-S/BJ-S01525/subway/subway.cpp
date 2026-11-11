#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int M=5e5+5,N=1e5+5;
int a[M];
int c,n,m,d,q;
struct edge{
    int v,w;
};
vector<edge> mp[M+N];
bool vis[M+N];
struct dij{
    int u,w;
    bool operator <(const dij &a)const{
        return w>a.w;
    }
};
priority_queue<dij> p;
int dijkstra(int x,int y){
    dij tmp;
    tmp.u=x;
    tmp.w=0;
    p.push(tmp);
    while(!p.empty()){
        dij t=p.top();
        p.pop();
        int u=t.u,w=t.w;
        if(vis[u])continue;
        vis[u]=1;
        if(u>m){
            for(int i=0;i<mp[u].size();i++){
                if(!vis[mp[u][i].v]&&(mp[mp[u][i].v].size()>1||mp[u][i].v==y)){
                    dij pu;
                    pu.u=mp[u][i].v;
                    pu.w=w+mp[u][i].w;
                    p.push(pu);
                }
            }
        }
        else{
            if(u==y){
                return w;
            }
            for(int i=0;i<mp[u].size();i++){
                if(!vis[mp[u][i].v]){
                    dij pu;
                    pu.u=mp[u][i].v;
                    pu.w=w+mp[u][i].w;
                    p.push(pu);
                }
            }
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            edge u,v;
            cin>>u.v>>u.w;
            v.w=u.w;
            v.v=m+i;
            mp[m+i].push_back(u);
            mp[u.v].push_back(v);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=a[x]+a[y];
        ans+=dijkstra(x,y);
        cout<<ans<<endl;
        while(!p.empty())p.pop();
        for(int i=1;i<=m+n;i++)vis[i]=0;
    }
    return 0;
}
