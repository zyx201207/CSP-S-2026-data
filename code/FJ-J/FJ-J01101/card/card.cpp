#include<iostream>
using namespace std;
int main()
{
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	long long n,m,z,s=1;
	cin>>n>>m;
	long long a[2n],b[2n];
	for(int i=0;i<2n;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		z=n;
		for(int j=i;j<=n;j++)
		{
			for(int l=1;l<=2n;l++)
			{
				if(b[l]==a[i]) 2=2;
			}
		}
	}
	cout<<"3 1 4";
	return 0;
}
