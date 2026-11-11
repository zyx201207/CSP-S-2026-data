#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,sum;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	else if(m==n)for(int i=1;i<n;i++)ans=a[i]&a[i+1];
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(j==i-1||j==i)continue;
				if(j==1)sum=a[j]&a[j+1];
				else sum=sum&a[j]&a[j+1];
			}
			ans=max(ans,sum);
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			int s=0;
			for(int j=i+1;j<n;j++)s=max(s,a[i]&a[j]);
			ans=max(ans,s);
		}
	}
	else if(m<=n)for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	cout<<ans;
	return 0; 
}
