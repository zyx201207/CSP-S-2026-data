#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
long long b[500005];
bool f1=0,f2=0;
int t;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			f1=1;
		}
		if(i>2)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			{
				f2=1;
			}
		}
	}
	if(f1==0)
	{
		a[1]=0;
		for(int i=1;;i++)
		{
			a[i+1]=a[i]+i;
			if(m==a[i+1])
			{
				cout<<i+1;
				return 0;
			}else if(m<a[i+1])
			{
				cout<<i;
				return 0;
			}
		}
		
	}
	/*if(f2==0)
	{
		t=abs(a[2]-a[1]);
		for(int i=1;;i++)
		{
			a[i]=0;
			a[i+1]=a[i]+i*t;
			if(m==a[i+1])
			{
				cout<<i+1;
				return 0;
			}else if(m<a[i+1])
			{
				cout<<i;
				return 0;
			}
		}
	}*/
	sort(a+1,a+n);
	t=a[1];
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i]-t+1;
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		if(m<b[i])
		{
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
