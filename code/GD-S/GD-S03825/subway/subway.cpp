#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 600, M = 550000;
int c, n, m, d, q, s, t, w[M], k[N], dist[N][N];
int t1, t2;
unordered_map<int, int> enter_time[M];
vector<int> can_reach_line[M];
vector<pii> line_graph[N];
vector<pii> line[N]; // first:station second:time
int work(){
    int ans = 1145141919810000721;
    for(int i = 0; i < can_reach_line[s].size(); i++) for(int j = 0; j < can_reach_line[t].size(); j++){
        int line1 = can_reach_line[s][i], line2 = can_reach_line[t][j];
        ans = min(ans, dist[line1][line2] + enter_time[s][line1] + enter_time[t][line2]);
    } 
    return ans;
}
void build_line_graph(){ //只提取路径点，放弃中间站点，建图
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dist[i][j] = 1145141919810000721;
    for(int i = 1; i <= n; i++){
        for(pii station : line[i]){
            int id = station.first, cost = station.second;
            for(int nxtid : can_reach_line[id]){
                dist[nxtid][i] = dist[i][nxtid] = min(dist[i][nxtid], enter_time[id][nxtid] + cost);
            }
        }
    }
}
void floyd(){ //n = 500的全源最短路，floyd即可
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                dist[j][k] = min(dist[j][k], dist[i][j] + dist[i][k]);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            cin >> t1 >> t2, line[i].push_back({t1, t2});
            enter_time[t1][i] = t2; //统计站点进线时间，解放站点间距离
            can_reach_line[t1].push_back(i); //统计站点可达的所有路径点
        }
    }
    build_line_graph();
    floyd();
    for(int i = 1; i <= q; i++){
        cin >> s >> t;
        cout << w[s] + w[t] + work() << '\n';
    }
    cout << flush;
}
//复杂度O(n^3 + \sigmakd + qd^2) 极限数据下约2e8，可能超时。
//能否优化？
//复杂度瓶颈在于floyd，换成dijkstra？
//可能存在稠密图情况，此时dijkstra可能不优。
//并且代码量上升，我认为没有必要。毕竟22，23数据点与24，25数据点的差距在于d，但2到20带来的运算次数提升约为500000*18+396*100000=4.8e7
//本机22，23数据点0.44秒，该改动带来的时间增加不明显。
//最后决定：不改动floyd。