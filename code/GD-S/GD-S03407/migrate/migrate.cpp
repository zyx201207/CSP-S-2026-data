//Author: mairuisheng
//#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=2e6+5;
int C;
int n,m;
int a[N];
vector<int> g[N];
int dis[N],cnt[N];
void SubA()
{
	int t=m/(a[2]-a[1]);
	if(t==0||t==1)
	{
		puts("0");
		return;
	}
	int p=t+t-1;
	printf("%lld\n",max(0ll,n-p));
}
void Sub1()
{
	int i,j,r=0,u,ans=0,z=0;
	for(i=1;i<=n;++i)
	{
		g[i].clear();
		r=max(r,i);
		while(r<=n&&a[r]-a[i]<=m)++r;
		if(C>=15&&C<=18)
		{
			for(j=r-1;j>=max(i+1,r-12);--j)g[i].push_back(j);
		}
		else
		{
			for(j=i+1;j<r;++j)g[i].push_back(j);
		}
	}
	queue<int> q;
	for(i=1;i<n;++i)
	{
		while(!q.empty())q.pop();
		q.push(i);
		dis[i]=0;
		cnt[i]=1;
		for(j=i+1;j<=n;++j)
		{
			dis[j]=N;
			cnt[j]=0;
		}
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			z=0;
			for(int v:g[u])
			{
				++z;
				if(C>=15&&C<=18&&z>10)break;
				if(dis[v]>dis[u]+1)
				{
					dis[v]=dis[u]+1;
					cnt[v]=cnt[u];
					q.push(v);
				}
				else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
			}
		}
		for(j=i+1;j<=n;++j)
		{
			if(cnt[j]==2)++ans;
		}
	}
	printf("%lld\n",ans);
}
void Solve()
{
	n=read();
	m=read();
	int i;
	for(i=1;i<=n;++i)a[i]=read();
	if(n==1)
	{
		puts("0");
		return;
	}
	if(C==11||C==12)SubA();
	else if(C==13||C==14)puts("0");
	else Sub1();
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();
	int T;
	T=read();
	while(T--)Solve();
	return 0;
}
