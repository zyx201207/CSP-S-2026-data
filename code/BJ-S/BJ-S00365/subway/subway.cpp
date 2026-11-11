#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
long long c,n,m,d,q;
long long w[500010];
long long k[500010];
struct edge{
    pair <int,int> to;
    long long w;
};
struct three{
    long long x,y;
    long long z;
};
struct sta{
    vector <three> v;
}st[500010];
map <pair <int,int>,vector <edge> > g;
map <pair <int,int>,bool> vis;
map <pair <int,int>,long long> dis;
priority_queue <pair <long long,pair <int,int> > > pq;
long long dij(pair <int,int> x,pair <int,int> y){
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= k[i];j ++){
            dis[{i,j}] = 1e18;
            vis[{i,j}] = 0;
        }
    }
    pq.push({0,{x.first,x.second}});
    vis[{x.first,x.second}] = 0;
    dis[{x.first,x.second}] = 0;
    while(!pq.empty()){
        pair <int,int> x = pq.top().second;
        pq.pop();
        if(vis[x]){
            continue;
        }
        vis[x] = 1;
        for(auto it : g[x]){
            pair <int,int> y = it.to;
            long long w = it.w;
            if(dis[x] + w < dis[y]){
                dis[y] = dis[x] + w;
                pq.push({-dis[y],y});
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j ++){
            long long a = 0,t = 0;
            cin >> a >> t;
            st[a].v.push_back((three){i,j,t});
            if(j != 1){
                g[{i,j}].push_back((edge){{i,j - 1},0});
            }
            if(j != k[i]){
                g[{i,j}].push_back((edge){{i,j + 1},0});
            }
        }
    }
    for(int i = 1;i <= m;i ++){
        for(long long x = 0;x < st[i].v.size();x ++){
            for(long long y = x + 1;y < st[i].v.size();y ++){
                g[{st[i].v[x].x,st[i].v[x].y}].push_back((edge){{st[i].v[y].x,st[i].v[y].y},st[i].v[x].z + st[i].v[y].z});
                g[{st[i].v[y].x,st[i].v[y].y}].push_back((edge){{st[i].v[x].x,st[i].v[x].y},st[i].v[x].z + st[i].v[y].z});
            }
        }
    }
    while(q --){
        long long rx = 0,ry = 0;
        long long ans = 1e18;
        cin >> rx >> ry;
        for(int i = 0;i < st[rx].v.size();i ++){
            for(int j = 0;j < st[ry].v.size();j ++){
                ans = min(ans,w[rx] + w[ry] + st[rx].v[i].z + st[ry].v[j].z + dij({st[rx].v[i].x,st[rx].v[i].y},{st[ry].v[j].x,st[ry].v[j].y}));

            }
        }
        cout << ans << endl;
    }
    return 0;
}