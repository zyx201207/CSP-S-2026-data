#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long c, n, m, d, q, dis[N];
int w[N];
vector< pair<int, int> > e[N];    // t, num
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
void bfs(int x){
    memset(dis, -1, sizeof(dis));
    dis[x] = 0;
    pq.push({0, x});
    while(pq.size()){
        auto a = pq.top(); pq.pop();
        for(auto b : e[a.second])
            if(dis[b.second] == -1 || a.first + b.first < dis[b.second]){
                dis[b.second] = a.first + b.first;
                pq.push({dis[b.second], b.second});
            }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        int a[N], t[N];
        for(int j = 1; j <= k; j++) cin >> a[j] >> t[j];
        for(int j = 1; j <= k-1; j++)
            for(int z = j; z <= k; z++){
                e[a[j]].push_back({t[j] + t[z], a[z]});
                e[a[z]].push_back({t[j] + t[z], a[j]});
            }
    }
    while(q--){
        int x, y; cin >> x >> y;
        bfs(x);
        cout << dis[y] + w[x] + w[y] << '\n';
    }
    return 0;
}