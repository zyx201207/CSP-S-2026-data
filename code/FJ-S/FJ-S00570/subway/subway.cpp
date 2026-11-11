#include<bits/stdc++.h>
#define endl '\n'
#define N 500006
#define M 506
using namespace std;
template <class T1,class T2> inline void chkmin(T1 &x,T2 y) {x=x<y?x:y;}
template <class T1,class T2> inline void chkmax(T1 &x,T2 y) {x=x<y?y:x;}
using i64=long long;
constexpr i64 INF=2e15;
int c,n,m,d,q,a[N];
i64 dis[M][M];
vector<pair<int,int> > vec[N];
main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
  for(int i=1;i<=m;i++)scanf("%d",&a[i]);
  for(int i=1,k,x,y;i<=n;i++)
  {
    scanf("%d",&k);
    while(k--)scanf("%d%d",&x,&y),vec[x].push_back({i,y});
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)dis[i][j]=(i==j?0:INF);
  for(int i=1;i<=m;i++)
    for(auto j:vec[i])
      for(auto k:vec[i])chkmin(dis[j.first][k.first],j.second+k.second);
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)chkmin(dis[i][j],dis[i][k]+dis[k][j]);
  while(q--)
  {
    int u,v; scanf("%d%d",&u,&v);
    i64 ans=INF;
    for(auto i:vec[u])
      for(auto j:vec[v])chkmin(ans,i.second+j.second+dis[i.first][j.first]);
    printf("%lld\n",ans+a[u]+a[v]);
  }
  return 0;
}
