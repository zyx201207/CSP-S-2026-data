//GZ-S00225  遵义市第十九中学  吴韩飞
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	sum+=m;
	int cnt=sum/m;
	int b=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>cnt)
		{
			b=i;
			break;
		}
	}
	if(a[b-2]+a[b-3]+m==a[b-1]*2)
	{
		cout<<b;
	}
	else
	{
		cout<<b-1;
	}
	return 0;	
} 
