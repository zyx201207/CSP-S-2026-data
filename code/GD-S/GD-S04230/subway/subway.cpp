#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define int long long 
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
int readint()
{
	int k=0,f=1,c=gc();
	for(;!isdigit(c);c=gc())
		if(c=='-') f=-1;
	for(;isdigit(c);c=gc())
		k=(k<<3)+(k<<1)+(c^48);
	return k*f;
}
const int N=5e5+10,M=2e3+10;
int task,qwq,n,m,d;
int a[N],rou[N];
struct node{
	int to,be,wi;
};
vector<node> e[N];
int ti[M][M]; //从i到j线路站台的时间 
bool v[N];
int dis[N];
struct qaq{
	int be,pi;
};
int spfa(int st,int en)
{
	queue<qaq> q;
	memset(v,0,sizeof(v));
	memset(dis,0x3f,sizeof(dis)); 
	dis[st]=0;
	q.push({0,st});
	while(!q.empty())
	{
		qaq p=q.front();
		q.pop();
		for(node t:e[p.pi])
		{
//			printf("q");
			int wi=t.wi;
			if(p.be!=t.be) //p.be转到t.be 
				wi+=ti[t.be][p.pi];
//			printf("%lld ",wi);
			if(dis[p.pi]+wi<=dis[t.to])
			{
				dis[t.to]=dis[p.pi]+wi;
				q.push({t.be,t.to});
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%lld ",dis[i]);
//	printf("\n");
	return a[st]+a[en]+dis[en];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	qwq=readint(),m=readint(),n=readint(),d=readint(),task=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint(); //站台->地铁口
	for(int i=1;i<=m;i++)
	{
		int k=readint();
		k<<=1;
		for(int j=1;j<=k;j++)
		{
			if(j&1) //站 
				rou[++rou[0]]=readint();
			else
				ti[i][rou[rou[0]]]=readint();
		}
		for(int j=1;j<=rou[0];j++)
		{
			for(int t=1;t<=rou[0];t++)
			{
				if(j==t) continue;
				e[rou[j]].push_back({rou[t],i,ti[i][rou[t]]});
			}
		}
		rou[0]=0;
	} 
//	for(int i=1;i<=n;i++)
//	{
//		printf("i:%lld\n",i);
//		for(node t:e[i])
//			printf("%lld %lld %lld\n",t.to,t.be,t.wi);
//		printf("\n");
//	}
	while(task--)
	{
		int st=readint(),en=readint();
		printf("%lld\n",spfa(st,en));
	}
}
