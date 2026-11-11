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
long long n,d;
long long x[2100000];
long long f[2100000][2];
long long dis[5100],ec[5100];
void bfs(long long s)
{
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<long long> q;
	q.push(s);
	dis[s]=0;
	ec[s]=1;
	while(q.size())
	{
		long long t=q.front();
		q.pop();
		for(int i=t+1;i<=n;i++)
		{
			if(x[i]-x[t]>d) break;
			if(dis[i]==dis[t]+1) ec[i]++;
			if(dis[i]>dis[t]+1)
			{
				dis[i]=dis[t]+1;
				ec[i]=ec[t];
				q.push(i);
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--)
	{
		read(n),read(d);
		for(int i=1;i<=n;i++)
		{
			read(x[i]);
		}
		if(n<=5000)
		{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				bfs(i);
				for(int j=i+1;j<=n;j++)
				{
					if(ec[j]==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
		else if(c==0||c==11||c==12)
		{
			long long k=x[2]-x[1];
			long long f=d/k;
			if(f<=1) printf("0\n");
			else printf("%lld\n",max(0ll,n-2*f+1));
		}
	}
	return 0;
}
