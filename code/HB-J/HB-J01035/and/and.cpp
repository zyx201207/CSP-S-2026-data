#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long maxn = INT_MIN;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		maxn = max(maxn,a[i]);
	}
	char flag = 'B';
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != i-1)
		{
			flag = 'A';
		}
	}
	if(m == 1)
	{
		cout<<maxn;
	}
	else if(m == n)
	{
		long long ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans &= a[i];
		}
		cout<<ans;
	}
	else if(m ==2)
	{
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m == n-1)
	{
		long long ans = a[2];
		for(int i = 3;i <= n;i++)
		{
			ans &= a[i];
		}
		for(int i = 2;i <= n;i++)
		{
			long long cnt = a[1];
			for(int j = 2;j <= i;j++)
			{
				cnt &= a[j];
			}
			for(int j = i+1;j <= n;j++)
			{
				cnt &= a[j];
			}
			ans = max(ans,cnt);
		}
		cout<<ans;
	}
	else if(flag == 'B')
	{
		cout<<0;
	}
	else if(flag == 'A')
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else
	{
		cout<<0;
	}
	return 0;
}
//RP++
