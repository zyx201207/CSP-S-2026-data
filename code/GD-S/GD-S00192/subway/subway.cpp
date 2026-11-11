#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define eb emplace_back
#define ep emplace
#define fr(a,b,c) for(int a = b;a <= c;a ++)
using namespace std;
const int N = 600,M = 600000;
int C,n,m,D,q,wt[M],kc[N];
ll d[N][N];
vector<pair<int,int>> rt[M];
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> C >> n >> m >> D >> q;
  fr(i,1,n){
    fr(j,1,n) d[i][j] = 1e18;
    d[i][i] = 0;
  }
  fr(i,1,m) cin >> wt[i];
  fr(i,1,n){
    cin >> kc[i];
    int a,t;
    fr(j,1,kc[i]){
      cin >> a >> t;
      rt[a].eb(i,t);
    }
  }
  fr(i,1,m){
    int ed = rt[i].size();
    ed --;
    fr(j,0,ed){
      fr(k,j + 1,ed){
        int u = rt[i][j].first,v = rt[i][k].first,w = rt[i][j].second + rt[i][k].second;
        d[u][v] = d[v][u] = min(d[u][v],1ll * w);
      }
    }
  }
  fr(i,1,n) fr(j,1,n) fr(k,1,n) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
  fr(i,1,q){
    int x,y;
    ll ans = 1e18;
    cin >> x >> y;
    int edx = rt[x].size(),edy = rt[y].size();
    edx --,edy --;
    fr(i,0,edx){
      fr(j,0,edy){
        int u = rt[x][i].first,v = rt[y][j].first,w = rt[x][i].second + rt[y][j].second;
        ans = min(ans,d[u][v] + w);
      }
    }
    printf("%lld\n",ans + wt[x] + wt[y]);
  }
  return 0;
}
