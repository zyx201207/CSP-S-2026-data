#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+3;
int c,n,m,d,q;
ll tim[M][503];
int a;
ll dis[503][503];
vector<int> stop[M];
ll t[M];
int main()
{ 
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  while(cin>>c)
  {
   memset(t,0,sizeof t);
   memset(dis,0x3f3f3f,sizeof dis);
   scanf("%d%d%d%d",&n,&m,&d,&q);
   for(int i=1;i<=m;i++) scanf("%lld",t+i);
   for(int i=1;i<=n;i++)
   {
	int k=0;
	scanf("%d",&k);
	for(int j=1;j<=k;j++) 
	{
	  ll tmp;
	  scanf("%d %lld",&a,&tmp);
	  stop[a].push_back(i);
	  tim[a][i]=tmp;
	}
   }
   
    for(int i=1;i<=m;i++)
    {
	  for(long unsigned int j=0;j<stop[i].size();j++)
	   for(long unsigned int p=j+1;p<stop[i].size();p++)
	   {
	   dis[stop[i][j]][stop[i][p]]=dis[stop[i][p]][stop[i][j]]=min(tim[i][stop[i][j]]+tim[i][stop[i][p]],dis[stop[i][j]][stop[i][p]]);
       }
	}
	
   for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int p=1;p<=n;p++)
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
   
     while(q--)
     {
	   int x,y;
	   long long ans=LONG_LONG_MAX;
	  scanf("%d%d",&x,&y);
	  for(long unsigned int i=0;i<stop[x].size();i++)
	   for(long unsigned int j=0;j<stop[y].size();j++)
	  ans=min(ans,dis[stop[x][i]][stop[y][j]]+tim[x][stop[x][i]]+tim[y][stop[y][j]]);
      printf("%lld\n",ans+t[x]+t[y]);
	 }
  }
  return 0;
}
