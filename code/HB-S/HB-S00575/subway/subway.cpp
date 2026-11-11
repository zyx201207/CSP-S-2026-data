#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
const ll INF = 1e18;
const int maxm = 5e5 + 5;
struct Node{
    int idx;
    vector<int> nxt; // 该节点的子结点
    int etr; // 作为入口使用的时间，即题面中的w
    vector<int> rte; // 在哪几条线路中
    unordered_map<int, int> tme; // 表示作为第几条线路, 该条线路站台到站厅所用时间
} SU[maxm];
struct qpqp{ // pq使用
    int id; // 节点编号
    int cur; // 当前的线路
    ll w; // 目前的边权
    bool operator <(const qpqp& other) const{
        return w > other.w;
    }
};
void read(int& x){
    x = 0;
    int f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}
int c, n, m, d, q;
ll dis[maxm];
bool vis[maxm];
void dij(int st){
    fill(dis + 1, dis + m + 1, INF);
    dis[st] = 0;
    vis[st] = true;
    priority_queue<qpqp> pq;
    for(int x : SU[st].rte){
        pq.push({st, x, 0});
    }
    while(!pq.empty()){
        qpqp tmp = pq.top();
        pq.pop();
        if(vis[tmp.id]) continue;
        for(int v : SU[tmp.id].nxt){
            ll wei;
            bool flag = false;
            for(int i = 0; i < SU[v].rte.size(); ++i){
                int tt = SU[v].rte[i];
                if(tt == tmp.cur) wei = 0;
                else wei = SU[v - 1].tme[tt] + SU[v - 1].tme[tmp.cur];
                if(dis[v] > dis[tmp.id] + wei){
                    dis[v] = dis[tmp.id] + wei;
                    pq.push({v, tt, dis[v]});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c), read(n), read(m), read(d), read(q);
    for(int i = 1; i <= m; ++i){
        cin >> SU[i].etr;
    }
    int k;
    for(int i = 1; i <= n; ++i){
        read(k);
        for(int j = 1; j <= k; ++j){
            int id, t;
            read(id), read(t);
            SU[id].rte.push_back(i);
            SU[id].tme[i] = t;
            SU[id].idx = id;
            if(j >= 2){
                SU[SU[j - 1].idx].nxt.push_back(id);
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        dij(x);
        cout << SU[x].etr + dis[y] + SU[y].etr + SU[x].tme[1] + SU[y].tme[1] << '\n';
    }
    return 0;
}