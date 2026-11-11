#include <bits/stdc++.h>
using namespace std;
//g++ subway.cpp -o subway -std=c++14 -Wall -O2

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 5e5 + 5;
int n, m, D, Q, subtask;
int head[N+500];
ll way[N];

int done[N+500];
ll dis[N+500];

struct edge{
    int to, nxt;
    ll w;
}e[N*20*2];

int cnt = 0, tot = 0;

void add(int u, int v, ll w){
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

struct node{
    int id; ll dis;
    bool operator < (const node &o) const {
        return dis > o.dis;
    }
};

void dijkstra(int s){
    for(int i=1; i<=tot; i++){
        dis[i] = INF;
        done[i] = 0;
    }
    priority_queue <node> q;
    dis[s] = 0;
    q.push({s, dis[s]});
    while(!q.empty()){
        node u = q.top();
        q.pop();
        if(done[u.id]) continue;
        done[u.id] = 1;
        for(int i=head[u.id]; i; i=e[i].nxt){
            int v = e[i].to;
            ll w = e[i].w;
            if(done[v]) continue;
            if(dis[v] > u.dis + w){
                dis[v] = u.dis + w;
                q.push({v, dis[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("subway6.in", "r", stdin);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>subtask>>n>>m>>D>>Q;
    for(int i=1; i<=m; i++){
        cin>>way[i];
    }
    tot = m;
    for(int i=1; i<=n; i++){
        int k, u = ++tot;
        cin>>k;
        for(int j=1; j<=k; j++){
            int v; ll w;
            cin>>v>>w;
            add(u, v, w);
            add(v, u, w);
        }
    }
    while(Q--){
        int s, ed;
        cin>>s>>ed;
        dijkstra(s);
        ll ans = way[s] + way[ed] + dis[ed];
        cout<<ans<<'\n';
    }
    return 0;
}