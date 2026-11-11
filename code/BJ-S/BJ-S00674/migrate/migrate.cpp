#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
int c,n;
ll d;
ll a[500010];
ll f[500010];
int cnt[500010];
vector<int>g[500010];
int ans;
void bfs(int s){
    queue<int>q;
    q.push(s);
    for(int i = 1;i <= n; i++){
        f[i] = 1e9;
        cnt[i] = 0;
    }
    cnt[s] = 1;
    f[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(f[v] > f[u]+1){
                f[v] = f[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            }else{
                if(f[v] == f[u] + 1){
                    cnt[v] += cnt[u];
                }
            }
        }
    }
    for(int i = s;i <= n; i++){
        if(cnt[i] == 2){
            ans++;
        }
    }
}
void solve(){
    ans = 0;
    cin >> n >>d;
    cnt[1] = 1;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        g[i].clear();
    }
    for(int i = 1;i < n; i++){
        for(int j = i+1;j <= n; j++){
            if(a[j] - a[i] <= d){
                g[i].push_back(j);
            }else{
                break;
            }
        }
    }
    for(int i = 1;i < n; i++){
        bfs(i);
        //for(int j  = 1;j <= n; j++){
        //    cout <<cnt[j] << ' ';
        //}
        //cout << '\n';
    }
    cout << ans << '\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}
