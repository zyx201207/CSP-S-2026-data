#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[5000],m,max=-1;
	cin>>n>>m;
	if(m==n)
	{
		int awy,hawy;
		cin>>awy;
		for(int s=1;s<=n-1;s++)
		{
			cin>>hawy;
			awy=awy&hawy;
		}
		max=awy;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>max)
			{
				max=a[i];
			}
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int z=1;z<=n-1;z++)
		{
			for(int j=z+1;j<=n;j++)
			{
				int ds;
				ds=a[z]&a[j];
				if(ds>max)max=ds;
			}
		}
	}
	cout<<max;
	return 0;
}
