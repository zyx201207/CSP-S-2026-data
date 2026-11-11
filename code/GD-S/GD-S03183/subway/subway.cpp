#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;
const int MAXM = 5e5 + 5;
const int MAXQ = 1e5 + 5;

struct Node {
    int li, ti;
    Node() {
    }
    Node(int l, int t) : li(l), ti(t) {
    }
};

int C, N, M, D, Q;
int w[MAXM];
int lin[MAXN];  // k[]
int st[MAXQ], ed[MAXQ];

vector<Node> sta[MAXM];
long long dis[MAXN][MAXN];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C >> N >> M >> D >> Q;
    for(int i=1; i<=M; i++) cin >> w[i];
    for(int i=1; i<=N; i++) {
        cin >> lin[i];
        for(int j=1; j<=lin[i]; j++) {
            int a, t;
            cin >> a >> t;
            sta[a].push_back(Node(i, t));
        }
    }
    for(int i=1; i<=Q; i++) cin >> st[i] >> ed[i];

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if (i == j) {
                dis[i][j] = 0;
            } else {
                dis[i][j] = LLONG_MAX;
            }
        }
    }
    for(int i=1; i<=M; i++) {
        for(int j=0; j<sta[i].size(); j++) {
            for(int k=j+1; k<sta[i].size(); k++) {
                dis[sta[i][j].li][sta[i][k].li] = min(dis[sta[i][j].li][sta[i][k].li], (long long)(sta[i][j].ti + sta[i][k].ti));
                dis[sta[i][k].li][sta[i][j].li] = dis[sta[i][j].li][sta[i][k].li];
            }
        }
    }
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=i+1; j<=N; j++) {
                if (dis[i][k] != LLONG_MAX && dis[j][k] != LLONG_MAX) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
                }
            }
        }
    }
    for(int i=1; i<=Q; i++) {
        long long ans = LLONG_MAX;
        for(int j=0; j<sta[st[i]].size(); j++) {
            for(int k=0; k<sta[ed[i]].size(); k++) {
                if (dis[sta[st[i]][j].li][sta[ed[i]][k].li] == LLONG_MAX) continue;
                ans = min(ans, dis[sta[st[i]][j].li][sta[ed[i]][k].li] + sta[st[i]][j].ti + sta[ed[i]][k].ti);
            }
        }
        cout << (ans + w[st[i]] + w[ed[i]]) << "\n";
    }
    return 0;
}