#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int f[500010];
int sum=0;
int cnt=0;
int maxx=0;
//int cmp(int xx,int yy)
//{
//	return xx>yy;
//}
main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[i]=f[i-1]+a[i];
	}
//	if(m==0)
//	{
//		cout<<1;
//		return 0;
//	}
	sort(a+1,a+1+n);
	int sum=0;
	cnt=1;
	for(int i=2;i<=n;i++)
	{
		cnt++;
		sum+=(a[i]-a[i-1])*(cnt-1);
		if(sum<=m)
		{
			maxx=max(cnt,maxx);
		}
		else
		{
			while(sum>m)
			{
				sum=sum-(a[i]-a[i-cnt+1]);
				cnt--;
			}
		}
		
	}
	cout<<maxx;
	
	
	return 0;
}
