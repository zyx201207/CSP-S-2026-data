#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int c,n,m,d,q;
long long W[500010];
struct node{
    int v;
    long long w;
};
vector<node> g[500510];
long long dis[500010];
struct point{
    int p;
    long long dis;
    bool operator < (const point a) const{
        return dis<a.dis;
    }
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>W[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v;
            long long w;
            cin>>v>>w;
            g[m+i].push_back({v,w});
            g[v].push_back({m+i,w});
        }
    }
    for(int R=1;R<=q;R++){
        int s,e;
        cin>>s>>e;
        memset(dis,0x3f,sizeof dis);
        priority_queue<point> q;
        q.push({s,0});
        dis[s]=0;
        while(!q.empty()){
            point tmp=q.top();
            q.pop();
            int u=tmp.p;
            for(int i=0;i<g[u].size();i++){
                int v=g[u][i].v;
                long long w=g[u][i].w;
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    q.push({v,dis[v]});
                }
            }
        }
        cout<<dis[e]+W[s]+W[e]<<endl;
    }
    return 0;
}
