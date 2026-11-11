#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long as;
void dfs(long long q,long long s,long long wz)
{
	if(q>m)
	{
		as = max(as,s);
		return ;
	}
	for(long long i = wz+1;i<=n;++i)
	{
		dfs(q+1,s&a[i],i);
	}
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;++i)
	{
		dfs(2,a[i],i);
	}
	cout << as;
	return 0;
}
