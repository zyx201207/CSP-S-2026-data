#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,x=0,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				s=a[j];
				a[j]=a[j+1];
				a[j+1]=s;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			x+=(a[i]-a[j]);
		}
		if(m>=x)
		{
			cout<<i;
			return 0;
		}
		x=0;
	}
	cout<<0;
	return 0;
	
	fclose(stdin);
	fclose(stdout);
} 
