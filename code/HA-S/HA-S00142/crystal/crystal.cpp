#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("crystal.in","crystal",);
	/*getch()*/
	long long n,m,sum=0,g=0;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=0;i<n;i++)
	{
		cin>>a[i-1];
	}
	if(n%2==0)
	{
		sum=a[n/2-1];
	}
	else
	{
		n++;
		sum=a[n/2-1];
	}
	for(long long i=0;i<n;i++)
	{
		if(a[i]<=sum&&m>=sum-a[i])
		{
			g++;
			m=m-sum+a[i];
		}
	}
	cout<<g+1;
	return 0;
}
