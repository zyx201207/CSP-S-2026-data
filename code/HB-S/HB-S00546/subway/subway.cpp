// 44
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge { int to, val; };
struct Question { int id, S, E;  bool operator < (const Question &_) const { return S < _.S; } };
struct Point { int id, dis;  bool operator < (const Point &_) const { return dis > _.dis; } };

const int N = 5e5 + 5;
const int Max = 5e7 + 5;
int n, m, D, Q, W[N], Ans[N];
Question Ques[N];
vector<Edge> G[Max];  int Dis[Max];  bool Vis[Max];

void Dijkstra(int Start) {
    priority_queue<Point> Q;  memset(Dis, 0x3f, sizeof(Dis));  memset(Vis, false, sizeof(Vis));
    Dis[Start] = 0;  Q.push({Start, Dis[Start]});

    while(!Q.empty()) {
        int x = Q.top().id;  Q.pop();
        if(Vis[x]) continue;  Vis[x] = true;
        
        for(int i = 0; i < G[x].size(); i++) { int y = G[x][i].to, w = G[x][i].val;
            if(Dis[y] < Dis[x] + w) continue;
            Dis[y] = Dis[x] + w;  Q.push({y, Dis[y]});
        }
    }
}

void Main() {
    cin >> m >> n >> D >> Q;
    for(int i = 1; i <= n; i++) cin >> W[i];
    for(int i = 1; i <= m; i++) {
        int K;  cin >> K;
        for(int j = 1; j <= K; j++) {
            int P, Val;  cin >> P >> Val;

            G[P].push_back({P + i * n, Val});
            G[P + i * n].push_back({P, Val});

            G[i + n * (D + 1)].push_back({P + i * n, 0});
            G[P + i * n].push_back({i + n * (D + 1), 0});
        }
    }

    for(int i = 1; i <= Q; i++) { cin >> Ques[i].S >> Ques[i].E;  Ques[i].id = i; }
    sort(Ques + 1, Ques + Q + 1);

    for(int i = 1; i <= Q; i++) {
        if(Ques[i].S != Ques[i - 1].S) Dijkstra(Ques[i].S);
        Ans[Ques[i].id] = Dis[Ques[i].E] + W[Ques[i].S] + W[Ques[i].E];
    }
    for(int i = 1; i <= Q; i++) cout << Ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int C;  cin >> C;  Main();
    return 0;
}