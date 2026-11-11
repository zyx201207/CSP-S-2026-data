#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstddef>
using namespace std;
using ll=long long;
const int N=505;
const int M=5e5+5;
const ll INF=1e18; // care!!!
int c,n,m,d,q;
ll w[M];
struct BelongNode{
  int road;
  ll weight;
};
vector<BelongNode> belg[M];
ll f[N][N];
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++) cin>>w[i];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) f[i][j]=INF;
    f[i][i]=0;
  }
  for(int i=1;i<=n;i++){
    int k;
    cin>>k;
    for(int j=1;j<=k;j++){
      int a;
      ll t;
      cin>>a>>t;
      belg[a].push_back({i,t});
    }
  }
  for(int i=1;i<=m;i++){
    auto&now=belg[i];
    for(size_t u=0;u<now.size();u++){
      for(size_t v=u+1;v<now.size();v++){
        f[now[u].road][now[v].road]=
        f[now[v].road][now[u].road]=
          min(f[now[u].road][now[v].road],now[u].weight+now[v].weight);
      }
    }
  }
  for(int k=1;k<=n;k++){
    for(int u=1;u<=n;u++){
      for(int v=1;v<=n;v++){
        f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
      }
    }
  }
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++){
  //     cerr<<"Dis [ "<<i<<", "<<j<<" ]= "<<f[i][j]<<'\n';
  //   }
  // }
  while(q--){
    int u,v;
    cin>>u>>v;
    if(u==v){
      cout<<"0\n";
      continue;
    }
    ll ans=INF;
    ll bas=w[u]+w[v];
    for(size_t i=0;i<belg[u].size();i++){
      for(size_t j=0;j<belg[v].size();j++){
        auto&frm=belg[u][i];
        auto&too=belg[v][j];
        ll dis=bas;
        dis+=frm.weight+too.weight+f[frm.road][too.road];
        ans=min(ans,dis);
      }
    }
    cout<<ans<<'\n';
  }
  cout.flush();
  fclose(stdin);
  fclose(stdout);
  return 0;
}