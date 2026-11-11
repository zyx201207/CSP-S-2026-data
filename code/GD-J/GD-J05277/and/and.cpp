#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
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
	sort(a+1,a+n+1);
	long long ans=a[n];
	m--;
	while(m>0)
	{
		if(n==m)
		{
			for(int i=1;i<=n;i++)
			{
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
		if(ans==0)
		{
			cout<<0;
			return 0;
		}
		if(ans==a[n-1])
		{
			n--;
			m--;
		}
		else if(ans&a[n-1]==0)
		{
			n--;
		}
		else
		{
			ans=ans&a[n-1];
			n--;
			m--;
		}
	}
	cout<<ans;
	return 0;
} 
