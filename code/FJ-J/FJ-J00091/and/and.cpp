#include<bits/stdc++.h>
using namespace std; 
int main()
{
	long long  n,m,maxn=0,a[10000005],s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
	}
	if(m==n)
	{
		s=a[1];
			for(int i=2;i<=n;i++)
	{
		s&=a[i];
	}
	cout<<s;
	}
	
	
	return 0;
}