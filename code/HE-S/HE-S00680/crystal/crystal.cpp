#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],cf[500001],ave,t=0,us=-1,noww=1;
bool xda=1,xdb=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	cin >> a[1] >> a[2];
	if(a[1]!=1||a[2]!=2)
	{
		xda=0;
	}
	for(int i=3;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=i)
		{
			xda=0;
		}
		if(a[i-1]-a[i-2]!=a[i]-a[i-1])
		{
			xdb=0;
		}
	}
	if(xda)
	{
		int i=1;
		while(m>=0)
		{
			t++;
			m-=i;
			i++;
		}
		cout << t;
		return 0;
	}
	if(xdb)
	{
		int i=a[2]-a[1];
		while(m>=0)
		{
			t++;
			m-=i; 
			i+=a[2]-a[1];
		}
		cout << t;
		return 0;
	}
	sort(a+1,a+n+1);
	cf[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		cf[i]=cf[i+1]+(a[n]-a[i]);
	}
	for(int i=n-1;i>=1;i--)
	{
		noww=1;
		if(cf[noww]-cf[i+1]-(i-noww+1)*cf[i]<=m)
		{
			us=max(us,i-noww+1);
		}
		else
		{
			while(cf[noww]-cf[i+1]-(i-noww+1)*cf[i]>m)
			{
				noww++;
			}
			us=max(us,i-noww+1);
		}
	}
	cout << us;
	return 0;
}

