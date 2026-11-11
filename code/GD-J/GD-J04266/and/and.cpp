#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ans)
			{
				ans=a[i];
			}
		}
		cout<<ans;
	}
	else if(m==2)
	{
		int ans1=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>ans1)
				{
					ans1=a[i]&a[j];
				}
			}
		}
		cout<<ans1;
	}
	else
	{
		int sum=a[n-m];
	  for(int i=n-m;i<=n;i++)
	  {
	  	sum&=a[i];
	   } 
	   cout<<sum;
	}
	return 0;
}
