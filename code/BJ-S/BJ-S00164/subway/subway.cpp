#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define maxv 500010
const long long inf = 2147483647;
struct Edge{
    int u,v;
    long long w;
};
struct Sta{
    int ln;
    long long t;
};
vector<Edge> edg[maxn];
int c,n,m,d,q;
long long w[maxv];
vector<Sta> st[maxv];
long long dis[maxn][maxn];
bool vis[maxn];
long long ans = 0;
long long len[maxn][maxn];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > que;
void dijkstra(int s){
    memset(vis,false,sizeof(vis));
    memset(dis[s],0x3f,sizeof(dis[s]));
    while(!que.empty()){
        que.pop();
    }
    dis[s][s] = 0;
    que.push(make_pair(0,s));
    while(!que.empty()){
        int u = que.top().second;
        que.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = true;
        for(int i = 0;i < edg[u].size();i++){
            int v = edg[u][i].v;
            if(dis[s][u] + edg[u][i].w < dis[s][v]){
                dis[s][v] = dis[s][u] + edg[u][i].w;
                que.push(make_pair(dis[s][v],v));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cout << inf << endl;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            len[i][j] = inf;
        }
    }
    for(int i = 1;i <= n;i++){
        int v;
        cin >> v;
        for(int j = 1;j <= v;j++){
            int num;
            long long val;
            cin >> num >> val;
            for(auto u : st[num]){
                len[u.ln][i] = min(len[u.ln][i],u.t + val);
                len[i][u.ln] = min(len[i][u.ln],u.t + val);
            }
            st[num].push_back((Sta){i,val});
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(len[i][j] != inf){
                edg[i].push_back((Edge){i,j,len[i][j]});
                edg[j].push_back((Edge){j,i,len[i][j]});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        dijkstra(i);
    }
    //cout << 666 << endl;
    for(int i = 1;i <= q;i++){
        ans = 0;
        long long res = inf;
        int bg,ed;
        cin >> bg >> ed;
        for(auto x : st[bg]){
            int sigx = x.ln;
            for(auto y : st[ed]){
                int sigy = y.ln;
                res = min(res,x.t + dis[sigx][sigy] + y.t);
            }
        }
        ans = res + w[bg] + w[ed];
        cout << ans << endl;
    }
    return 0;
}
