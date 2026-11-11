#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	
	int n,m,k;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i+1])
		{
			a[i]=a[i]+a[i+1];
			a[i+1]=a[i]-a[i+1];
			a[i]=a[i]-a[i+1];
		
		}	
	}
	for(int j=0;j<n;j++)
	{
		if(a[j]+a[j+1]>m)
		{
			k++;
		}
		cout<<k;
	}
	freopen("crystal.out","w",stdout);
	return 0;
}
