#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct edge{
    int v;
    long long w;
    bool operator < (const edge &s) const{
        return s.w < w;
    }
};
int cnt;
long long w[N];
unordered_map<int,int> mp;
vector<edge> g[N << 1];
int vis[N << 1];
long long dis[2005][2005];
priority_queue<edge> pq;
void dij(int s){
    for(int i = 1;i <= cnt;i++){
        dis[s][i] = 1e18;
        vis[i] = 0;
    }
    dis[s][s] = 0;
    pq.push({s,0});
    while(!pq.empty()){
        int u = pq.top().v;
        pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = 1;
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i].v;
            long long w = g[u][i].w;
            if(dis[s][v] > dis[s][u] + w){
                dis[s][v] = dis[s][u] + w;
                pq.push({v,dis[s][v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i <= n;i++){
        int k;
        scanf("%d",&k);
        int las = 0;
        for(int j = 1;j <= k;j++){
            int a;
            long long t;
            scanf("%d%lld",&a,&t);
            if(!mp.count(a)){
                mp[a] = ++cnt;
            }
            cnt++;
            g[cnt].push_back({mp[a],t});
            g[mp[a]].push_back({cnt,t});
            if(j != 1){
                g[las].push_back({cnt,0});
                g[cnt].push_back({las,0});
            }
            las = cnt;
        }
    }
    for(int i = 1;i <= cnt;i++){
        if(mp.count(i)){
            dij(mp[i]);
        }
    }
    for(int i = 1;i <= q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",dis[mp[x]][mp[y]] + w[x] + w[y]);
    }

    return 0;
}