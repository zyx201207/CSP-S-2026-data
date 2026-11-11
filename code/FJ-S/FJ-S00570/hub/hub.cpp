#include<bits/stdc++.h>
#define endl '\n'
#define N 1000006
using namespace std;
int n,k,tag[N],d[1006][1006],ans;
struct Edge {int u,v;} E[N];
void brute(int now)
{
  if(now>n)
  {
    int v1=0,e1=0;
    for(int i=1;i<=n;i++)if(tag[i]==1)v1++;
    for(int i=1;i<n;i++)if(tag[E[i].u]==1&&tag[E[i].v]==1)e1++;
    if(v1-e1>1)return;
    int v2=0,e2=0;
    for(int i=1;i<=n;i++)if(tag[i]==2)v2++;
    for(int i=1;i<n;i++)if(tag[E[i].u]==2&&tag[E[i].v]==2)e2++;
    if(v2-e2>1)return;
    if(v1+v2!=k)return;
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
      int minn=2e9;
      for(int j=1;j<=n;j++)if(tag[j])minn=min(minn,d[i][j]);
      maxn=max(maxn,minn);
    }
    ans=min(ans,maxn);
    return;
  }
  for(int i=0;i<3;i++)tag[now]=i,brute(now+1);
}
void solve()
{
  scanf("%d%d",&n,&k),ans=2e9;
  memset(d,0x3f,sizeof(d));
  for(int i=1;i<=n;i++)d[i][i]=0;
  for(int i=1,u,v;i<n;i++)
  {
    scanf("%d%d",&E[i].u,&E[i].v);
    d[E[i].u][E[i].v]=min(d[E[i].u][E[i].v],1);
    d[E[i].v][E[i].u]=min(d[E[i].v][E[i].u],1);
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  brute(1),printf("%d\n",ans);
}
main()
{
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  int T; scanf("%*d%d",&T);
  while(T--)solve();
  return 0;
}
