#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],book[200005],sum[200005],idx=1;
long long ans = LLONG_MIN;
void dfs(int x,int t)
{
	if(x == t+1)
	{
		long long f = sum[1];
		for(int i=2;i<idx;i++)
		{
			f = f&sum[i];
		}
		ans = max(ans,f);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i] == 0)
		{
			book[i] = 1;
			sum[idx] = a[i];
			idx++;
			dfs(x+1,t);
			book[i] = 0;
			sum[idx] = 0;
			idx--;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m == 1)
	{
		long long ans = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans = max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		long long f =a[1]; 
		for(int i=2;i<=n;i++)
		{
			f = f&a[i];
		}
		cout<<f;
		return 0;
	}	
	dfs(1,m);
	cout<<ans;
	return 0;
}
