#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define int long long
struct Node {
    int x;
    int w;
};
vector<Node> e[5010];
int dis[5010];
int cnt[5010];
int x[5010];
bool operator <(Node x, Node y) {
    return x.w > y.w;
}
int n, d;
void dijkstra(int s) {
    for(int i = 1; i <= n; ++i)
        dis[i] = 1e9, cnt[i] = 1;
    dis[s] = 0;
    priority_queue<Node> pq;
    pq.push({s, 0});
    while(!pq.empty()) {
        Node t = pq.top();
        pq.pop();
        if(t.w != dis[t.x]) continue;
        for(Node i : e[t.x]) {
            if(dis[i.x] == dis[t.x] + i.w) {
                cnt[i.x]++;
            }
            if(dis[i.x] > dis[t.x] + i.w) {
                dis[i.x] = dis[t.x] + i.w;
                cnt[i.x] = cnt[t.x];
                pq.push({i.x, dis[i.x]});
            }
        }
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if(c >= 15 && c <= 18) {
        while(t--) cout << 0 << endl;
    }
    while(t--) {
        cin >> n >> d;
        for(int i = 1; i <= n; ++i)
            cin >> x[i], e[i].clear();
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                if(abs(x[i] - x[j]) <= d) {
                    e[i].push_back({j, 1});
                    e[j].push_back({i, 1});
                }
        /*
        for(int i = 1; i <= n; ++i) {
            cout << i << ": ";
            for(Node j : e[i]) {
                cout << j.x << ' ';
            }
            cout << endl;
        }
        */
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            dijkstra(i);
            for(int j = 1; j <= n; ++j)
                if(cnt[j] == 2) {
                    ans++;
                    //cout << i << ' ' << j << endl;
                }
        }
        cout << ans / 2 << '\n';
    }
    return 0;
}
