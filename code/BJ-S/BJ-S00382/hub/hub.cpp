#include "bits/stdc++.h"
using namespace std;

vector<int> G[1000005];
int n, k;
int vis[1000005];

vector<int> sth;
int res = 0x3f3f3f3f;

int darwen;

void init() {
    for(int i = 1; i <= n; i++) {
        G[i].clear();
    }
    sth.clear();
    res = INT_MAX;
    memset(vis, 0, sizeof(vis));
    darwen = 0;
    return ;
}

bool isinsth(int x) {
    for(auto it : sth) {
        if (x == it) {
            return true;
        }
    }
    return false;
}

void printsth() {
    for(auto it : sth) {
        cout << it << ' ';
    }
    cout << '\n';
}


void gogogo() {
    //printsth();
    // find workstation
    //if(sth[0] != 1 || sth[1] != 4) return ;
    //cout << "&&&&&&&&&&&\n";
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++) {
        if(isinsth(i)) continue;
        //cout << i <<"pushed ";
        q.push({i, 0});
    }
    int maxlen = 0;
    while(!q.empty()) {
        auto id = q.front();
        q.pop();
        if(isinsth(id.first)) {
            //printsth();
            maxlen = max(maxlen, id.second);
            darwen = max(maxlen, id.second);
            //cout << "Ok " << maxlen << "::" << id.second << endl;
        }
        for(auto it : G[id.first]) {
            if(!vis[it]) {
                q.push({it, id.second + 1});
                vis[it] = 1;
            }

        }
    }
    //cout << res << "--" <<maxlen << endl;
    if(maxlen == 0) return;
    res = min(maxlen, res);
}


void dfs(int r, int cnt) {
    if(cnt == k) {
        //printsth();
        gogogo();
        return ;
    }
    for(int i = r + 1; i <= n; i++) {

        sth.push_back(i);
        dfs(i, cnt + 1);
        sth.pop_back();
    }
}

void solve() {

    if(n == k) {
        cout << 0 << '\n';
        return ;
    }

    dfs(0, 0);
    cout << min(res, INT_MAX) << '\n';

    return ;

}

int main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        init();
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        solve();
    }

    return 0;
}
