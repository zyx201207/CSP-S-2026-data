#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = int(50);
const int MAXM = int(1e5)+5;

struct node{
    int e;
    int t[MAXN];
    int cnt = 0;
}dots[MAXM];
struct To{
    int v;
    int line;
};
int a[MAXN][MAXM];
int sz[MAXN];// 编号为i的线路长度
int dis[MAXN];
bool vis[MAXN];
vector<To> g[MAXM];

int C,n,d,m,Q;

int bfs(int start,int end){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    queue<To> q;
    while(!q.empty())   q.pop();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sz[i];j++){
            if(a[i][j] == start){
                q.push({start,i});
            }
        }
    }
    vis[start] = true;
    dis[start] = 0;
    while(!q.empty()){
        To nod = q.front();
        q.pop();
        int u = nod.v;
        int lines = nod.line;
        for(auto ed:g[u]){
            if(dis[ed.v] > (ed.line!=lines)*(dots[u].t[lines]+dots[u].t[ed.line])+dis[u]){
                dis[ed.v] = (ed.line!=lines)*(dots[u].t[lines]+dots[u].t[ed.line])+dis[u];
                q.push({ed.v,lines});
            }
            cout << ed.v << " " << lines << " " << dis[ed.v] << endl;
        }
    }
    return dis[end]+dots[start].e+dots[end].e;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> C >> n >> m >> d >> Q;
    for(int i = 1;i<=m;i++){
        cin >> dots[i].e;
    }
    for(int i = 1;i<=n;i++){
        cin >> sz[i];
        a[i][0] = 0;
        for(int j = 1;j<=sz[i];j++){
            cin >> a[i][j] >> dots[a[i][j]].t[i];
            dots[a[i][j]].cnt++;
            g[a[i][j-1]].push_back({a[i][j],i});
            if(a[i][j-1])   g[a[i][j]].push_back({a[i][j-1],i});
        }
    }
    g[0].clear();
    for(int i = 1;i<=Q;i++){
        int u,v;
        cin >> u >> v;
        cout << bfs(u,v) << endl;
    }
    return 0;
}