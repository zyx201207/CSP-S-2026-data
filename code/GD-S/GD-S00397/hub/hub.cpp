#include<iostream>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)? EOF:*p1++)
void read(long long &x)
{
	x=0;
	char c=gc();
	long long f=1;
	while(c>'9'||c<'0') f=(c=='-'? -f:f),c=gc();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
	x*=f;
}
long long c,t;
long long n,k,ans;
long long u[110],v[110];
long long h[110],da[210],ne[210],idx;
long long fa[110],siz[110];
long long dis[110];
bool sel[110];
void adde(long long u,long long v)
{
	da[++idx]=v;
	ne[idx]=h[u];
	h[u]=idx;
}
long long find(long long a)
{
	long long x=a;
	while(x!=fa[x]) x=fa[x];
	while(a!=fa[a])
	{
		long long u=a;
		a=fa[a];
		fa[u]=x;
	}
	return a;
}
void merge(long long f,long long s)
{
	f=find(f),s=find(s);
	if(f!=s) fa[s]=f,siz[f]+=siz[s];
}
void bfs()
{
	queue<long long> q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=(sel[i]? 0:inf);
		if(sel[i]) q.push(i);
	}
	while(q.size())
	{
		long long t=q.front();
		q.pop();
		for(int i=h[t];i!=-1;i=ne[i])
		{
			if(dis[da[i]]>dis[t]+1)
			{
				dis[da[i]]=dis[t]+1;
				q.push(da[i]);
			}
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c),read(t);
	while(t--)
	{
		ans=inf;
		idx=0;
		memset(h,-1,sizeof(h));
		read(n),read(k);
		for(int i=1;i<n;i++)
		{
			read(u[i]),read(v[i]);
			adde(u[i],v[i]);
			adde(v[i],u[i]);
		}
		for(int i=0;i<(1<<n);i++)
		{
			long long cnt=0;
			for(int j=1;j<=n;j++)
			{
				sel[j]=(i>>j-1)&1;
				cnt+=sel[j];
				fa[j]=j;
				siz[j]=1;
			}
			if(cnt>k) continue;
			for(int j=1;j<n;j++)
			{
				if(sel[u[j]]&&sel[v[j]]) merge(u[j],v[j]);
			}
			cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(sel[j]&&j==fa[j]) cnt++;
			}
			if(cnt>2) continue;
			bfs();
			long long mx=0;
			for(int j=1;j<=n;j++)
			{
				mx=max(mx,dis[j]);
			}
			ans=min(ans,mx);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
