#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[20],h,hh=-1,zd=INT_MIN,p;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]>4) p=1;
	}
	if(n<=20)
	{
		for(int i=0;i<=19;i++) f[i]=pow(2,i);
		for(int i=0;i<=1048575;i++)
		{
			int ii=i;
			h=0;
			hh=-1;
			for(int j=n-1;j>=0;j--)
			{
				if(ii>=f[j])
				{
					ii-=f[j];
					h++;
					if(hh==-1) hh=a[j+1];
					else hh=(hh&a[j+1]);
				}
			}
			if(h==m) zd=max(zd,hh);
		}
		cout<<zd;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++) zd=max(zd,a[i]);
			cout<<zd;
		}
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++) zd=max(zd,(a[i]&a[j]));
			}
			cout<<zd;
		}
		if(m==n)
		{
			int h;
			h=a[1];
			for(int i=2;i<=n;i++) h=(h&a[i]);
			cout<<h;
		}
	}
	else
	{
		if(p==0)
		{
			cout<<0;
			return 0;
		}
		sort(a+1,a+1+n);
		int zx=INT_MAX;
		for(int i=n;i>=n-m+1;i--) zx=min(zx,a[i]);
		cout<<zx;
	}
	return 0;
}
