#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
long long x,y,a[500001],m,ans1,ans=1,l;
long long max1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long x=m;
	if(a[3]-a[2]==a[2]-a[1]) 
	{
		for(long long i=1;i<=n;i++)
		{
			if((x-i*(a[2]-a[1]))>=0)
			{
				ans++;
				x-=i*(a[2]-a[1]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<i;j++)
		{
			ans1=0;
			l=a[i]*j;
			for(long long k=i-j;k<i;k++)
			{
				ans1+=a[k];
			}
			if((l-ans1)<=m)
			{
				ans=j+1;
				max1=max(max1,ans);
			}
		}
	}
	cout<<max1;
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
