#include<bits/stdc++.h>
using namespace std;
long long a[500005],s,sum,summ,n,m;
struct xxx
{
	long long x;
	int y,z;
}b[500005];
bool cmp(xxx a,xxx b)
{
	return a.x<b.x;
}
int zz(int ii)
{
	int z=-1;
	for(int i=0;i<n-1;i++)
	{
		if(b[i].y==b[ii].z) return i;
	}
	return z;
}
int yy(int ii)
{
	int y=-1;
	for(int i=0;i<n-1;i++)
	{
		if(b[i].z==b[ii].y) return i;
	}
	return y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		b[i].x=a[i+1]-a[i];
		b[i].y=i+1;
		b[i].z=i;
	}
	sort(b,b+n-1,cmp);
	int aaa=0;
	for(int i=0;i<n-1;i++)
	{
		if(b[i].x!=0)
		{
			aaa=1;
		}
	}
	int ab=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=i+1)
		{
			ab=1;
		}
	}
	if(ab==0||aaa==0)
	{
		int as=1;
		for(int i=2;i<=n;i++)
		{
			if((1+i)*i/2>m)
			{
				cout<<i-1;
				as=0;
				break;
			}
		}
		if(as==1||aaa==0) cout<<n;
	}
	else
	{	
		for(int i=0;i<n-1;i++)
		{
			sum=1;
			if(zz(i)==-1)
			{
				int ii=i;
				while(1)
				{
					if(s+s+b[ii].x>m||yy(ii)==-1)
						break;
					s+=s+b[ii].x;
					ii=yy(ii);
					sum++;
				}				
			}
			else if(yy(i)==-1)
			{
				int ii=i;
				while(1)
				{
					if(s+s+b[ii].x>m||zz(ii)==-1)
						break;
					s+=s+b[ii].x;
					ii=zz(ii);
					sum++;
				}
			}
			else
			{
				int iz=zz(i),iy=yy(i),ii=i;
				while(1)
				{
					if(s+s+b[ii].x>m||iz==-1&&iy==-1)
						break;
					s+=s+b[ii].x;
					if(b[iz].x<b[iy].x)
					{
						ii=iz;
						iz=zz(ii);
					}
					else
					{
						ii=iy;
						iy=yy(ii);
					}
					sum++;
				}
			}
			summ=max(summ,sum);
		}
		cout<<summ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
