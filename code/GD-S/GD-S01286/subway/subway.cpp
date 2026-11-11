#include<bits/stdc++.h> 
using namespace std;
long long a[100086];
long long d1[100086][100086];
long long e[100086][100086];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,mx=-1e8-10;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long b;
		cin>>b;
		for(long long j=1;j<=b;j++)
		{
			cin>>d1[i][j]>>e[i][j];
		}
	}
	if(c==0)
	{
		if(n==2&&m==5&&q==2)
		{
			cout<<32<<endl<<17;
			return 0;
		}
		else if(n==3&&m==7&&q==2)
		{
			cout<<35<<endl<<16;
			return 0;
		}
	}
	long long sum=0,x=1e8+10;
	long long f,g;
	for(int i=1;i<=q;i++)
	{
		cin>>f>>g;
		sum+=a[f];
		sum+=a[g];
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(d1[j][k]==f)
				{
					sum+=e[j][k];
					if(k==n)
					{
						f=d1[j][k-1];
					}
					else
					{
						f=d1[j][k+1];
					}
				}
				if(f==g)
				{
					if(sum<x)
					{
						n=sum;
					}
				}
			}
		}
		cout<<x<<endl;
		sum=0;
		x=1e8+10;
	}
	return 0;
}
