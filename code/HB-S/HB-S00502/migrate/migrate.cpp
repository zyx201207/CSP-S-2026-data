#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int a[N], in[N], dis[N], num[N], ii[N]; vector<int> e[N], r[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t; cin >> c >> t; while(t--) {
        int n, d; cin >> n >> d; int ans = 0;
        for(int i = 1;i <= n;i++) e[i].clear(), r[i].clear(), in[i] = 0;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int cnt = 0;
        for(int i = n;i >= 1;i--) {
            for(int j = i+1;j <= n;j++)
                if((a[j] - a[i]) <= d) e[i].push_back(j), in[j]++, r[j].push_back(i);
            for(int j = 1;j <= n;j++) ii[j] = in[j];
            for(int j = i;j <= n;j++) dis[j] = 1e18;
            for(int j = i;j <= n;j++) num[j] = 0;
            // for(int j = 1;j <= n;j++) cout << in[j] << " \n"[j == n];
            queue<int> q, w; q.push(i), dis[i] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop(); w.push(u); // cout << u << " ";
                for(auto v : e[u]) {
                    in[v]--;
                    if(in[v] == 0) q.push(v);
                } 
            }while(!w.empty()) {
                int u = w.front(); w.pop();
                if(r[u].size() == 0) { dis[u] = 0, num[u] = 1; continue; }
                for(auto x : r[u]) {
                    dis[u] = min(dis[u], dis[x] + 1);
                }  for(auto x : r[u]) {
                    if((dis[x] + 1) == dis[u]) num[u] += num[x];
                }
            }
            for(int j = i;j <= n;j++) cnt += (num[j] == 2);
            for(int j = 1;j <= n;j++) in[j] = ii[j];
        } cout << cnt << endl;
    }
    return 0;
}