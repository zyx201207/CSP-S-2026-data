#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		long long x = -1;
		for(int i = 0;i<n;i++)
		{
			if(a[i]>x)
			{
				x = a[i];
			}
		}
		cout<<x;
		return 0;
	}
	if(m==2)
	{
		long long x = -1;
		for(int i = 0;i<n;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				if(a[i]&a[j]>x)
				{
					x = a[i]&a[j];
				}
			}
		}
		cout<<x;
		return 0;
	}
	if(m==n)
	{
		long long x = a[0];
		for(int i= 1;i<n;i++)
		{
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	sort(a,a+n,greater<int>() );
	long long ans = a[0];
	for(int i = 1;i<m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
 } 
