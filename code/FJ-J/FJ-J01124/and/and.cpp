#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,m=1,f=0,s=0,l,y=0;
	bool o;
	cin>>a>>b;
	long long n[a],c[b],k[b];
	for(long long i=0;i<a;i++)
	{
		cin>>n[i];
	}
	sort(n+0,n+a);
	for(long long i=0;i<a;i++)
	{
		while(m)
		{
			if(y==0)
			{
				if((n[i]+1)%2==1)
			{
				break;
			}
			}
			else
			{
				if(m%2==1)
				{
					break;
				}
			}
			if(y==0)
			m=(n[i]+1)/2;
			else
			m=m/2;
			y++;
		}
		
		if(m==0)
		{
			f++;
		c[s]=n[i];
		k[s]=i;
		s++;
		}
		m=1;
		if(f==b)
		{
			long long p=c[0];
			for(long long j=1;j<s;j++)
			{
				p=p and c[j];
			}
			cout<<p;
			return 0;
		}
	}
long long p=c[0];
			for(long long j=1;j<s;j++)
			{
				p=p and c[j];
			}
	m=0;
	for(int t=0;t<b;t++)
	{
		for(long long i=1;i<a;i++)
	{
		for(long long j=0;j<s;j++)
		{
			if(i==k[j])
			{
				o=0;
			}
		}
		if(o)
		{
			if(m<n[i] and p)
			{
				m=n[i] and p;
				l=i;
				y=1;
		}
			
		}
	}
	if(y==1)
	{
		f++;
	c[s]=n[l];
	k[s]=l;
	s++;
	if(f==b)
	{
				long long p=c[0];
			for(long long j=1;j<s;j++)
			{
				p=p and c[j];
			}
			cout<<p;
			return 0;
	}
	}
	
	}
	return 0;
}
