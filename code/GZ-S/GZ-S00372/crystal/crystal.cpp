//GZ-S00372 六盘水市第二十四中学 王轩宇
#include<bits/stdc++.h>
using namespace std;
long long c[500005];
long long pp(long long s)
{
	if(s<0)
	{
		s=s-s-s;
	}
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,t,s=0,z=0;
	cin>>a>>b;
	c[0]=0;
	for(long long i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	for(long long i=1;i<=a;i++)
	{
		for(long long j=i;j<=a;j++)
	    {
	    	if(c[j]>c[j+1])
	    	{
	    		t=c[j+1];
	    		c[j+1]=c[j];
	    		c[j]=t;
			}
	    }
	}
	for(long long i=2;i<=a;i++)
	{
		for(long long j=1;j<i;j++)
		{
			s+=pp(c[i]-c[j]);
		}
		for(long long l=i+1;l<=a;l++)
		{
			if(c[l]==c[i])
			{
				z++; 
			}
			else
			{
				break;
			}
		}
		if(s>b)
		{
			
			cout<<i-1+z;
			return 0;
		}
		else if(s==b)
		{
			cout<<i+z;
			return 0;
		}
		s=0;
	}
	cout<<a;
	return 0;
}
