#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	int a[n],sum[100000000];
	for(int i;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i;i<n;i++)
	{
		for(int j;j<m;j++)
	{
		sum[i]=a[j]&a[j+1]&a[j+2];
	}
	}
	for(int i;i<n;i++)
	{
		if(sum[i]>sum[i+1])
		{
			t=sum[i];
			sum[i]=sum[i+1];
			sum[i+1]=t;
		}
	}
	for(int i;i<n;i++)
	{
		cout<<sum[i];
	}
}
