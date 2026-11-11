#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen(and.in,"r",studin);
	freopen(and.out,"w",studout);
	
	int n,m,a[1000],maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i])
			{
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	int x;
	for(int i=1;i<=m;i++)
	{
		if(i==m)
		{
			a[m]=a[i-1]&a[m];
			break;
		}
		a[i+1]=a[i]&a[i+1];
	}
	cout<<a[m];
	return 0;
}
