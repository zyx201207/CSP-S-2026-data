#include<bits/stdc++.h>
using namespace std;
bool sum[505][205];
int main()
{
	
	int n,m,a[505];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int k;
	for(int i=1;i<=n;i++)
	{
		int s[505];
		k=1;
		for(int j=i;j<=n;j++)
		{
			if(!sum[a[j]][i])
			{
				sum[j][i]=1;
				s[k++]=a[i];
			}
			else
			{
				while(s[k]!=a[i])
				{
					sum[s[k]][i]=0;
					k--;
				}
			}
		}
	}
	int num;
	for(int i=1;i<=m;i++)
	{
		num=0;
		for(int j=1;j<=n;j++)
		{
			if(sum[j][i])
			{
				num++;
			}
		}
		cout <<num;
		if(i<n)
		{
			cout<<" ";
		}
	}
	return 0;
}
