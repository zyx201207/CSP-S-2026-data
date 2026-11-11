#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ans,b[200010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	if(m==2)
	{
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	if(m==3)
	{
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					maxx=max(maxx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<maxx;
	}
	return 0;
} 

