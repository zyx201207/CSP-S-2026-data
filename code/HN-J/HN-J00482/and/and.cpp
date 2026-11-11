#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long num=0;
	int n,m;
	cin>>n>>m;
	long long a[n]={};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];		
	}
	sort(a,a+n,greater<int>());
	if(m!=n)
	{
		for(int j=1;j<m;j++)
		{
			for(int i=0;i<n-1;i++)
			{
				a[i]=a[i]&a[i+1];
			}
			n--;
		}	
	}
	else
	{
		num=a[0]&a[1];
		for(int i=2;i<n;i++)
		{
			num=num&a[i];
		}
		cout<<num;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		num=max(num,a[i]);
	}
	cout<<num;
	/*
	int dp[m];
	dp[0]=
	for(int i=0;i<n;i++)
	{
		
	}
	*/return 0;
}

