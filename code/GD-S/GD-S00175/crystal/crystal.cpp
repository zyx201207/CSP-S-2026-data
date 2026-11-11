#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],i,j,f[500009],s[500009],ans,sum,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(i=2;i<=n;i++)
	f[i]=a[i]-a[i-1];
	for(i=1;i<=n;i++)
	s[i]=s[i-1]+f[i];
	for(i=2;i<=n;i++)
	{
		sum=m;cnt=0;
		for(int j=i-1;j>=1;j--)
		{
			//cout<<s[i]-s[j]<<"\n";
			if(s[i]-s[j]<=sum)
			{
				sum-=(s[i]-s[j]);
				cnt++;	
			}
			else break;
		} 
		ans=max(ans,cnt+1);
	}
	printf("%lld",ans);
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
