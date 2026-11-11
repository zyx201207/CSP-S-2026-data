//8
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point { int id, dis;  bool operator < (const Point &_) const { return dis > _.dis; } };

const int N = 2e6 + 5;
const int M = 5005;
int n, D, Res;
int X[N];
int Dis[M][M];  bool Vis[M];
vector<int> G[M], V;

bool Check(int i, int j, int k) {
    for(int _ = 0; _ < V.size(); _++) if(Dis[i][V[_]] + Dis[V[_]][k] + Dis[k][j] == Dis[i][j]) return false;
    for(int _ = 0; _ < V.size(); _++) if(Dis[i][k] + Dis[k][V[_]] + Dis[V[_]][j] == Dis[i][j]) return false;
    return true;
}

void Dijkstra(int Start, int *Dis) {
    priority_queue<Point> Q;  memset(Dis, 0x3f, sizeof(Dis));  memset(Vis, false, sizeof(Vis));
    Dis[Start] = 0;  Q.push({Start, Dis[Start]});

    while(!Q.empty()) {
        int x = Q.top().id;  Q.pop();
        if(Vis[x]) continue;  Vis[x] = true;
        
        for(int i = 0; i < G[x].size(); i++) { int y = G[x][i];
            if(Dis[y] < Dis[x] + 1) continue;
            Dis[y] = Dis[x] + 1;  Q.push({y, Dis[y]});
        }
    }
}

void Main1() {
    cin >> n >> D;  Res = 0;
    for(int i = 1; i <= n; i++) cin >> X[i];

    memset(Dis, 0x3f, sizeof(Dis));    
    for(int i = 1; i <= n; i++) { G[i].clear();
        int L = lower_bound(X + 1, X + n + 1, X[i] - D) - X;
        int R = (X[i] + D < X[n]) ? (upper_bound(X + 1, X + n + 1, X[i] + D) - X - 1) : n;
        for(int pos = L; pos <= R; pos++) if(i != pos) G[i].push_back(pos);
    }

    for(int i = 1; i <= n; i++) Dijkstra(i, Dis[i]);

    for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) { 
        V.clear();
        for(int k = 1; k <= n; k++) if(k != i && k != j && Dis[i][k] + Dis[k][j] == Dis[i][j] && Check(i, j, k)) V.push_back(k);
        if(V.size() == 2) Res++;
    }

    cout << Res << '\n';
}

void Main2() {
    cin >> n >> D;  Res = 0;
    for(int i = 1; i <= n; i++) cin >> X[i];

    int Delta = D / (X[2] - X[1]);  if(Delta <= 1) { cout << 0 << '\n';  return; }

    for(int i = 1; i <= n; i++) {
        if(i + Delta + Delta - 1 <= n) Res++;
        if(i - Delta - Delta + 1 >= 1) Res++;
    }
    cout << (Res >> 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int C, T;  cin >> C >> T;
    while (T--) Main1();
    if(1 <= C && C <= 6) { while (T--) Main1();  return 0; }
    if(11 <= C && C <= 12) { while (T--) Main2();  return 0; }
    // if(C == 13 || C == 14) { while (T--) Main3();  return 0; }
    return 0;
}