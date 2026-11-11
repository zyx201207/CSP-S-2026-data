#include <bits/stdc++.h>
using namespace std;
 int main()
 {
	long long n,m,a[210000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	m--;
	while(m--)
	{
		int book[210000]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(book[i]==0)a[i]=a[i]&a[j];
				else a[i]=max(a[i],a[i]&a[j]);
			}
		}
	}
	long long c=0;
	for(int i=0;i<n;i++)
	{
		c=max(c,a[i]);
	}
	cout<<c;
	return 0;
 }
