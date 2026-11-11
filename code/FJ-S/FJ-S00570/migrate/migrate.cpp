#include<bits/stdc++.h>
#define endl '\n'
#define N 2000006
using namespace std;
using i64=long long;
int n,m,nxt[N],pre[N];
i64 ans,d,a[N],b[N],f[N],g[N];
vector<int> vec_pre[N],vec_nxt[N];
inline i64 read()
{
  i64 ret=0; int f=0; char ch=getchar();
  for(;(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
  if(ch=='-')f=1,ch=getchar();
  for(;ch>='0'&&ch<='9';ch=getchar())ret=(ch^48)+(ret<<3)+(ret<<1);
  return f?-ret:ret;
}
inline void solve(int lb,int rb)
{
  if(lb==rb)return;
  m=rb-lb+1;
  for(int i=1;i<=m;i++)b[i]=a[lb+i-1];
  for(int i=0;i<=m+1;i++)
  {
    f[i]=g[i]=pre[i]=nxt[i]=0;
    vec_pre[i].clear(),vec_nxt[i].clear();
  }
  for(int i=2,j=1;i<=m;pre[i++]=j)
    for(;j<i-1&&b[j]<b[i]-d;j++);
  for(int i=m-1,j=m;i;nxt[i--]=j)
    for(;j>i+1&&b[j]>b[i]+d;j--);
  for(int i=1;i<=m;i++)
    vec_nxt[nxt[i]].push_back(i),vec_pre[pre[i]].push_back(i);
  for(int i=1;i<=m;i++)
  {
    if(nxt[pre[i]]==i)f[i]+=f[pre[i]];
    for(int j:vec_nxt[i])if(j<i&&j>pre[i])f[i]++;
    f[i]++;
  }
  for(int i=m;i;i--)
  {
    if(pre[nxt[i]]==i)g[i]+=g[nxt[i]];
    for(int j:vec_pre[i])if(j>i&&j<nxt[i])g[i]++;
    g[i]++;
  }
  for(int i=1;i<=m;i++)if(nxt[i]>i+1)
  {
    int x=nxt[i],y=nxt[i]-1,z=nxt[x],add=(pre[y]==i?f[i]:1);
    if(x&&y&&z&&pre[z]==y)ans+=1ll*add*g[z];
    auto it_r=lower_bound(vec_pre[y].begin(),vec_pre[y].end(),z);
    auto it_l=upper_bound(vec_pre[y].begin(),vec_pre[y].end(),x);
    if(it_l<it_r)ans+=(i64)(it_r-it_l)*add;
  }
}
void solve()
{
  scanf("%d%lld",&n,&d),ans=0;
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1,lst=1;i<=n;i++)
    if(a[i+1]-a[i]>d||i==n)solve(lst,i),lst=i+1;
  printf("%lld\n",ans);
}
main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  int T; scanf("%*d%d",&T);
  while(T--)solve();
  return 0;
}
