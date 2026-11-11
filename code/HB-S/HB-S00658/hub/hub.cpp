#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector <int> e[110];

int vis[110];
int ans = 1e9;
int bel[110],cnt;

void dfs2(int u,int fa){
    for (auto v : e[u]){
        if (v == fa || vis[v] == 0) continue;
        bel[v] = cnt;
        dfs2(v,u);
    }
}

bool check(){
    for (int i=1;i<=n;i++){ bel[i] = 0;}
    cnt = 0;
    for (int i=1;i<=n;i++){
        if (vis[i] == 1 && bel[i] == 0){
            cnt ++;
            dfs2(i,0);
        }
        if (cnt > 2) return false;
    }
    if (cnt == 2) return true;
    else return false;
}

queue <pair<int,int> > q;
int getans(){
    int res = 0;
    for (int i=1;i<=n;i++){
        while (!q.empty()) q.pop();
        q.push(make_pair(i,0));
        while (!q.empty()){
            if (vis[q.front().first] == 1){
                res = max(res,q.front().second);
                break;
            }
            for (auto v : e[q.front().first]){
                q.push(make_pair(v,q.front().second + 1));
            }
            q.pop();
        }
    }
    return res;
}

void dfs1(int step,int p){
    if (step == k+1){
        if (check()){
            ans = min(ans,getans());
        }
        return ;
    }
    for (int i=p;i<=n;i++){
        vis[i] = 1;
        dfs1(step+1,i+1);
        vis[i] = 0;
    }
}


void solve(){
    cin >> n >> k;

    ans = 1e9;
    for (int i=1;i<=n;i++){
        e[i].clear();
    }

    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }

    dfs1(1,1);

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("hub.in","r",stdin);
    freopen ("hub.out","w",stdout);
    cin >> c >> t;
    while (t--){
        solve();
    }
    return 0;
}
