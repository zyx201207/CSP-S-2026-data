#include<bits/stdc++.h>
using namespace std; 
int main()
{
	long long  n,m,maxn=0,a[10000005],s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    if(n==1)
	{
		cout<<a[1];
	}
	else
	{
		for(int i=1;1<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cout<<a[j];
			}
		}
	}
	return 0;
}