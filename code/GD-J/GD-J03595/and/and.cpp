#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200009],sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			int b=a[i-1];
			a[i-1]=a[i];
			a[i]=b;
			i=0;
		}
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				sum=max(sum,a[i]&a[j]);
			}
		
		}
	}
	else if(m==n)
	{
		for(int i=0;i<n;i++)
		a[i]=a[i]&a[i-1];
		cout<<a[n-1];
	}
	else if(m==n-1)
	{
		for(int i=0;i<n-1;i++)
		a[i]=a[i]&a[i-1];
		int f1=a[n-2];
		for(int i=1;i<n;i++)
		a[i]=a[i]&a[i-1];
		int f2=a[n-1];
		cout<<max(f1,f2);
	}
	else
	cout<<a[m-1];
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
