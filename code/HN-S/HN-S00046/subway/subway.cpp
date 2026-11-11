#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second

const int M=500'010, N=510, inf=1e18;
int c, n, m, d, r, w[M], k[N];
vector<int> a[N], t[N];
vector<pii> e[M];

priority_queue<pii, vector<pii>, greater<pii>> q;
int dis[N][N];
bool vis[N][N];

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(0);
  cin>> c>> n>> m>> d>> r;
  for(int i=1; i<=m; i++) cin>> w[i];
  for(int i=1; i<=n; i++) {
    cin>> k[i], a[i].resize(k[i]+1), t[i].resize(k[i]+1);
    for(int j=1; j<=k[i]; j++) cin>> a[i][j]>> t[i][j], e[a[i][j]].emplace_back(i, j);
  }
  for(int x=1; x<=n; x++) for(int y=1; y<=n; y++) if(x!=y) dis[x][y]=inf;
  for(int x=1; x<=n; x++) {
    q.emplace(dis[x][x]=0, x);
    for(int u, d; q.size(); ) {
      u=q.top().sec, q.pop();
      if(vis[x][u]) continue; vis[x][u]=1;
      for(int i=1; i<=k[u]; i++) {
        int p=a[u][i];
        for(pii now: e[p]) {
          int v=now.fir, j=now.sec;
          if(v==u) continue;
          if(dis[x][v]>dis[x][u]+t[u][i]+t[v][j]) {
            dis[x][v]=dis[x][u]+t[u][i]+t[v][j];
            q.emplace(dis[x][v], v);
          }
        }
      }
    }
    for(int y=x+1; y<=n; y++) dis[y][x]=dis[x][y], vis[y][x]=1;
  }
  for(int i=1, x, y, ans; i<=r; i++) {
    cin>> x>> y, ans=inf;
    for(pii pu: e[x]) {
      for(pii pv: e[y]) {
        int u=pu.fir, j=pu.sec, v=pv.fir, k=pv.sec;
        int c=w[x]+t[u][j]+dis[u][v]+t[v][k]+w[y];
        ans=min(ans, c);
      }
    }
    cout<< ans<< '\n';
  }
  return 0;
}