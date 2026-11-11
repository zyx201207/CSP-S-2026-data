#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct node{
    int to,w;
};
vector<node> f[500505];
int o,n,m,d,q;
int st,ed;
int w[505];
bool vis[500505];
long long dis[500505];
void dij(int st){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[st]=0;
    while(1){
        int u=-1;
        for(int i=1;i<=m+n;i++){
            if(vis[i]==0&&(u==-1||dis[i]<dis[u])){
                u=i;
            }
        }
        if(u==-1)  break;
        vis[u]=1;
        for(node e:f[u]){
            if(vis[e.to]==0){
                dis[e.to]=min(dis[e.to],dis[u]+e.w);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>o>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,t;i<=n;i++){
        int la;
        cin>>t;
        for(int j=1;j<=t;j++){
            int a,w;
            cin>>a>>w;
            a=n+a;
            //cout<<a<<" "<<w<<"\n";
            f[i].push_back({a,w});
            f[a].push_back({i,w});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>st>>ed;
        dij(n+st);
        cout<<dis[n+ed]+w[st]+w[ed]<<"\n";
    }
    return 0;
}
