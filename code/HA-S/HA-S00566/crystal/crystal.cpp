#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long l[500005];
int zuida(int x)
{
	memset(l,0,sizeof(l));
	for(int i = 1;i<=n;i++)
	{
		l[i] = max(a[i]-x,x-a[i]);
	}
	sort(l+1,l+n+1);
	int cnt = 1;
	for(int i =2;i<=n;i++)
	{
		if(m<0) break;
		if(x-a[i]>=0)
		{
			m-=l[i];
			cnt++;			
		}

	}
	return cnt;
}
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flag =1;
	cin>>n>>m;
	int x;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
		{
			x = a[i]-a[i-1];
		}
		if(i>2 && flag)
		{
			if(x!=a[i]-a[i-1]) flag = 0;
		}
	}
	int ans = 0;
	if(flag)
	{
		int x = a[2]-a[1];
		if(x<0)x = 0-x;
		if(x == 0) {
			cout<<n;
			return 0;	
		}
		int cnt = 1;
		for(int i = 1;i<=n;i++)
		{
			m-=x*i;
			if(m<=0) break;
			cnt++;
		}
		cout<<cnt;
	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
		int x = zuida(a[i]);
		if(ans<x)
		{
			ans = x;
		}
		}
	cout<<ans;	
	}
	
	
}
