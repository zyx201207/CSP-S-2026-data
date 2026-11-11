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
const int N=5e4+10;
int n,task,d,ans=0;
vector<int> e[N];
int a[N];
bool v[N];
int f[N],dis[N];
void bfs(int st)
{
	queue<int> q;
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	memset(dis,0x3f,sizeof(dis));
	q.push(st);
	v[st]=1;
	dis[st]=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		v[p]=0;
		for(int t:e[p])
		{
			if(dis[p]+1<dis[t])
			{
				dis[t]=dis[p]+1;
				f[t]=1;
				if(v[t]==0)
				{
					q.push(t);
					v[t]=1;
				}
			}
			else if(dis[p]+1==dis[t])
				f[t]++;
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int qwq=readint(),task=readint();
	while(task--)
	{
		ans=0;
		n=readint(),d=readint();
		for(int i=1;i<=n;i++)
			a[i]=readint();
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			for(int j=i+1;j<=n;j++)
			{
				int t=a[j]-a[i];
				if(t<=d)
					e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=1;j<=n;j++)
				if(f[j]==2)
					ans++;
//				printf("%lld ",dis[j]);
//			printf("\n"); 
		}
		printf("%lld\n",ans);
	}
}
