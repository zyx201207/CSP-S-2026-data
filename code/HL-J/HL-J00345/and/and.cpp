#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,x,sum=0;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	x=a[1];
	if(n==m) 
	{
		for(int i=2;i<=n;i++) x=(x&i);
		cout<<x;
		return 0;
	}
	if(m==1) 
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((i&j)>=sum) sum=(i&j);
			}
		}
	}
	cout<<sum;
} 
