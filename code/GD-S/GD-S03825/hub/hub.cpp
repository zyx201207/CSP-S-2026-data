#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100;
int c, T, n, k, l, r, ishub[N], dis[N], vis[N];
vector<int> e[N];
void dfs(int x, int pa){
    for(int nxt : e[x]){
        if(nxt == pa) continue;
        if(dis[nxt] <= dis[x] + 1) continue;
        dis[nxt] = dis[x] + 1; dfs(nxt, x);
    }
}
void dfs_check(int x, int pa){
	vis[x] = 1;
	for(int nxt : e[x]){
        if(nxt == pa || !ishub[nxt]) continue;
        dfs_check(nxt, x);
    }
}
bool check(){
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) if(!vis[i] && ishub[i]) dfs_check(i, i), cnt++;
	return cnt <= 2;
}
void work_A(){
    cin >> n >> k;
    int nn = n / 2;
    for(int i = 1; i < n; i++) cin >> l >> r;
    if(n == k) return cout << 0 << '\n', void();
    if(k >= nn) return cout << 1 << '\n', void();
    return cout << (nn - k) / 4 + (((nn - k) % 4 != 0) ? 1 : 0) + 1 << '\n', void();
}
void work(){
    if(c == 13 || c == 14) return work_A();
    cin >> n >> k;
    int ans = n;
    for(int i = 1; i <= n; i++) e[i].clear();
    for(int i = 1; i < n; i++) cin >> l >> r, e[l].push_back(r), e[r].push_back(l);
    if(n == k) return cout << 0 << '\n', void();
    for(int i = 0; i < (1 << n); i++){
        if(__builtin_popcount(i) != k) continue;
        for(int j = 1; j <= n; j++) dis[j] = 1145141919, ishub[j] = 0;
        for(int j = 0; j < n; j++){
            ishub[j + 1] = (i >> j) & 1;
            if(ishub[j + 1]) dis[j + 1] = 0;
        }
        if(!check()) continue;
        for(int j = 1; j <= n; j++) if(ishub[j]) dfs(j, j);
        int tmp = 0;
        for(int j = 1; j <= n; j++) tmp = max(tmp, dis[j]);
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> T;
    for(int i = 1; i <= T; i++) work();
    cout << flush;
}
