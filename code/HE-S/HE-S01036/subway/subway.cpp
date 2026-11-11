#include<iostream>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
const int N=510,M=5e5+10,D=22,Q=1e5+10,INF=1e18;
int c,n,m,d,q,w[M],k[N],f[N][N];
vector<int>a[N],t[N];
vector<pair<int,int>>belong[M];
int read()
{
  int res=0;
  char ch=getchar();
  while('0'<=ch&&ch<='9')
  {
    res=res*10+ch-'0';
    ch=getchar();
  }
  return res;
}
void Floyd()
{
  for(int i=1; i<=n; ++i)f[i][i]=0;
  for(int k=1; k<=n; ++k)for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
  return;
}
signed main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  c=read(),n=read(),m=read(),d=read(),q=read();
  for(int i=1; i<=m; ++i)w[i]=read();
  for(int i=1; i<=n; ++i)
  {
    k[i]=read();
    a[i].resize(k[i]+5);
    t[i].resize(k[i]+5);
    for(int j=1; j<=k[i]; ++j)
    {
      a[i][j]=read();
      t[i][j]=read();
      belong[a[i][j]].push_back({i,t[i][j]});
    }
  }
  memset(f,0x3f,sizeof f);
  for(int t=1; t<=M; ++t)if(belong[t].size()>1)
      for(int i=0; i<belong[t].size(); ++i)for(int j=0; j<i; ++j)
          f[belong[t][j].first][belong[t][j].first]=f[belong[t][j].first][belong[t][i].first]=
                min(f[belong[t][i].first][belong[t][j].first],belong[t][i].second+belong[t][j].second);
  Floyd();
  while(q--)
  {
    int x,y,ans=INF;
    cin>>x>>y;
    for(int i=0; i<belong[x].size(); ++i)for(int j=0; j<belong[y].size(); ++j)
        ans=min(ans,f[belong[x][i].first][belong[y][j].first]+belong[x][i].second+belong[y][j].second);
    ans+=w[x]+w[y];
    cout<<ans<<'\n';
  }
  return 0;
}
