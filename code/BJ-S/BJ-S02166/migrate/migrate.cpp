#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int NR = 2e6 + 5;

ll x[NR];

namespace solve110 {
    const int NR110 = 5005;

    vector<int> mp110[NR110];
    ll dis110[NR110][NR110];
    int cnt110[NR110][NR110];
    bool inq[NR110];

    struct node_T {
        int u, cnt;
        ll dis;

        bool operator>(const node_T a) const {
            return dis > a.dis;
        }
    };

    void djistra(int st) {
        dis110[st][st] = 0;
        cnt110[st][st] = 1;

        priority_queue<node_T, vector<node_T>, greater<node_T>> q;

        q.push(node_T{st, 1, 0});
        while (!q.empty()) {
            node_T now = q.top();
            q.pop();

            for (int v : mp110[now.u]) {
                if (now.dis + 1 < dis110[st][v]) {
                    dis110[st][v] = now.dis + 1;
                    cnt110[st][v] = now.cnt;
                    q.push(node_T{v, cnt110[st][v], dis110[st][v]});
                }
                else if (now.dis + 1 == dis110[st][v]) {
                    cnt110[st][v] += now.cnt;
                    q.push(node_T{v, now.cnt, dis110[st][v]});
                }
            }
        }
    }

    void solve() {
        int n, ans = 0;
        ll d;

        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];

        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n && x[j] - x[i] <= d; j++) {
                mp110[i].emplace_back(j);
                mp110[j].emplace_back(i);
            }
        
        memset(dis110, 0x3f, sizeof(dis110));

        for (int i = 1; i <= n; i++)
            djistra(i);
        
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (cnt110[i][j] == 2)
                    ans++;
        printf("%d\n", ans);

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++)
        //         printf("%4lld", dis110[i][j]);
        //     puts("");
        // }
        // puts("");
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++)
        //         printf("%4d", cnt110[i][j]);
        //     puts("");
        // }

        for (int i = 1; i <= n; i++)
            mp110[i].clear();
        memset(cnt110, 0, sizeof(cnt110));
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, t;

    cin >> c >> t;
    while (t--) {
        if (c <= 10) {
            solve110::solve();
        }
    }
    return 0;
}