#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5, _=505,inf=2e18;

int c,n,m,tmp,q,w[M],k[_],d[_][_];

vector<pair<int,int>> tt[M];

signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>tmp>>q;
  for(int i=1;i<=m;i++)
    cin>>w[i];
  for(int i=1;i<=n;i++)
  {
    cin>>k[i];
    for(int j=1;j<=k[i];j++)
    {
      int u,t;
      cin>>u>>t;
      tt[u].push_back(make_pair(i,t));
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)
        d[i][j]=0;
      else
        d[i][j]=inf;
    }
  }
  for(int i=1;i<=m;i++)
    for(auto j:tt[i])
      for(auto o:tt[i])
        d[j.first][o.first]=min(j.second+o.second,d[j.first][o.first]);
  for(int o=1;o<=n;o++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][o]+d[o][j]);
  int x,y,ans;
  for(int i=1;i<=q;i++)
  {
    cin>>x>>y;
    ans=inf;
    for(auto j:tt[x])
      for(auto o:tt[y])
        ans=min(ans,j.second+d[j.first][o.first]+o.second);
    ans+=w[x]+w[y];
    cout<<ans<<"\n";
  }
  return 0;
}
