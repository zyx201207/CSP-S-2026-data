#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
char b[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(m==2&&n<=20000)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i!=j)
				{
					sum=max(sum,a[i]&a[j]);
				}
			}
		}
		cout<<sum;
		return 0;
	}
	long long andd=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		andd=andd&a[i];
	}
	cout<<andd;
	return 0;
} 
