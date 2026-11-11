#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int M = 5e5 + 5;
const int Q = 5e5 + 5;
int w[M];
bool vis[2 * M];
P a[Q];
vector<P> g[2 * M];

int dijkstra(int x, int y){
    memset(vis, false, sizeof(vis));
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, x));
    while(!q.empty()){
        int num = q.top().first, cur = q.top().second;
        q.pop();
        if(cur == y)
            return num + w[x] + w[y];
        for(const P v : g[cur]){
            if(vis[v.first])
                continue;
            vis[v.first] = true;
            q.push(make_pair(num + v.second, v.first));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //priority_queue
    //auto t = clock();
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1, k; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            g[a].push_back(make_pair(m + i, t));
            g[m + i].push_back(make_pair(a, t));
        }
    }
    for(int i = 1; i <= q; i++)
        cin >> a[i].first >> a[i].second;
    for(int i = 1; i <= q; i++)
        cout << dijkstra(a[i].first, a[i].second) << '\n';
    //cout << clock() - t;
}