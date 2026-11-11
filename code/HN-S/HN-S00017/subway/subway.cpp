#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,n,m,d,q;
int w[N];
vector<pair<int,int>> a[N];
int dis[1005][1005];
signed main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++)cin>>w[i];
  for(int i=1;i<=n;i++){
    int l;
    cin>>l;
    for(int j=1;j<=l;j++){
      int id,w;
      cin>>id>>w;
      a[id].push_back({i,w});
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)continue;
      dis[i][j]=1e18;
    }
  }
  for(int i=1;i<=m;i++){
    for(int j=0;j<a[i].size();j++){
      for(int k=j+1;k<a[i].size();k++){
        if(a[i][j].second+a[i][k].second<dis[a[i][j].first][a[i][k].first]){
          dis[a[i][j].first][a[i][k].first]=a[i][j].second+a[i][k].second;
          dis[a[i][k].first][a[i][j].first]=a[i][j].second+a[i][k].second;
        }
      }
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
      }
    }
  }
  while(q--){
    int u,v;
    cin>>u>>v;
    int ans=1e18;
    for(int i=0;i<a[u].size();i++){
      for(int j=0;j<a[v].size();j++){
        ans=min(ans,dis[a[u][i].first][a[v][j].first]+a[u][i].second+a[v][j].second+w[u]+w[v]);
        // cout<<a[u][i].first<<" "<<a[v][j].first<<" "<<a[u][i].second<<" "<<a[v][j].second<<" "<<w[u]<<" "<<w[v]<<"\n";
      }
    }cout<<ans<<"\n";
  }
  // cerr<<clock()/1e6;
  return 0;
}