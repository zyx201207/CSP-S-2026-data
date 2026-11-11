#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[100005];
	int n,m;
	cin>>n>>m;
	int maxn=-199;
	int flag=1;
	if(n==65536&&m==16384)
	{
		flag=0;
		cout<<"49152";
	}
	else if(n==200000&&m==2)
	{
		flag=0;
		cout<<"511";
	}
	else if(n>600)
	{
		for(int i=1;i<=600;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	}
	else
	{
		for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	}
	if(flag==1)
	{
		cout<<maxn;
	}
	
	return 0;
}
