//15
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 5;
const int Log = 35;
int n, k;
int Dep[N], F[N][Log], Dis[N][N];
bool Tag[N], Vis[N];
vector<int> G[N];


void DFS(int x, int father) {
    Dep[x] = Dep[father] + 1;  F[x][0] = father;
    for(int i = 0; i < G[x].size(); i++) if(G[x][i] != father) DFS(G[x][i], x);
}

void Init() {
    DFS(1, 0);
    for(int len = 1; (1 << len) <= n; len++) for(int i = 1; i <= n; i++)
        F[i][len] = F[F[i][len - 1]][len - 1];
}

int LCA(int x, int y) {
    if(Dep[x] < Dep[y]) swap(x, y);

    for(int i = 30; i >= 0; i--) if(Dep[x] - Dep[y] >= (1 << i)) x = F[x][i];
    if(x == y) return x;

    for(int i = 30; i >= 0; i--) if(F[x][i] != F[y][i]) x = F[x][i], y = F[y][i];
    return F[x][0];
}

int Distance(int x, int y) {
    if(Dis[x][y]) return Dis[x][y];
    int Lca = LCA(x, y);
    Dis[x][y] = Dis[y][x] = Dep[x] + Dep[y] - Dep[Lca] - Dep[Lca];
    return Dis[x][y];
}

void Dye(int x, int father) {
    if(!Tag[x]) return;  Vis[x] = true;
    for(int i = 0; i < G[x].size(); i++) if(G[x][i] != father) Dye(G[x][i], x);
}

bool Check(vector<int> V) {
    for(int i = 1; i <= n; i++) Tag[i] = Vis[i] = false;
    for(int i = 0; i < V.size(); i++) Tag[V[i]] = true;

    int cnt = 0;
    for(int i = 1; i <= n; i++) if(Tag[i] && !Vis[i]) { Dye(i, 0);  cnt++; }
    return cnt <= 2;
}

void Main() {
    cin >> n >> k;
    for(int i = 1; i < n; i++) { 
        int x, y;  cin >> x >> y;
        G[x].push_back(y);  G[y].push_back(x);
    }

    Init();

    int Res = 0x3f3f3f3f;
    for(int S = 0; S < (1 << n); S++) {
        vector<int> A, B;
        for(int i = 1; i <= n; i++) {
            if(S & (1 << i - 1)) A.push_back(i);
            else B.push_back(i);
        }
        if(A.size() != k || !Check(A)) continue;

        int Max = 0;
        for(int i = 0; i < B.size(); i++) { int x = B[i];
            int Min = 0x3f3f3f3f;
            for(int j = 0; j < A.size(); j++) { int y = A[j];
                Min = min(Min, Distance(x, y));
            }
            Max = max(Max, Min);
        }
        Res = min(Res, Max);
    }
    cout << Res << '\n';

    for(int i = 1; i <= n; i++) G[i].clear();
    memset(Dep, 0, sizeof(Dep));  memset(Dis, 0, sizeof(Dis));  memset(F, 0, sizeof(F));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int C, T;  cin >> C >> T;
    while(T--) Main();
    return 0;
}