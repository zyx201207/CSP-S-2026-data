#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k,col[1000005],dis[4005][4005];
bool flag;
vector<int> e[1000005];
set<int> st;
void dfs(int x,int c){
    col[x] = c;
    for (auto i : e[x]) if (st.count(i)){
        if (col[i] && col[i] != c) flag = true;
        else if (!col[i]) dfs(i,c);
    }
}
void bfs(int s){
    queue<int> q;
    q.push(s);
    memset(dis[s],0x3f,sizeof(dis[s]));
    dis[s][s] = 0;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (auto i : e[x]) if (dis[s][i] > dis[s][x] + 1){
            dis[s][i] = dis[s][x] + 1;
            q.push(i);
        }
    }
}
void solve(){
    cin >> n >> k;
    for (int i = 1;i <= n;i++) e[i].clear();
    for (int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) bfs(i);
    int ans = LONG_LONG_MAX;
    for (int i = 1;i < (1 << n);i++) if (__builtin_popcount(i) == k){
        st.clear();
        flag = false;
        for (int j = 1;j <= n;j++){
            col[j] = 0;
            if ((i >> (j - 1)) & 1) st.insert(j);
        }
        dfs(*st.begin(),54399);
        int tmp = -1;
        for (auto j : st) if (!col[j]) tmp = j;
        if (tmp == -1) continue;
        dfs(tmp,43599);
        if (flag) continue;
        for (auto j : st) if (!col[j]) flag = true;
        if (flag) continue;
        int maxn = 0;
        for (int j = 1;j <= n;j++){
            int minn = LONG_LONG_MAX;
            for (auto k : st) minn = min(minn,dis[j][k]);
            maxn = max(maxn,minn);
        }
        ans = min(ans,maxn);
    }
    cout << ans << "\n";
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}
//freopen
//freopen
//freopen
//I love linfangfei forever!!!
//subscribe to luogu uid 551559 plzzzzz!!!