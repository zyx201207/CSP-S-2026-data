#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[200010],b[4];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>> n >> m;
	bool flag1=true,flag2=true;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]>=4)
		{
			flag1=false;
		}
		if(a[i]!=i-1 && i!=1)
		{
			flag2=false;
		}
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout << a[n] << endl;
	}
	else if(m==n)
	{
		long long ans=a[1];
		for(int i=2; i<=n; i++)
		{
			ans&=a[i];
		}
		cout << ans << endl;
	}
	else if(m==2)
	{
		long long ans=0;
		for(int i=1; i<n; i++)
		{
			ans=max(ans,a[i]&a[n]);
		}
		cout << ans << endl;
	}
	else if(m==n-1)
	{
		long long num=a[1],ans=0;
		for(int i=2; i<=n; i++)
		{
			num&=a[i];
		}
		for(int i=1; i<=n; i++)
		{
			ans=max(ans,num|a[i]);
		}
		cout << ans << endl;
	}
	else if(flag1)
	{
		for(int i=1; i<=n; i++)
		{
			b[a[i]]++;
		}
		if(m<=b[3])
		{
			cout << 3 << endl;
		}
		else if(m<=b[3]+b[2])
		{
			cout << 2 << endl;
		}
		else if(m<=b[3]+b[1])
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if(flag2)
	{
		int cnt=0,temp1=n;
		while(temp1>0)
		{
			temp1/=2;
			cnt++;
		}
		int num=1;
		for(int i=1; i<=cnt-n/m+1; i++)
		{
			a[n]-=num;
			num*=2;
		}
		cout << a[n];
	}
	else
	{
		cout << a[n] << endl;
	}
	return 0;
}
