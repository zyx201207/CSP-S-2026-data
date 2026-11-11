#include "bits/stdc++.h"
using namespace std;

/*
Goodbye, CSP/NOI!
-----------------------------------
|\     |  /----------\   |-----|
| \    |  |          |      |
|  \   |  |          |      |
|   \  |  |          |      |
|    \ |  |          |      |
|     \|  \----------/   |-----|
-----------------------------------
*/

#define HOPE_AC "QUEQIEXIWANG"
using pii = pair<int, int>;

int c, n, m, d, q;

int u[500005];
vector<int> t[505];
vector<pii> G[505];

int up[505][500005];

//int has[505][500005];

int vis[500005];

bool in_line(int ln, int x) {
    for(auto it : t[ln]) {
        if(it == x) return true;
    }
    return false;
}

void bfs(int st, int ed) {

    int res = INT_MAX;
    memset(vis, 0, sizeof(vis));
    queue<pii> q;

    for(int ln = 1; ln <= n; ln++) {
        if(up[ln][st] != 0) {
            q.push({ln, u[st] + up[ln][st]});
            // cout << up[ln][st] << "AAA \n";
            /// << u[st] << "UUU \n";
            //printf("Debug: Line:%d is a good start. use:%d\n", ln, u[st] + up[ln][st]);
        }
    }

    unordered_map<int, int> m;
    // nopop
    do {

        for(int i = 1; i <= n; i++) {
            if(in_line(i, ed)) {
                m[i] = 1;
            }
        }


    } while(0);

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        //if(t.second >= res) continue;
        if(m[t.first]) {
            res = min(res, t.second + u[ed] + up[t.first][ed]);
            //printf("Debug: Finished Travel: scd:%d u:%d up:%d\n", t.second, u[ed], up[t.first][ed]);
            continue;
        }

        for(auto it : G[t.first]) {
            //printf("Debug: Can go Line:%d, need %d\n", it.first, it.second);
            if(!vis[it.first] || m[it.first]) {
                vis[it.first] = 1;
                q.push({it.first, t.second + it.second});
                //printf("Debug: Pay %d\n", it.second);
                //printf("Debug: Line:%d to Line:%d, all use:%d\n", t.first, it.first, t.second + it.second);
            }
        }

    }

    cout << res << '\n';

    return ;
}




int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> u[i];
    }

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int a, b;
            cin >> a >> b;
            t[i].push_back(a);
            up[i][a] = b;
            //printf("up[%d][%d]:%d ", i, a, b);
        }
        //printf("\n");

    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == i) continue;
            for(auto it : t[i]) {
                if(in_line(j, it)) {
                    G[i].push_back({j, up[i][it] + up[j][it]});
                }
            }

        }
    }


    while(q--) {
        int st, ed;
        cin >> st >> ed;
        bfs(st, ed);

    }




    return 0;
}

