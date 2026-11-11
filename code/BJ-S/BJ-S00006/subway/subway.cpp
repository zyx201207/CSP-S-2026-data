#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
const int M = 505;
const int D = 25;
int c, n, m, d, q, w[N], k[M], p[M][M];
vector<pair<int,int> > t[N];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i ++){
        cin >> k[M];
        for(int j = 1; j <= k[M]; j ++){
            int x, T;
            cin >> x >> T;
            t[x].push_back({i, T});
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            p[i][j] = INT_MAX;
            if(i == j) p[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j < t[i].size(); j ++){
            for(int k = j + 1; k < t[i].size(); k ++){
                int xx = t[i][j].first;
                int yy = t[i][k].first;
                int xxx = t[i][j].second;
                int yyy = t[i][k].second;
                p[xx][yy] = min(p[xx][yy], xxx + yyy);
                p[yy][xx] = min(p[yy][xx], xxx + yyy);
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            for(int k = 1; k <= n; k ++){
                if(p[i][k] == INT_MAX || p[k][j] == INT_MAX) continue;
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            int fff = min(p[i][j], p[j][i]);
            p[i][j] = fff;
            p[j][i] = fff;
        }
    }
    while(q --){
        int xxxx, yyyy, ans = INT_MAX;
        cin >> xxxx >> yyyy;
        for(int i = 0; i < t[xxxx].size(); i ++){
            for(int j = 0; j < t[yyyy].size(); j ++){
                int uu = t[xxxx][i].first;
                int vv = t[yyyy][j].first;
                int ww = p[uu][vv] + w[xxxx] + w[yyyy] + t[xxxx][i].second + t[yyyy][j].second;
                ans = min(ans, ww);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}