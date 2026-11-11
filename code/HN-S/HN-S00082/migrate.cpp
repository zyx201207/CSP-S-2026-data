/*
#include<bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 2e6 + 5;

LL ans;
int to[N], opt, T, n, cnt[N], vis[N], sz[N], lst[N], c[N], f[21][N], dep[N], wyt;
LL x[N], d;
vector<int>g[N];

struct node{
  int x, cnt, l, r, lazy;
};

struct Node{
  int l, r, lazy;
  pair<node, node>minx;
}t[N * 4];

node Min(node a, node b){
  node c;
  c.x = min(a.x, b.x);
  return {c.x, (a.x == c.x) * a.cnt + (b.x == c.x) * b.cnt};
}

pair<node, node>AND(pair<node, node>a, pair<node, node>b){
  pair<node, node>c;
  c.first = Min(a.first, b.first);
  c.second = Min((c.first.x == a.first.x ? a.second : a.first), (c.first.x == b.first.x ? b.second : b.first));
  return c;
}

void renew(int p){
  t[p].minx = AND(t[p * 2].minx, t[p * 2 + 1].minx);
}

void tog(int p, int L){
  t[p].lazy += L;
  t[p].minx.first.x += L;
  t[p].minx.second.x += L;
}

void Lazy(int p){
  if(!t[p].lazy)return ;
  tog(p * 2, t[p].lazy);
  tog(p * 2 + 1, t[p].lazy);
  t[p].lazy = 0;
}

void build(int p, int l, int r){
  t[p].l = l, t[p].r = r, t[p].minx.first = {0, 1}, t[p].minx.second = {(int)(1e9), 0}, t[p].lazy = 0;
  if(t[p].l == t[p].r)return ;
  int mid = (l + r) >> 1;
  build(p * 2, l, mid), build(p * 2 + 1, mid + 1, r);
  renew(p);
}

void updata(int p, int l, int r, int L){
  if(r < l)return ;
  if(l <= t[p].l && t[p].r <= r){
    tog(p, L);
    return ;
  }
  int mid = (t[p].l + t[p].r) >> 1;
  Lazy(p);
  if(l <= mid)updata(p * 2, l, r, L);
  if(r > mid)updata(p * 2 + 1, l, r, L);
  renew(p);
}

pair<node, node> getsum(int p, int l, int r){
  if(l <= t[p].l && t[p].r <= r)return t[p].minx;
  Lazy(p);
  int mid = (t[p].l + t[p].r) >> 1;
  if(l <= mid){
    if(r > mid){
      return AND(getsum(p * 2, l, r), getsum(p * 2 + 1, l, r));
    }
    return getsum(p * 2, l, r);
  }
  return getsum(p * 2 + 1, l, r);
}

int LCA(int x, int y){
  if(dep[x] < dep[y])swap(x, y);
  int k = dep[x] - dep[y];
  for(int i = 20; ~i; i--){
    if(k & (1 << i))x = f[i][x];
  }
  if(x == y)return x;
  for(int i = 20; ~i; i--){
    if(f[i][x] != f[i][y]){
      x = f[i][x], y = f[i][y];
    }
  }
  return f[0][x];
}

void dfs(int x, int fa){
  vis[x] = 1;
  dep[x] = dep[fa] + 1;
  sz[x] = 1;
  f[0][x] = fa;
  for(int i = 1; i <= 20; i++){
    f[i][x] = f[i - 1][f[i - 1][x]];
  }
  for(auto v : g[x]){
    dfs(v, x);
    sz[x] += sz[v];
  }
}

void dfs2(int x, int fa){
  vis[x] = 1;
  //cout << getsum(1, 1, n).first.x <<' ' << getsum(1, 1, n).second.x <<'\n';
  if(fa && fa - 1 > x){
    int kk = LCA(fa, fa - 1);
    //cout << x << ' ' << fa + 1 << " ~ " << kk << ' ' << dep[fa] << ' ' << dep[fa - 1] << ' ' << (dep[fa] > dep[fa - 1]) << '\n';
    if(kk && dep[fa] == dep[fa - 1])updata(1, kk, n, 1);
    else if(kk && dep[fa] != dep[fa - 1])updata(1, fa + 1, kk - (dep[fa] != dep[fa - 1]), 1);
  }
  if(fa && fa - 2 > x){
    int kk = LCA(fa, fa - 2);
    //cout << x << ' ' << fa + 1 << " ~ " << kk << ' ' << dep[fa] << ' ' << dep[fa - 2] << ' ' << (dep[fa] > dep[fa - 2]) << '\n';
    if(kk && dep[fa] == dep[fa - 2])updata(1, kk, n, 1);
    else if(kk && dep[fa] != dep[fa - 2])updata(1, fa + 1, kk - (dep[fa] != dep[fa - 2]), 1);
  }
  auto now = getsum(1, 1, wyt);
  auto aa = now.first, bb = now.second;
  if(aa.x == 1)ans += aa.cnt;
  if(bb.x == 1)ans += bb.cnt;
  //cout << aa.x <<' ' << bb.x<< '\n';
  //if(aa.x == 1)cout << "!1!" << x << " " << aa.cnt <<'\n';
  //if(bb.x == 1)cout << "!2!" << x << " " << bb.cnt << '\n';
  for(auto v : g[x]){
    dfs2(v, x);
  }
  if(fa && fa - 1 > x){
    int kk = LCA(fa, fa - 1);
    //cout << x << ' ' << fa + 1 << " ~ " << kk << '\n';
    if(kk && dep[fa] == dep[fa - 1])updata(1, kk, n, -1);
    else if(kk && dep[fa] != dep[fa - 1])updata(1, fa + 1, kk - (dep[fa] != dep[fa - 1]), -1);
  }
  if(fa && fa - 2 > x){
    int kk = LCA(fa, fa - 2);
    //cout << x << ' ' << fa + 1 << " ~ " << kk << '\n';
    if(kk && dep[fa] == dep[fa - 2])updata(1, kk, n, -1);
    else if(kk && dep[fa] != dep[fa - 2])updata(1, fa + 1, kk - (dep[fa] != dep[fa - 2]), -1);
  }
}

void Solve(){
  cin >> n >> d;
  for(int i = 1; i <= n + 1; i++){
    sz[i] = 0;
    cnt[i] = 0;
    vis[i] = 0;
    lst[i] = 0;
    g[i].clear();
  }
  for(int i = 1; i <= n; i++){
    cin >> x[i];
  }
  x[n + 1] = (LL)(4e18);
  for(int i = 1, j = 0; i <= n; i++){
    for(; j + 1 <= n + 1 && x[j + 1] <= x[i] + d; j++){
    }
    to[i] = j;
    //cout << i << " -> " << to[i] << '\n';
  }
  build(1, 1, n + 1);
  for(int i = 1; i <= n + 1; i++){
    if(to[i] == i)continue;
    cnt[to[i]]++;
    lst[to[i]] = max(lst[to[i]], i);
    g[to[i]].push_back(i);
  }
  ans = 0;
  for(int i = n + 1; i; i--){
    if(vis[i])continue;
    dfs(i, 0);
  }
  wyt = 0;
  for(int i = 1; i <= n + 1; i++)vis[i] = 0;
  for(int i = n + 1; i; i--){
    if(vis[i])continue;
    wyt = i;
    dfs2(i, 0);
  }
  cout << ans << '\n';
}

/*
0 1
4 2
1 2 3 4

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
9 10
0 36 37 37 47 50 60 64 93
9 10
3 9 36 45 49 52 57 70 93

0 1
9 10
0 36 37 37 47 50 60 64 93

2 -> 5
2 -> 6
2 -> 7
2 -> 8

int main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  for(cin >> opt; T--; Solve());
  return 0;
}
*/
#include<bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 2e6 + 5;

LL a[N], minx, d;
int cnt, n, opt, T, ans;

void dfs(int x, int y, int res){
  if(x == y){
    if(minx > res){
      minx = res;
      cnt = 1;
    }
    else if(minx == res){
      cnt++;
    }
    return ;
  }
  for(int j = x + 1; j <= y; j++){
    if(a[j] <= a[x] + d)dfs(j, y, res + 1);
  }
}

void Solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      cnt = 0, minx = (int)(1e9);
      dfs(i, j, 0);
      ans += (cnt == 2);
      //if(cnt == 2)cout << i << " -> " << j <<'\n';
    }
  }
  cout << ans << '\n';
}

int main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  for(cin >> opt >> T; T--; Solve());
  return 0;
}

