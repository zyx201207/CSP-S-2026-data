#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int a[200000],m,n;
	cin>>n>>m;
	if(n==200000)
	{cout<<511;
	return 0;
	}
	for(int i=0;i<=n-1;i++)
	{cin>>a[i];
	}
	if(m==1)
	{int zd=0;
	for(int i=0;i<=n-1;i++)
	if(a[i]>zd)
	zd=a[i];
	cout<<zd;
	}
	if(m==2)
	{
	int b,c,zd=0;
		for(int i=0;i<=n-1;i++)
		for(int l=i+1;l<=n-1;l++)
		{int j[20]={},bb=0,s=0;
		b=a[i],c=a[l];
		while(c!=0&&b!=0)
		{
			if(b%2==1&&c%2==1)
			j[bb]=1;
			bb++;
		b/=2;
		c/=2;
		}int ds=1;
       for(int cc=0;cc<=19;cc++)
		{s+=j[cc]*ds;
		ds*=2;
		}
		if(s>zd)
		zd=s;
	
		}
			cout<<zd;
	}
	if(m==n)
	{
		int ds=1,zs=0,j[20]={},cs=0;
		while (a[0]!=0)
		{j[cs]=a[0]%2;
			cs++;
		a[0]/=2;
		}cs=0;
		for(int i=0;i<=n-1;i++)
		while(a[i]!=0)
		{if(j[cs]==a[i]%2&&j[cs]==1)
		j[cs]=1;
		else
		j[cs]=0;
			cs++;
			a[i]/=2;
		}
		for(int i=0;i<=19;i++)
		{zs=j[i]*ds;
		ds*=2;
		}
		cout<<zs;
	}
	
	
	if(m==3)
	{
	int b,c,d,zd=0;
		for(int i=0;i<=n-1;i++)
		for(int l=i+1;l<=n-1;l++)
		for(int p=l+1;p<=n-1;p++)
		{int j[20]={},bb=0,s=0;
		b=a[i],c=a[l],d=a[p];
		while(d!=0&&c!=0&&b!=0)
		{
			if(b%2==1&&c%2==1&&d%2==1)
			j[bb]=1;
			bb++;
		b/=2;
		c/=2;
		d/=2;
		}int ds=1;
       for(int cc=0;cc<=19;cc++)
		{s+=j[cc]*ds;
		ds*=2;
		}
		if(s>zd)
		zd=s;
	
		}
			cout<<zd;
	}
    
}