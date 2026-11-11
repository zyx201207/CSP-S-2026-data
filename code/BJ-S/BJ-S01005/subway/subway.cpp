#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
bool vis[MAXN];
int w[MAXN];
int a[505][MAXN],t[505][MAXN];
int start,ending;
int ans = 0;
int c,n,m,d,q;
vector<int> ve[MAXN];
int dfs(int v,int ans){
    if(v == ending) return ans;
    vis[v] = true;
    for(int i = 0;i < ve[v].size();i++){
        if(vis[ve[v][i]]) continue;
        dfs(ve[v][i],ans + 1);
    }
}
void solve(){
    cin >> start >> ending;
    ans += (w[start] + w[ending]);
    dfs(start,ans);
    cout << ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        int k; cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> a[i][j] >> t[i][j];
            ve[a[i][j]].push_back(a[i][j-1]);
            ve[a[i][j-1]].push_back(a[i][j]);
        }
    }
    while(q--) solve();
    return 0;
}
