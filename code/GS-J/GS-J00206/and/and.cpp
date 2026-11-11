#include <bits/stdc++.h>

using namespace std;

int n,m;
long long a[2005],ma;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(m==1)
		cout<<ma<<endl;
	else if(m==2)
	{
		ma=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ma=max(ma,a[i]&a[j]);	
			}
		}
		cout<<ma<<endl;
	}
	else if(m==n)
	{
		for(int i=1;i<n;i++)
		{
			ma=a[i]&a[i-1];
			a[i]=ma;
		}
		cout<<ma<<endl;
	}
	return 0;
}
