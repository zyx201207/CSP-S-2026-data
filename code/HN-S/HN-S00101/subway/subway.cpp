#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=5e5+100,kMN=600;

int c,n,m,d,q,w[kMaxN];
ll D[kMN][kMN],ans,mi;
vector<pair<int,int>>S[kMaxN];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++){
    cin>>w[i];
  }
  for(int i=1,k,t,a;i<=n;i++){
    for(cin>>k;k--;){
      cin>>a>>t,S[a].push_back({i,t});
    }
  }
  fill(D[0],D[n]+n+1,1e18);
  for(int i=1;i<=m;i++){
    for(int j=0;j+1<S[i].size();j++){
      ll *dis=D[S[i][j].first];
      for(int k=j+1;k<S[i].size();k++){
        dis[S[i][k].first]=min(dis[S[i][k].first],1ll*S[i][j].second+S[i][k].second);
      }
    }
  }
  for(int i=1;i<=n;i++){
    D[i][i]=0;
    for(int j=1;j<=n;j++){
      D[i][j]=min(D[i][j],D[j][i]);
    }
  }
  for(int i=1;i<=n;i++){
    ll *disi=D[i];
    for(int j=1;j<=n;j++){
      ll *disj=D[j];
      ll tt=disj[i];
      for(int k=1;k<=n;k++){
        disj[k]=min(disj[k],tt+disi[k]);
      }
    }
  }
  for(int i=1,x,y;i<=q;i++){
    cin>>x>>y;
    ans=1e18;
    vector<pair<int,int>>&sx=S[x],&sy=S[y];
    for(int j=0;j<sx.size();j++){
      ll *dis=D[sx[j].first];
      mi=1e18;
      for(int k=0;k<sy.size();k++){
        mi=min(mi,dis[sy[k].first]+sy[k].second);
      }
      ans=min(ans,mi+sx[j].second);
    }
    cout<<ans+w[x]+w[y]<<'\n';
  }
	return 0;
}