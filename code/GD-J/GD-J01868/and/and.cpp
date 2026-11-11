#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool b[35][200005],c[200005],d[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxn=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(int t=0;t<=31;t++)
			b[t][i]=((a[i]>>t)&1);
		d[i]=1;
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		printf("%lld",maxn);
		return 0;
	}
	long long ans=0;
	for(int t=31;t>=0;t--)
	{
		for(int i=1;i<=n;i++)
			c[i]=d[i];
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			d[i]=d[i]&b[t][i];
			if(d[i])
				cnt++;
		}
		if(cnt<m)
			for(int i=1;i<=n;i++)
				d[i]=c[i];
		else
			ans+=(1<<t);
//		cout<<cnt<<'\n';
//		cout<<cnt<<' '<<ans<<'\n';
//		for(int i=1;i<=n;i++)
//			cout<<b[t][i]<<' ';
//		cout<<'\n';
	}
	printf("%lld",ans);
	return 0;
}
