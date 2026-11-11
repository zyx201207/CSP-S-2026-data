#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005],c[10000005],d[10000005],e[1000005];
void x()
{
	long long s=1;
	b[1]+=1;
	while(b[s]!=1)
	{
		b[s+1]+=1;
		b[s]=b[s]-2;
		s=s+1;
	}
}
long long lj(long long n,long long v)
{
	if(v>n) return 0;
	return b[v]+lj(n,v+1); 
}
long long erci(long long w,long long r)
{
	if(r>w) return 1;
	return 2*erci(w,r+1);
}
long long erjinzhi(long long w,long long j)
{
	if(w>j) return 0;
	return erci(w,2)*d[w]+erjinzhi(w+1,j);
}
long long awy(long long n,long long m)
{
	long long bl=1,zz=0,y=1;
	while(zz!=m)
	{
		if(b[bl]==1)
		{
			c[zz+1]=a[bl];
			zz=zz+1;
		}
		bl=bl+1;
	}
	while(c[1]>0)
	{
		d[y]=c[1]%2;
		c[1]=c[1]/2;
		y=y+1;
	}
	long long k=1;
	for(long long i=2;i<=m;++i)
	{
		k=1;
		while(c[i]>0)
		{
			if(c[i]%2==1&&d[k]==1)
			{
				k=k+1;
				c[i]=c[i]/2;
			}
			else
			{
				d[k]=0;
				k=k+1;
				c[i]=c[i]/2;
			}
		}
		for(long long j=k;j<=y;++j)
		{
			d[j]=0;
		}
	}
	return erjinzhi(1,k);
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long m,n,max=-1;
cin>>n>>m;
for(long long i=1;i<=n;++i)
{
	cin>>a[i];
}
while(b[n+1]<1)
{
	x();
	if(b[n+1]>=1) break;
	if(lj(n,1)==m)
	{
		if(max<awy(n,m)) max=awy(n,m);
	}
}
cout<<max;
return 0;
}

