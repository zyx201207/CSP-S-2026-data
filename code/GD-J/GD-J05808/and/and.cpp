#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
long long mx;
long long dfs(long long c,long long x,long long d)
{
	if(d == m)
	{
		return a[x-1];
	}
	if(x == n && d < m)
	{
		return 0;
	}
	dfs(c,x+1,d);
	if(x!=1 && n-x >= m)
	{
		dfs(a[x],x+1,1);
	}
	mx = max(mx,c&dfs(c&a[x],x+1,d+1));
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long cnt = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		if(i == 0)
		{
			cnt = a[i];
		}
		else
		{
			cnt = cnt & a[i];
		}
	}
	if(m == n)
	{
		cout<<cnt;
		return 0;
	}
	dfs(a[0],1,1);
	cout<<mx;
	return 0;
}
