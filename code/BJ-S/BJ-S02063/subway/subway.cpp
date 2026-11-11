#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int g2s_time[505];  // ground to station time
int s2s_time[505][505]; // station to station time

void handle_data_input(){
    map<int, int> l2s_time;

    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    vector<int> line;
    memset(s2s_time, 0x3f, sizeof(s2s_time));
    for(int i = 1; i <= m; i++) scanf(" %d", &g2s_time[i]);
    for(int i = 1; i <= n; i++) {
        int k, a, t; scanf(" %d", &k);
        for(int j = 1; j <= k; j++) {
            scanf(" %d %d", &a, &t);
            l2s_time[a] = t;
        }
        for(auto &a1 : l2s_time) {
            for(auto &a2 : l2s_time) {
                int x = a1.first;
                int y = a2.first;
                if(x != y) {
                    s2s_time[x][y] = min(a1.second + a2.second, s2s_time[x][y]);
                    s2s_time[y][x] = min(a1.second + a2.second, s2s_time[y][x]);
                } else {
                    s2s_time[x][y] = 0;
                    s2s_time[y][x] = 0;
                }
            }
        }
        l2s_time.clear();
    }
    return;
}

void update_path() {
    for(int k = 1; k <= m; k++) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                if(i == k || j == k) continue;
                s2s_time[i][j] = min(s2s_time[i][k] + s2s_time[k][j], s2s_time[i][j]);
            }
        }
    }
    return;
}

int query(int x, int y) {
    return s2s_time[x][y] + g2s_time[x] + g2s_time[y];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    handle_data_input();
    update_path();
    int x, y;
    for(int i = 1; i <= q; i++) {
        scanf(" %d %d", &x, &y);
        printf("%d\n", query(x, y));
    }
    return 0;
}
