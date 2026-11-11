#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[510000],m,t=1,book[310000]={0},c[310000]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		t=1;
		for(int i=k;i<=n;i++)
		{
			int s=a[i];
			if(book[s]==0)
			{
				book[s]=t++;
			}
			else
			{
				t=book[s]+1;
				for(int j=1;j<=m;j++)
				{
					if(book[j]>book[s])book[j]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(book[j]!=0)c[j]++;
			book[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
