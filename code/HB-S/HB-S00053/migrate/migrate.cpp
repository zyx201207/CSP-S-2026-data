#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 20;
int A[N], dist[N], cnt[N], vis[N];
int n, d;
int c, t;
void dfs(int pos, int step){
    if(step < dist[pos]) dist[pos] = step, cnt[pos] = 1;
    else if(step == dist[pos]) ++cnt[pos];
    for(int i = 1; i <= n; ++i)
    if(!vis[i] && abs(A[i] - A[pos]) <= d){
        vis[i] = true;
        dfs(i, step + 1);
        vis[i] = false;
    }
}
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> A[i];
    int ans = 0;

if(c != 11 && c != 12){
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j) dist[j] = INT_MAX, cnt[j] = 0, vis[j] = false;
        vis[i] = true;
        dfs(i, 0);
        vis[i] = false;
        for(int j = i; j <= n; ++j){
            if(cnt[j] == 2) ++ans;
        }
    }
    cout << ans << endl;
}
else{
    int step = 0;
    while(abs(A[step + 1] - A[1]) <= d) ++step;
    if(step <= 2) cout << "0\n";
    else cout << max(0LL, n - step * 2 + 3) << endl;
}

}
signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}
