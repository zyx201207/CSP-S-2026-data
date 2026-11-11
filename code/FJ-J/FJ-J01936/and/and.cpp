#include<bits/stdc++.h>
using namespace std;
int n,m;
int log2j(int y)
{
	int op=1;
	for(int i=1;i<=y;i++)
	{
		op*=2;
	}
	return op;
}
int awy(int x,int y)
{
	int op=0;
	int g=0;
	int d=x;
	int f=y;
	while(d>0&&f>0)
	{
		if(d%2==f%2)
		{
			op+=d%2*log2j(g);
		}
		g++;
		d/=2;
		f/=2;
	}
	return op;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+1],man=0,f[m+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		man=max(man,a[i]);
	}
	f[1]=man;
	bool u[n+1];
	for(int i=0;i<n;i++)
	{
		u[i]=true;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==man)
		{
			u[i]=false;;
			break;
		}
	}
	for(int i=2;i<=m;i++)
	{
		f[i]=0;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(u[j]==true)
				f[i]=max(f[i],awy(f[i-1],a[j]));
		}
		for(int j=0;j<n;j++)
		{
			if(awy(f[i-1],a[j])==f[i])
			{
				u[j]=false;
			}
		}
	}
	cout<<f[m];
	
	return 0;
}

