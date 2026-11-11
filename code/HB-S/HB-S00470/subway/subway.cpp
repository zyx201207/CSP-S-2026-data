#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,ans;
int k[510];
queue<int>qx;
queue<int>ql;
queue<int>qt;
int w[500010];
vector<int>a[510];
vector<int>t[510];
int dis[500010][510];
vector<int>pa[500010];
vector<int>pat[500010];
void mnpa(int bg,int tar){
    memset(dis,127,sizeof(dis));
    while (!qx.empty())qx.pop();
    while (!ql.empty())ql.pop();
    dis[bg][0]=w[bg];
    qx.push(bg);
    ql.push(0);
    qt.push(0);
    while (!qx.empty()){
        int x=qx.front();
        int xl=ql.front();
        int xt=qt.front();
//        printf("dis[%d][%d]=%d\n",x,xl,dis[x][xl]);
        qx.pop();
        ql.pop();
        qt.pop();
        if (x==tar){
            ans=min(ans,dis[tar][xl]+xt+w[tar]);
            continue;
        }
        int len=pa[x].size();
        for (int i=0;i<len;i++){
            int yl=pa[x][i];
            int tyl=pat[x][i];
            int mn=0;
            if (xl!=yl)mn=dis[x][xl]+xt+tyl;
            else mn=dis[x][xl];
            for (int j=0;j<k[yl];j++){
                int y=a[yl][j];
                int yt=t[yl][j];
                if (mn<dis[y][yl]){
                    dis[y][yl]=mn;
                    qx.push(y);
                    ql.push(yl);
                    qt.push(yt);
                }
            }
        }
    }
}

struct yz{
    int y,z;
};

int vis[510];
int dist[510];
vector<yz>edge[510];
void dijkstra(int x,int y){
    memset(dist,127,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dist[0]=1;
    for (int step=1;step<=m;step++){
        int mn=1e9,p=-1;
        for (int i=1;i<=n;i++){
            if (!vis[i] && dist[i]<mn){
                mn=dist[i];
                p=i;
            }
        }
        vis[p]=1;
        if (p==-1 || p==y)break;
        for (auto [y,z]:edge[x]){
            if (dist[x]+z<dist[y]){
                dist[y]=dist[x]+z;
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    if (7<=c && c<=11){
        for (int i=1;i<=m;i++){
            scanf("%d",&w[i]);
        }
        for (int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for (int j=1;j<=k;j++){
                int x,y;
                scanf("%d%d",&x,&y);
                a[i].push_back(x);
                t[i].push_back(y);
            }
            for (int j=1;j<k;j++){
                edge[a[i][j]].push_back({a[i][j+1],t[i][j]+t[i][j+1]});
                edge[a[i][j+1]].push_back({a[i][j],t[i][j]+t[i][j+1]});
            }
            while (q--){
                int x,y;
                scanf("%d%d",&x,&y);
                dijkstra(x,y);
            }
        }
        return 0;
    }
    for (int i=1;i<=m;i++){
        scanf("%d",&w[i]);
        pa[i].push_back(0);
        pat[i].push_back(0);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for (int j=1;j<=k[i];j++){
            int x,y;
            scanf("%d%d",&x,&y);
            pa[x].push_back(i);
            pat[x].push_back(y);
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    while (q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ans=1e9;
        mnpa(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
/*20TLE*/

