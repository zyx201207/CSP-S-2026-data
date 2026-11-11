#include <bits/stdc++.h>
using namespace std;

const int N=1'000'010;
int C, T, n, k, cnt;
vector<int> g[N];
bool ins[N], vis[N];

void dfs1(int u) { for(int v: g[u]) if(ins[v]&&!vis[v]) vis[v]=1, dfs1(v); }
int dfs2(int u) { if(ins[u]) return 0; int r=0; for(int v: g[u]) if(!vis[v]) vis[v]=1, r=max(r, dfs2(v)); return r+1; }

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(0);
  for(cin>> C>> T; T--; ) {
    cin>> n>> k;
    for(int i=1; i<=n; i++) g[i].clear();
    for(int i=1, u, v; i<n; i++) cin>> u>> v, g[u].emplace_back(v), g[v].emplace_back(u);
    int ans=n;
    for(int S=0; S<1<<n; S++) {
      if(__builtin_popcount(S)!=k) continue;
      int cnt=0;
      for(int i=1; i<=n; i++) ins[i]=(S>>(i-1)&1), vis[i]=0;
      for(int i=1; i<=n; i++) if(ins[i]&&!vis[i]) cnt++, vis[i]=1, dfs1(i);
      if(cnt<=2) { int res=0; for(int i=1; i<=n; i++) if(!ins[i]) { fill(vis+1, vis+n+1, 0), vis[i]=1, res=max(res, dfs2(i)); } ans=min(ans, res); }
    }
    cout<< ans<< '\n';
  }
  return 0;
}