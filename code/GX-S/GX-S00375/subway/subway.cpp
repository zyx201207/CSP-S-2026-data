#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXX=10000+10,INF=0x3f3f3f3f;
long long c,n,m,d,q;
long long w[MAXX],z[MAXX][MAXX];
struct zhantai
{
	long long num,b[MAXX];
}zt[MAXX];
vector<long long>xl[MAXX];

struct node
{
	 long long s,now,x;
};
long long dis[MAXX],vis[MAXX];
void dijistra(long long a,long long b)
{
	node t;
	t.s=w[a];
	t.now=a;
	t.x=0;
	memset(dis+1,INF,sizeof(dis));
	dis[a]=w[a];
	queue<node>q;q.push(t);
	while( !q.empty() )
	{
		t=q.front();q.pop();
		long long s=t.s,now=t.now,x=t.x;
		//cout<<"s:"<<s<<"  now:"<<now<<"  x:"<<x<<endl; 
		if(s>dis[now])continue;
		if(x!=0)
		{
			int len=xl[x].size();
			for(int j=0;j<len;j++)
			{
				  long long to=xl[x][j];
				  if(to==now)continue;
				  if(dis[to]>s)
				  {
					  dis[to]=s;vis[to]=x;t.s=dis[to];
					   t.now=to;t.x=x;
				    q.push(t);
				  }
			}
		}
		for(int i=1;i<=zt[now].num;i++)
		{
			if(zt[now].b[i]==x )continue;
			int xlnow=zt[now].b[i];
		  int len=xl[xlnow].size();
		  for(int j=0;j<len;j++)
		  {  
			  long long to=xl[xlnow][j];//cout<<"to"<<to<<endl;
			  if(to==now)continue;
			  if(dis[to]> s+z[now][x]+z[now][xlnow])
			  {
				  dis[to]=s+z[now][x]+z[now][xlnow];t.s=dis[to];vis[to]=xlnow;
				  t.now=to;t.x=xlnow;
				  q.push(t);
			  }
		  }
	    }
	   }
	   cout<<dis[b]+w[b]+z[b][vis[b]]<<endl;
	return;
}
int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++)cin>>w[i];
  for(int i=1;i<=n;i++)
  {
	  long long k;cin>>k;//cout<<"k"<<k<<endl;
	  for(int j=1;j<=k;j++)
	  {
		  long long a,t;cin>>a>>t;//cout<<"a"<<a<<"t"<<t<<endl;
		  z[a][i]=t;
		  zt[a].b[++zt[a].num]=i;
		  xl[i].push_back(a);
	  }
  }
  for(int i=1;i<=q;i++)
  {
	  long long be,en;
	  cin>>be>>en;
	  dijistra(be,en);
  }
  return 0;
}
