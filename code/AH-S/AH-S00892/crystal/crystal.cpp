#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		if(i>=3)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			{
				f=0;
				break;
			}
		}
	}
	if(f)
	{
		int t=a[n]-a[n-1];
		for(int i=n-1;i>=1;i--)
		{
			if(i*t+i*i*t<=m*2)
			{
				ans+=i;
				break;
			}
		}
		cout<<ans;
	}
	else
	{
		long long ans1=1,l=1,num=1,m1=0;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i+1]-a[i]>m)
			{
				l=i+1;
				num=1;
				m1=0;
				ans1=1;
				continue;
			}
			m1=m1+(a[i+1]-a[i])*num;
			if(m1<=m)
			{
				ans1++;
				num++;
			}
			else
			{
				for(int j=l;j<=i;j++)
				{
					m1-=a[i+1]-a[j];
					l++;
					ans1--;
					if(m1<=m)
					{
						ans1++;
						break;
					}
				}
			}
			ans=max(ans,ans1);
			if(ans==n)
			{
				break;
			}
		}
		cout<<ans;
	}
	
	return 0;
}
