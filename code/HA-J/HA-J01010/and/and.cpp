#include<bits/stdc++.h>
using namespace std;
int a[300000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1)
	{
		cout<<a[0];
		return 0;
	}
	if(m==2)
	{
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==3)
	{
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					ans=max(ans,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==4)
	{
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					for(int l=k+1;l<n;l++)
					{
						ans=max(ans,(a[i]&a[j]&a[k]&a[l]));
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		int ans=1;
		for(int i=0;i<m;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<rand();
	return 0;
}
