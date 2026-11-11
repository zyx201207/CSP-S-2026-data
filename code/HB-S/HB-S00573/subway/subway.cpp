#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
using ull=unsigned long long;
using pui=pair<ull,int>;
const int M=5e5+10,N=1010;
int c,n,m,d,q,w[M];
int ecnt,hd[N+M];
struct edge{
    int nxt,to,wt;
}e[N+M];
void addedge(int u,int v,int wt){
    e[++ecnt]={hd[u],v,wt};
    hd[u]=ecnt;
}
ull f[N][N];
namespace case1_6{
    void floyd(){
        for(int i=1;i<=n;i++){
            int k; cin>>k;
            while(k--){
                int a,t; cin>>a>>t;
                addedge(a,m+i,t);
                addedge(m+i,a,t);
            }
        }
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n+m;i++){
            f[i][i]=0;
            for(int j=hd[i];j;j=e[j].nxt) f[i][e[j].to]=min((int)f[i][e[j].to],e[j].wt);
        }
        for(int k=1;k<=n+m;k++)
            for(int i=1;i<=n+m;i++)
                for(int j=1;j<=n+m;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        for(int i=1;i<=q;i++){
            int x,y; cin>>x>>y;
            cout<<f[x][y]+w[x]+w[y]<<endl;
        }
    }
};
namespace case7_11{
    priority_queue<pui,vector<pui>,greater<pui>>que;
    ull dis[N];
    bool vis[N];
    void dijkstra(int x){
        memset(dis,0x3f,sizeof(dis));
        dis[x]=0;
        memset(vis,0,sizeof(vis));
        que.emplace(0,x);
        while(!que.empty()){
            ull udis=que.top().first;
            int uv=que.top().second;
            que.pop();
            if(vis[uv]) continue;
            vis[uv]=1;
            for(int i=hd[uv];i;i=e[i].nxt) if(dis[e[i].to]>udis+e[i].wt){
                dis[e[i].to]=udis+e[i].wt;
                que.emplace(dis[e[i].to],e[i].to);
            }
        }
        for(int i=1;i<=m;i++) f[x][i]=dis[i];
    }
    void dloyd(){
        for(int i=1;i<=n;i++){
            int k,a1,t1,a2,t2; cin>>k;
            if(k==1) cin>>a1>>t1;
            else{
                cin>>a1>>t1>>a2>>t2;
                addedge(a1,a2,t1+t2);
                addedge(a2,a1,t1+t2);
            }
        }
        for(int i=1;i<=m;i++) dijkstra(i);
        for(int i=1;i<=q;i++){
            int x,y; cin>>x>>y;
            cout<<f[x][y]+w[x]+w[y]<<endl;
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c<=6) case1_6::floyd();
    else if(c<=11) case7_11::dloyd();
    return 0;
}