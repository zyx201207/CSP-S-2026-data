#include<bits/stdc++.h>

using namespace std;

long long fg(long long ans,long long a[],long long n,long long m)
{
	long long max_cnt=0;
	for(int i=ans-1;i>=1;i--)
	{
		long long t=a[ans]-a[i];
		if(m>=t)
		{
			m-=t;
			a[i]=a[ans];
			max_cnt++;
		}
	}
	return max_cnt+1;
}
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long max_cnt=-1;
	for(int i=2;i<=n;i++)
		max_cnt=max(max_cnt,fg(i,a,n,m));
	printf("%lld\n",max_cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
