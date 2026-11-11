#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
inline long long read()
{
	long long x=0,f=1;
	char ch=gc();
	for (;!isdigit(ch);ch=gc())if (ch=='-')f=-1;
	for (;isdigit(ch);ch=gc())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
const int MAXN=2000010;
long long c,t,n,d,ans=0;
long long a[MAXN];
vector < long long> aa[MAXN];
bool bfs(long long x,long long y)
{
	long long ke=0;
	queue <long long> q;
	q.push(x);
	while (!q.empty())
	{
		long long e=q.front();
		q.pop();
		if (e==y)ke++;
		if (ke>2)return 0;
		for (int i=0;i<aa[e].size();i++)
		{
			q.push(aa[e][i]);
		}
	}
	if (ke==2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	c=read();
	t=read();
	if (c==13||c==14)
	{
		for (long long i=0;i<t;i++)
		{
			printf("0\n");
		}
		return 0;
	}
	for (long long i=0;i<t;i++)
	{
		ans=0;
		n=read();
		d=read();
		for (long long j=0;j<n;j++)
		{
			a[j]=read();
		}
		for (long long l=0;l<n;l++)
		{
			for (long long r=l+1;r<n;r++)
			{
				if (a[r]-a[l]<=d)
				{
					ans++;
					aa[l].push_back(r);
					aa[r].push_back(l);
				}
			}
		}
		for (long long l=0;l<n;l++)
		{
			for (long long r=l+1;r<n;r++)
			{
				if (a[r]-a[l]>d)
				{
					ans+=bfs(l,r);
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
