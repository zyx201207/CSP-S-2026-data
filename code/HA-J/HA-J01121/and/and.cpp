#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0,sum.;
int a[200010];
int w[35],t[35],tt[35];
int f(int x,int y)
{
	int i=0,q=0;
	int j=0,z=0;
	for(int i=1;i<=35;i++)
	{
		w[i]=t[i]=0;
	}
	while(x!=0)
	{
		w[++i]=x%2;
		x/=2;
	}
	while(y!=0)
	{
		t[++j]=y%2;
		y/=2;
	}
	for(int p=max(i,j);p>=1;p--)
	{
		tt[++z]=w[p]&t[p];
	}
	for(int p=z;p>=1;p++)
	{
		int d=q,f=tt[p];
		while(d--)
		{
			f*=2;
		}
		sum+=f;
		q++;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ma) ma=a[i];
		}
		cout<<ma;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(f(a[i],a[j])>ma)
				{
					cout<<f(a[i],a[j]);
				}
			}
		}
	}
	return 0;
}
