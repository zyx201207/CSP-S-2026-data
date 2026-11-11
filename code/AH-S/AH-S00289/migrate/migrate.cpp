#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, ans, cnt, step, mx[N];
long long d, x[N];
vector<int> g[N];
void dfs(int u, int mb, int sp){
    if(u == mb && sp == step){
        cnt++;
        return;
    }
    for(int e : g[u]){
        if(e > mb) continue;
        dfs(e, mb, sp + 1);
    }
}
bool check(int st, int ed){
    step = 0;
    int pos = st;
    while(pos < ed){
        if(mx[pos] == pos){
            return false;
        }
        pos = mx[pos];
        step++;
    }
    cnt = 0;
    dfs(st, ed, 0);
    if(cnt == 2) return true;
    return false;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(x[j] - x[i] <= d){
                    g[i].push_back(j);
                }else{
                    mx[i] = j - 1;
                    break;
                }
            }
            if(mx[i] == 0) mx[i] = n;
        }
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(check(i, j)){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1 ; i < n; i++){
            mx[i] = 0;
        }
        ans = cnt = step = 0;
    }

    return 0;
}
