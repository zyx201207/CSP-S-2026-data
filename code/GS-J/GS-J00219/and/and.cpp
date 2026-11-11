#include <bits/stdc++.h>
using namespace std;
int a[105],b[105],c[105];        
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	int n,m,minn=0,andd=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int l=1;
		cin>>a[i];
		while (a[i]>0)
		{
			b[i]=a[i]%2*l;
			l*=10;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int l=10;
			if ((b[i]%l==1)&&(b[i+1]%l==1))
			{
				c[i]+=1*(l/10);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (minn<c[i])
		{
			minn=c[i];
		}
	}
	int y=0;
	for (int i=0;i<n;i++)
	{
		int l=10,p=1;
		andd+=minn/p%l*(2^i);
		l*=10;
		p*=10;
	}
	cout<<andd;
	return 0;
}
