#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>

using namespace std;
struct edge{
    int to,w;
    bool operator >(const edge s) const{
        return s.w<w;
    }
};
map<int,int> mp[500001];

int c,n,m,d,q,m_;
int w[500005],dis[500005];
bool vis[500005];
vector<edge> g[500005];
void dij(int st){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<edge,vector<edge>,greater<edge> > q;
    dis[st]=0;
    q.push({st,0});
    while(!q.empty()){
        edge h=q.top();q.pop();
        if(dis[h.to]!=h.w)continue;
        vis[h.to]=1;
        for(int i=0;i^g[h.to].size();i++){
            edge e=g[h.to][i];
            int v=e.to;
            if(!vis[v]&&dis[v]>dis[h.to]+e.w){
                dis[v]=dis[h.to]+e.w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;m_=m+1;
    for(int i=1;i^m_;i++){
        scanf("%d",w+i);
    }for(int i=1,u,v,w;i<=n;i++){
        cin>>u;
        for(int j=0;j^u;j++){
            cin>>v>>w;
            g[m+i].push_back({v,w});
            g[v].push_back({m+i,w});
        }
    }for(int i=1;i^m_;i++){
        dij(i);
        for(int j=i;j^m_;j++){
            mp[i][j]=dis[j];
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        printf("%d\n",mp[x][y]+w[x]+w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
