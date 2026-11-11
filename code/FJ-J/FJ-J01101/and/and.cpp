#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	int p;
	long long n,m,da;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long b[m+1],bb[m+1];
	for(int i=1;i<=m+1;i++) bb[i]=-1;
	for(int i=1;i<=m;i++)
	{
		da=0;
		p=1;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=i-1;l++)
			{
				if(j==bb[l]) p=0;
			}
			if(a[j]>da && p==1)
			{
				da=a[j];
				bb[i]=j;
			}
			p=1;
		}
		b[i]=da;
	}
	da=b[1];
	for(int i=2;i<=m;i++)
	{
		da=da&b[i];
	}
	cout<<da;
	return 0;
}
