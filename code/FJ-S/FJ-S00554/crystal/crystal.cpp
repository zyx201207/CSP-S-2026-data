#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],ans,max3,max1,max2,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	if(n<=5000)
	{
		max2=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=b[j]-b[i-1];
				if(a[j]*(j-i+1)-ans<=m)
				{
					max1=j-i+1;
					if(max1>max2)
					{
						max2=max1;
					}
				}
			}
		} 
		cout<<max2;
	}
	else
	{
		max3=-1; 
		for(int i=1;i<=n;i++)
		{
			ans=a[i]*i;
			if((ans-b[i]-1)<=m)
			{
				if(i>max3)
				{
					max3=i;
				}
			}
		}
		cout<<max3;
	}
	return 0;
} 
