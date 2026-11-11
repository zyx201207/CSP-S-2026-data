#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,m,a[1000000],s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			s=a[i]&a[j];
			if(s>=max) max=s;
		}
	}
	cout<<max<<endl;
	return 0;
}
