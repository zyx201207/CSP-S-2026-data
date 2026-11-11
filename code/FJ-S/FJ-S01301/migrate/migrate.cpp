#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
const int N=2e6+5;
int a[N];
int n,d;
int dis[N],sum[N];
int R[N];
void solve1()
{
	scanf("%lld%lld",&n,&d);
	for (int i=0;i<=n;i++)
	{
		dis[i]=1e18;
		sum[i]=0;
		R[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int ans=0;
	for (int S=1;S<n;S++)
	{
		dis[S]=0;
		sum[S]=1;
		sum[S-1]=0;
		R[0]=S;
		int cnt=0;
		int j=S;
		for (int i=S+1;i<=n;i++)
		{
			while (a[j]<a[i]-d)
			{
				j++;
			}
			if (j==i) break;
			dis[i]=dis[j]+1;
			int now=sum[R[dis[j]]]-sum[j-1];
			if (now==2) cnt++;
			sum[i]=sum[i-1]+now;
			R[dis[i]]=i;
		}
		ans+=cnt;
	}
	printf("%lld\n",ans);
	return ;
}
void solve2()
{
	scanf("%lld%lld",&n,&d);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int D=a[2]-a[1];
//	cout<<D<<":"<<d<<":";
	if (d<2*D) puts("0");
	else
	{
		int k=d/D;
		printf("%lld\n",max(0ll,n-2*k+1));
	}
	return ;
}
void solve3()
{
	scanf("%lld%lld",&n,&d);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if (n<4)
	{
		puts("0");
		return ;
	}
	int p1=lower_bound(a+1,a+n+1,a[n]-d)-a;
	int p2=upper_bound(a+1,a+n+1,a[1]+d)-a-1;
	if (p2-p1>2&&n>=4)
	{
		puts("0");
		return ;
	}
	int ans=0;
	for (int i=1;a[i]+d<a[n];i++)
	{
		int pos=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		int q1=upper_bound(a+1,a+n+1,a[pos-1]+d)-a-1;
		int q2=upper_bound(a+1,a+n+1,a[pos-2]+d)-a-1;
		ans+=q1-q2;
	}
	printf("%lld\n",ans);
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while (T--)
	{
		if (c==13||c==14)
		{
			solve3();
			continue;
		}
		if (c==11||c==12)
		{
			solve2();
		}
		else
		{
			solve1();
		}
	}
	return 0;
}
