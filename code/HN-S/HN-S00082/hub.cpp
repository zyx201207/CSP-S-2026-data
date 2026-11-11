#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int mx0dep[N], mx1dep[N], dp1[N], dp2[N], mx2dep[N], u, v, l, r, mid, c[N], vis[N], n, dfn[N], tot, End[N], K, opt, T;
vector<int>g[N];

void dfs1(int x, int fa){
  dfn[x] = ++tot;
  for(auto v : g[x]){
    if(v == fa)continue;
    dfs1(v, x);
    if(mx0dep[v] + 1 > mx0dep[x]){
      mx1dep[x] = mx0dep[x];
      mx0dep[x] = mx0dep[v] + 1;
    }
    else{
      mx1dep[x] = max(mx1dep[x], mx0dep[v] + 1);
    }
    dp1[x] += dp1[v];
  }
  if(mx0dep[x] >= mid){
    dp1[x]++;
  }
  End[x] = tot;
}

void dfs2(int x, int fa){
  for(auto v : g[x]){
    if(v == fa)continue;
    dfs2(v, x);
    dp2[v] = dp2[x] + dp1[x] - dp1[v];
    mx2dep[v] = max(mx2dep[x] + 1, (c[x] == v ? mx1dep[x] : mx0dep[x]));
    if(mx2dep[v] >= mid)dp2[v]++;
    dfs2(v, x);
  }
}

void To(int x, int fa, int ppp){
  if(ppp > mid)return ;
  vis[x] = 1;
  for(auto v : g[x]){
    if(v == fa)continue;
    To(v, x, ppp + 1);
  }
}

bool Check(){
  for(int i = 1; i <= n; i++){
    dp1[i] = 0;
    dp2[i] = 0;
    mx0dep[i] = 0;
    mx1dep[i] = 0;
    mx2dep[i] = 0;
    c[i] = 0;
  }
  tot = 0;
  dfs1(1, 0);
  dfs2(1, 0);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      for(int k = 1; k <= n; k++){
        if(dfn[i] <= dfn[k] && dfn[k] <= End[i] || !(dfn[j] + 1 <= dfn[k] && dfn[k] <= End[j]))vis[k] = 1;
        else vis[k] = 0;
      }
      To(i, 0, 0);
      To(j, 0, 0);
      bool flag = 1;
      for(int k = 1; k <= n; k++){
        flag &= (vis[k] == 1);
      }
      //cout << dp1[i] << ' ' <<dp2[j] <<' ' << i <<' ' << j <<' '<< mid << '\n';
      if(flag && max(1, dp1[i]) + max(dp2[j], 1) <= K)return 1;
    }
  }
  return 0;
}

void Solve(){
  cin >> n >> K;
  for(int i = 1; i <= n; i++)g[i].clear();
  for(int i = 1; i < n; i++){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  l = 0, r = n;
  while(l < r){
    mid = (l + r) >> 1;
    if(Check())r = mid;
    else l = mid + 1;
  }
  cout << l << '\n';
}

int main(){
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for(cin >> opt >> T; T--; Solve());
  return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
