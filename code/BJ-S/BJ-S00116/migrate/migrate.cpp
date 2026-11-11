#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, SMALL = 3e2 + 5;
long long C, T, n, d, X[N], dis[SMALL], vis[SMALL], ans;
bool check(long long x, long long y){
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[x] = 0, vis[y] = 1;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long > > > pq;
    pq.push(make_pair(0, x));
    while (!pq.empty()){
        long long dist = pq.top().first, u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        for (int i = u + 1; i <= y; i ++)
            if (X[i] - X[u] <= d && dis[i] > dist + 1){
                dis[i] = dist + 1;
                pq.push(make_pair(dist + 1, i));
            }
    }
    long long cnt = 0;
    queue<pair<long long, long long> > Q;
    Q.push(make_pair(0, x));
    while (!Q.empty()){
        long long dist = Q.front().first, u = Q.front().second;
        Q.pop();
        if (u == y && dist == dis[y]){
            cnt ++;
            continue;
        }
        for (int i = u + 1; i <= y; i ++)
            if (X[i] - X[u] <= d && dis[i] == dist + 1)
                Q.push(make_pair(dist + 1, i));
            else if (X[i] - X[u] > d)
                break;
    }
    return cnt == 2;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> C >> T;
    while (T --){
        cin >> n >> d;
        for (int i = 1; i <= n; i ++)
            cin >> X[i];
        if (C <= 6){
            ans = 0;
            for (int i = 1; i < n; i ++)
                for (int j = i + 1; j <= n; j ++)
                    if (check(i, j))
                        ans ++;
            cout << ans << "\n";
        } else cout << "0\n";
    }
    return 0;
}
