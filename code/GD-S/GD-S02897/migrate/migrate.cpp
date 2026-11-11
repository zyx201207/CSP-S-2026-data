#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int N = 2e6 + 10;
int c, t, n, d, a[N], cnt, ans, mnl, vis[305];
void bfs(int x, int y) {
    queue<pi> q;
	memset(vis, 0x3f, sizeof vis);
    vis[x] = 0;
    q.push({x, 0});
    while(!q.empty()) {
        pi t = q.front(); q.pop();
        int u = t.first;
        if(t.second > mnl) continue;
        if(u == y) {
            cnt++;
            if(t.second < mnl) {
                mnl = t.second;
                cnt = 1;
            }
            continue;
        }
        for(int v = u + 1; v <= n && a[v] - a[u] <= d; v++) q.push({v, t.second + 1});
    }
}
bool chk(int a[]) {
    bool res = 1;
    for(int i = 3; i <= n; i++) res &= (a[2] - a[1] == a[i] - a[i - 1]);
    return res;
}
void sol() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n <= 300) {
    	ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                cnt = 0;
                mnl = 1e9;
                bfs(i, j);
                ans += (cnt == 2);
            }
        }
        cout << ans << endl;
    }
    else cout << 0 << endl;
}
int main() {
	ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--) sol();
	return 0;
}