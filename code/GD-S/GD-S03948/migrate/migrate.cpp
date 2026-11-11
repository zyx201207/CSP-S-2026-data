#include<iostream>
using namespace std;
long long c,t,x[2000005];
struct fly{
	long long ci;
	long long fa;
};
fly z[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		long long n,d,bird=0;
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>x[j];
			z[j].ci=99999;
			z[j].fa=99999;
		}
		z[0].ci=0;
		z[0].fa=1;
		for(int j=0;j<n;j++)
		{
			long long yb=j+1;
			while(x[yb]-x[j]<=d)
			{
				if(z[j].ci+1<z[yb].ci)
				{
					z[yb].fa=z[j].fa;
				}
				if(z[j].ci+1==z[yb].ci)
				{
					z[yb].fa+=z[j].fa;
				}
				z[yb].ci=min(z[j].ci+1,z[yb].ci);
				yb++;
			}
		}
		long long all1=0;
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(z[k].fa-z[j].fa==2)all1++;
			}
		}
		cout<<all1;
	}
	return 0;
} 
